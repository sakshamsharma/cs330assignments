// progtest.cc
//	Test routines for demonstrating that Nachos can load
//	a user program and execute it.
//
//	Also, routines for testing the Console hardware device.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "console.h"
#include "addrspace.h"
#include "synch.h"

extern void ForkStartFunction(int dummy);

//----------------------------------------------------------------------
// StartUserProcess
// 	Run a user program.  Open the executable, load it into
//	memory, and jump to it.
//----------------------------------------------------------------------

void StartUserProcess(char *filename) {
  OpenFile *executable = fileSystem->Open(filename);
  ProcessAddrSpace *space;

  if (executable == NULL) {
    printf("Unable to open file %s\n", filename);
    return;
  }
  space = new ProcessAddrSpace(executable);
  currentThread->space = space;

  delete executable; // close file

  space->InitUserCPURegisters(); // set the initial register values
  space->RestoreStateOnSwitch(); // load page table register

  machine->Run(); // jump to the user progam
  ASSERT(FALSE);  // machine->Run never returns;
                  // the address space exits
                  // by doing the syscall "exit"
}

void StartBatchOfProcesses(char files[][300], int *priorities, int batchSize) {
    NachOSThread *thread;
    ProcessAddrSpace *space;
    OpenFile *executable;
    int i;

    for (i=0; i<batchSize; i++) {
        executable = fileSystem->Open(files[i]);
        if (executable == NULL) {
            printf("Unable to open file %s\n", files[i]);
            continue;
        }
        thread = new NachOSThread(files[i]);
        space = new ProcessAddrSpace(executable);
        thread->space = space;

        delete executable; // close file

        space->InitUserCPURegisters(); // set the initial register
                                       // values

        // save initialized registers for the thread
        thread->SaveUserState();

        // Allocate Kernel Stack
        thread->AllocateThreadStack(ForkStartFunction, 0);

        thread->Schedule();
    }

    exitThreadArray[currentThread->GetPID()] = true;
    // FinishThread doesn't log completion time, NachOSThread::Exit does
    currentThread->FinishThread();

    // Let scheduler run the other threads
    machine->Run();
}

// Data structures needed for the console test.  Threads making
// I/O requests wait on a Semaphore to delay until the I/O completes.

static Console *console;
static Semaphore *readAvail;
static Semaphore *writeDone;

//----------------------------------------------------------------------
// ConsoleInterruptHandlers
// 	Wake up the thread that requested the I/O.
//----------------------------------------------------------------------

static void ReadAvail(int arg) { readAvail->V(); }
static void WriteDone(int arg) { writeDone->V(); }

//----------------------------------------------------------------------
// ConsoleTest
// 	Test the console by echoing characters typed at the input onto
//	the output.  Stop when the user types a 'q'.
//----------------------------------------------------------------------

void ConsoleTest(char *in, char *out) {
  char ch;

  console = new Console(in, out, ReadAvail, WriteDone, 0);
  readAvail = new Semaphore("read avail", 0);
  writeDone = new Semaphore("write done", 0);

  for (;;) {
    readAvail->P(); // wait for character to arrive
    ch = console->GetChar();
    console->PutChar(ch); // echo it!
    writeDone->P();       // wait for write to finish
    if (ch == 'q')
      return; // if q, quit
  }
}
