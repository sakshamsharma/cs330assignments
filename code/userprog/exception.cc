// exception.cc
//  Entry point into the Nachos kernel from user programs.
//  There are two kinds of things that can cause control to
//  transfer back to here from user code:
//
//  syscall -- The user code explicitly requests to call a procedure
//  in the Nachos kernel.  Right now, the only function we support is
//  "Halt".
//
//  exceptions -- The user code does something that the CPU can't handle.
//  For instance, accessing memory that doesn't exist, arithmetic errors,
//  etc.
//
//  Interrupts (which can also cause control to transfer from user
//  code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"
#include "console.h"
#include "synch.h"

//----------------------------------------------------------------------
// ExceptionHandler
//  Entry point into the Nachos kernel.  Called when a user program
//  is executing, and either does a syscall, or generates an addressing
//  or arithmetic exception.
//
//  For system calls, the following is the calling convention:
//
//  system call code -- r2
//      arg1 -- r4
//      arg2 -- r5
//      arg3 -- r6
//      arg4 -- r7
//
//  The result of the system call, if any, must be put back into r2.
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//  "which" is the kind of exception.  The list of possible exceptions
//  are in machine.h.
//----------------------------------------------------------------------
static Semaphore *readAvail;
static Semaphore *writeDone;
static void ReadAvail(int arg) { readAvail->V(); }
static void WriteDone(int arg) { writeDone->V(); }

static void ConvertIntToHex (unsigned v, Console *console)
{
    unsigned x;
    if (v == 0) return;
    ConvertIntToHex (v/16, console);
    x = v % 16;
    if (x < 10) {
        writeDone->P() ;
        console->PutChar('0'+x);
    }
    else {
        writeDone->P() ;
        console->PutChar('a'+x-10);
    }
}

void
CallOnScheduling(int which)
{
    DEBUG('t', "Now in thread \"%s\"\n", currentThread->getName());

    // If the old thread gave up the processor because it was finishing,
    // we need to delete its carcass.  Note we cannot delete the thread
    // before now (for example, in NachOSThread::FinishThread()), because
    // up to this point, we were still running on the old thread's stack!
    if (threadToBeDestroyed != NULL) {
        delete threadToBeDestroyed;
        threadToBeDestroyed = NULL;
    }

#ifdef USER_PROGRAM
    if (currentThread->space != NULL) {     // if there is an address space
        currentThread->RestoreUserState();     // to restore, do it.
        currentThread->space->RestoreStateOnSwitch();
    }
#endif
    machine->Run();
}

void
ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);
    int memval, vaddr, printval, tempval, exp;
    char buffer[257];
    unsigned printvalus, numPages;        // Used for printing in hex
    IntStatus oldstatus;
    ProcessAddrSpace *NewSpace;
    if (!initializedConsoleSemaphores) {
        readAvail = new Semaphore("read avail", 0);
        writeDone = new Semaphore("write done", 1);
        initializedConsoleSemaphores = true;
    }
    Console *console = new Console(NULL, NULL, ReadAvail, WriteDone, 0);;

    if ((which == SyscallException) && (type == SYScall_Halt)) {
        DEBUG('a', "Shutdown, initiated by user program.\n");
        interrupt->Halt();
    }
    else if ((which == SyscallException) && (type == SYScall_PrintInt)) {
        printval = machine->ReadRegister(4);
        if (printval == 0) {
            writeDone->P() ;
            console->PutChar('0');
        }
        else {
            if (printval < 0) {
                writeDone->P() ;
                console->PutChar('-');
                printval = -printval;
            }
            tempval = printval;
            exp=1;
            while (tempval != 0) {
                tempval = tempval/10;
                exp = exp*10;
            }
            exp = exp/10;
            while (exp > 0) {
                writeDone->P() ;
                console->PutChar('0'+(printval/exp));
                printval = printval % exp;
                exp = exp/10;
            }
        }
        // Advance program counters.
        machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
        machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
    }
    else if ((which == SyscallException) && (type == SYScall_PrintChar)) {
        writeDone->P() ;
        console->PutChar(machine->ReadRegister(4));   // echo it!
        // Advance program counters.
        machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
        machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
    }
    else if ((which == SyscallException) && (type == SYScall_PrintString)) {
        vaddr = machine->ReadRegister(4);
        machine->ReadMem(vaddr, 1, &memval);
        while ((*(char*)&memval) != '\0') {
            writeDone->P() ;
            console->PutChar(*(char*)&memval);
            vaddr++;
            machine->ReadMem(vaddr, 1, &memval);
        }
        // Advance program counters.
        machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
        machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
    }
    else if ((which == SyscallException) && (type == SYScall_PrintIntHex)) {
        printvalus = (unsigned)machine->ReadRegister(4);
        writeDone->P() ;
        console->PutChar('0');
        writeDone->P() ;
        console->PutChar('x');
        if (printvalus == 0) {
            writeDone->P() ;
            console->PutChar('0');
        }
        else {
            ConvertIntToHex (printvalus, console);
        }
        // Advance program counters.
        machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
        machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
    }
    else if ((which == SyscallException) && (type == SYScall_GetReg)) {
        // Since arguments are passed in registers as well, and arg1 is in r4
        // Register 4 contains the index of the register to be read

        // Read value from register 4, and read that register's value

        // Also, error checking (that the register number is valid)
        // has been done in machine.cc file's ReadRegister function

        // TODO Figure out if unsigned is needed
        machine->WriteRegister(2, (machine->ReadRegister(machine->ReadRegister(4))));

        // Advance program counters.
        machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
        machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
    } else if ((which == SyscallException) && (type == SYScall_GetPA)) {

        // Arguments passed in register 4 by convention
        int virtAddr = machine->ReadRegister(4);

        // TODO Decide if these variables should be global or stay
        int i;
        unsigned int vpn, offset;
        TranslationEntry *entry;
        unsigned int pageFrame;
        bool found = false;

        // Calculate the virtual page number, and offset within the
        // page from the virtual address
        vpn = (unsigned) virtAddr / PageSize;

        if (vpn < machine->pageTableSize) {
            offset = (unsigned) virtAddr % PageSize;

            if (machine->tlb == NULL) {
                // => page table => vpn is index into table
                if (machine->NachOSpageTable[vpn].valid) {
                    entry = &machine->NachOSpageTable[vpn];
                    found = true;
                }
            } else {
                for (entry = NULL, i = 0; i < TLBSize; i++)
                    // TODO Generates compiler warning. Investigate
                    if (machine->tlb[i].valid &&
                        (machine->tlb[i].virtualPage == vpn)) {
                        entry = &machine->tlb[i];
                        found = true;
                        break;
                    }
            }

            if (found) {
                pageFrame = entry->physicalPage;

                if (pageFrame < NumPhysPages) {
                    // Everything went fine
                    entry->use = TRUE;      // set the use, dirty bits
                    machine->WriteRegister(2, pageFrame * PageSize + offset);

                } else {
                    // ERROR 1 CATCH
                    // Physical page number was larger than num of
                    // phyical pages
                    machine->WriteRegister(2, -1);
                }
            } else {
                // ERROR 2 CATCH
                // The for loop didn't find a valid page table entry
                machine->WriteRegister(2, -1);
            }
        } else {
            // ERROR 3 CATCH
            // Virtual page number >= number of entries in page table
            machine->WriteRegister(2, -1);
        }

        // Advance program counters.
        machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
        machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
    } else if ((which == SyscallException) && (type == SYScall_GetPID)) {
        // We need to get the calling thread's PID
        machine->WriteRegister(2, currentThread->getPID());

        // Advance program counters.
        machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
        machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
    } else if ((which == SyscallException) && (type == SYScall_GetPPID)) {
        // We need to get the calling thread's PID
        machine->WriteRegister(2, ppid[currentThread->getPID()]);

        // Advance program counters.
        machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
        machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
    } else if ((which == SyscallException) && (type == SYScall_Time)) {
        machine->WriteRegister(2, stats->totalTicks);

        // Advance program counters.
        machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
        machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
    } else if ((which == SyscallException) && (type == SYScall_Sleep)) {
        tempval = machine->ReadRegister(4);  // Time more
        exp = stats->totalTicks;  // Time till now
        oldstatus = interrupt->SetLevel(IntOff); // Restore later

        if (tempval != 0) {
            scheduler->AddToSleepList((void*)currentThread, exp + tempval);
            currentThread->PutThreadToSleep();
        }
        currentThread->YieldCPU();
        interrupt->SetLevel(oldstatus);

        // Advance program counters.
        machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
        machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
    } else if ((which == SyscallException) && (type == SYScall_Yield)) {
        currentThread->YieldCPU();
        // TODO Should we send a return value?

        // Advance program counters.
        machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
        machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
    } else if ((which == SyscallException) && (type == SYScall_Exec)) {
        oldstatus = interrupt->SetLevel(IntOff); // Restore later
        tempval = 0;

        vaddr = machine->ReadRegister(4);
        machine->ReadMem(vaddr, 1, &memval);
        while ((*(char*)&memval) != '\0') {
            buffer[tempval] = (*(char*)&memval);
            tempval++;          // Buffer position being written to
            vaddr++;            // Virtual address being read
            machine->ReadMem(vaddr, 1, &memval);
        }
        buffer[tempval] = 0;

        OpenFile *executable = fileSystem->Open(buffer);

        if (executable == NULL) {
            // Returns if exev failed
            machine->WriteRegister(2, -1);

            // Advance program counters.
            machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
            machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
            machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
        }

        delete currentThread->space;
        currentThread->space = new ProcessAddrSpace(executable);
        currentThread->space->InitUserCPURegisters(); // init reg vals
        currentThread->space->RestoreStateOnSwitch(); // page table
                                                      // register
        delete executable; // close file

        interrupt->SetLevel(oldstatus);
    } else if ((which == SyscallException) && (type == SYScall_Fork)) {
        //creating a new thread

        tempval = sprintf(buffer, "Child of %d", currentThread->getPID());
        NachOSThread *newThread = new NachOSThread(buffer);
        newThread->setStatus(READY);

        numPages = (machine->pageTableSize);    //numPages in thread which
                                                //forked

        ASSERT(numPages + machine->PhysPagesUsed <= NumPhysPages);
                                //Check we're not trying to run anything
                                //too big - atleast until we have virtual
                                //memory

        oldstatus = interrupt->SetLevel(IntOff);    // Restore later
        NewSpace = new ProcessAddrSpace(numPages);  // Process Address Space
                                                    // for new thread

        newThread->space = NewSpace;             // New Address Space for
        NewSpace->CopyAddrSpace(currentThread->space);   // Child, Copying
        currentThread->space->RestoreStateOnSwitch();    // data from parent
                                                // thread's memory

        // incrementing Program Counter
        machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
        machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);

        // Saving UserState for Child Process
        machine->WriteRegister(2, 0);
        newThread->SaveUserState();
        interrupt->SetLevel(oldstatus);

        // Allocating ThreadStack to kernel Thread and adding to Ready Queue
        newThread->ThreadFork(CallOnScheduling, 0);

        // Child's PID returned to Parent
        machine->WriteRegister(2, newThread->getPID());
    } else if ((which == SyscallException) && (type == SYScall_Exit)) {
        currentThread->FinishThread();
        // TODO Check if we have to HALT in case of no other process
    } else {
        printf("Unexpected user mode exception %d %d\n", which, type);
        ASSERT(FALSE);
    }
}
