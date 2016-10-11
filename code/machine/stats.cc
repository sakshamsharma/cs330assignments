// stats.h
//  Routines for managing statistics about Nachos performance.
//
// DO NOT CHANGE -- these stats are maintained by the machine emulation.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "utility.h"
#include "stats.h"

//----------------------------------------------------------------------
// Statistics::Statistics
//  Initialize performance metrics to zero, at system startup.
//----------------------------------------------------------------------

Statistics::Statistics() {
    totalTicks = idleTicks = systemTicks = userTicks = 0;
    numDiskReads = numDiskWrites = 0;
    numConsoleCharsRead = numConsoleCharsWritten = 0;
    numPageFaults = numPacketsSent = numPacketsRecvd = 0;

    averageBurst = 0;
    minBurst = 0;
    maxBurst = 0;
    totalNonZeroBursts = 0;

    averageWait = 0;
    minWait = 0;
    maxWait = 0;
    varianceWait = 0;
    totalWaits = 0;
}

//----------------------------------------------------------------------
// Statistics::Print
//  Print performance metrics, when we've finished everything
//  at system shutdown.
//----------------------------------------------------------------------

void Statistics::Print() {
    printf("Ticks: total %d, idle %d, system %d, user %d\n", totalTicks,
           idleTicks, systemTicks, userTicks);
    printf("Disk I/O: reads %d, writes %d\n", numDiskReads, numDiskWrites);
    printf("Console I/O: reads %d, writes %d\n", numConsoleCharsRead,
           numConsoleCharsWritten);
    printf("Paging: faults %d\n", numPageFaults);
    printf("Network I/O: packets received %d, sent %d\n", numPacketsRecvd,
           numPacketsSent);

    printf("\n\n");

    printf("Total CPU busy time: %d\n", systemTicks+userTicks);
    printf("Total execution time: %d\n", totalTicks);
    printf("CPU utilization: %.2f%%\n",
           ((systemTicks+userTicks)*100.0)/totalTicks);
    printf("Maximum CPU burst length: %d\n", maxBurst);
    printf("Minimum CPU burst length: %d\n", minBurst);
    printf("Average CPU burst length: %d\n", averageBurst);
    printf("Number of non-zero CPU bursts: %d\n", totalNonZeroBursts);
    printf("Maximum waiting time: %d\n", maxWait);
    printf("Minimum waiting time: %d\n", minWait);
    printf("Average waiting time: %d\n", averageWait);
    printf("Variance in waiting time: %d\n", varianceWait);
}
