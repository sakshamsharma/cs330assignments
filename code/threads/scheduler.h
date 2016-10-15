// scheduler.h
//  Data structures for the thread dispatcher and scheduler.
//  Primarily, the list of threads that are ready to run.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "copyright.h"
#include "list.h"
#include "thread.h"

// The following class defines the scheduler/dispatcher abstraction --
// the data structures and operations needed to keep track of which
// thread is running, and which threads are ready but not running.

//----------------------------------------------------------------------
// SchedulingAlgo
// Enumeration of the possible scheduling algorithms
//----------------------------------------------------------------------
enum SchedulingAlgo {
    Default = 0,
    NonPFCFS = 1,
    NonPShortestNext = 2,
    RoundRobin1 = 3,
    RoundRobin2 = 4,
    RoundRobin3 = 5,
    RoundRobinMaxCPU = 6,
    Unix1 = 7,
    Unix2 = 8,
    Unix3 = 9,
    UnixMaxCPU = 10
};

class NachOSscheduler {
public:
    NachOSscheduler();          // Initialize list of ready threads
    ~NachOSscheduler();         // De-allocate ready list

    void ThreadIsReadyToRun(NachOSThread* thread);  // Thread can be dispatched.
    NachOSThread* FindNextThreadToRun();        // Dequeue first thread on the ready
    // list, if any, and return thread.
    void Schedule(NachOSThread* nextThread);    // Cause nextThread to start running
    void Print();           // Print contents of ready list

    void Tail();                        // Used by fork()

    // Returns size of readyThreadList
    int GetListSize() { return readyThreadList->GetSize(); };
#ifdef USER_PROGRAM
    SchedulingAlgo schedAlgo;       // Scheduling Algorithm for the scheduler
    void UpdatePriority(int burstLength);       // updates priorities of all
                                                // threads for next scheduling

#endif
private:
    List *readyThreadList;          // queue of threads that are ready to run,
                                    // but not running
};

#endif // SCHEDULER_H
