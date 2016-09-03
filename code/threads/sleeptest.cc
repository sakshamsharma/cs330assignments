// threadtest.cc
//  Simple test case for the threads assignment.
//
//  Create two threads, and have them context switch
//  back and forth between themselves by calling NachOSThread::YieldCPU,
//  to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.


////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////// //
// // NOTE                                                                 // //
// // TO RUN THIS TEST, EITHER MODIFY THE MAKEFILES (NOT RECOMMENDED)      // //
// //     OR INSTEAD COPY THIS FILE'S CONTENTS INTO THE THREADTEST.CC FILE // //
// ////////////////////////////////////////////////////////////////////////// //
////////////////////////////////////////////////////////////////////////////////

#include "copyright.h"
#include "system.h"
#include "synch.h"

//----------------------------------------------------------------------
// SimpleThread
//  Loop 5 times, yielding the CPU to another ready thread
//  each iteration.
//
//  "which" is simply a number identifying the thread, for debugging
//  purposes.
//----------------------------------------------------------------------

void SimpleThread(int which) {
    int num;

    for (num = 0; num < 35; num++) {
        printf("*** thread %d looped %d times\n", which, num);
        printf("Time is %d\n", stats->totalTicks);

        if (num == 20 && which == 1) {
            printf("Thread %d is going to sleep now\n");

            int tempval = 150;
            int exp = stats->totalTicks;  // Time till now

            IntStatus oldstatus = interrupt->SetLevel(IntOff); // Time more
            if (tempval != 0) {
                scheduler->AddToSleepList((void*)currentThread, exp + tempval);
                currentThread->PutThreadToSleep();
            }
            currentThread->YieldCPU();
            interrupt->SetLevel(oldstatus);

        } else {
            currentThread->YieldCPU();
        }
    }
}

//----------------------------------------------------------------------
// ThreadTest
//  Set up a ping-pong between two threads, by forking a thread
//  to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void ThreadTest() {
    DEBUG('t', "Entering SimpleTest");

    NachOSThread *t = new NachOSThread("forked thread");

    t->ThreadFork(SimpleThread2, 1);
    SimpleThread2(0);
}
