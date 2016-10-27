// stats.h
//  Routines for managing statistics about Nachos performance.
//
// DO NOT CHANGE -- these stats are maintained by the machine emulation.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include <math.h>
#include <limits.h>
#include "utility.h"
#include "stats.h"

// For some reason, the ones imported from utility aren't visible
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#define max(a,b)  (((a) > (b)) ? (a) : (b))

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
    minBurst = INT_MAX;
    maxBurst = 0;
    totalNonZeroBursts = 0;

    averageWait = 0;
    totalWaits = 0;
}

void Statistics::newBurst(int burstTime) {
    if (burstTime > 0) {
        int totalBurstTime = averageBurst * totalNonZeroBursts + burstTime;
        totalNonZeroBursts++;
        averageBurst = totalBurstTime / totalNonZeroBursts;

        minBurst = min(burstTime, minBurst);
        maxBurst = max(burstTime, maxBurst);
        // if (burstTime > 200) {
        //     printf("Failed on Burst Time %d\n", burstTime);
        //     ASSERT(false);
        // }
    }
}

void Statistics::newWait(int waitTime) {
    int totalWaitTime = averageWait * totalWaits + waitTime;
    averageWait = totalWaitTime / (totalWaits+1);
    totalWaits++;
}

void Statistics::newCompletion(int startToEnd) {
    compTimes.push_back(startToEnd);
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

    printf("Average waiting time: %d\n", averageWait);

    int totalSum = 0;
    int minComp = INT_MAX, maxComp = 0;
    for (std::vector<int>::iterator it = compTimes.begin();
         it!=compTimes.end(); it++) {
        totalSum += *it;
        minComp = min(minComp, *it);
        maxComp = max(maxComp, *it);
    }
    printf("Maximum completion time: %d\n", maxComp);
    printf("Minimum completion time: %d\n", minComp);

    float averageComp = (totalSum*1.0)/compTimes.size();
    printf("Average completion time: %.2f\n", averageComp);

    float secondMoment = 0.0;
    for (std::vector<int>::iterator it = compTimes.begin();
         it!=compTimes.end(); it++) {
        secondMoment += pow(*it-averageComp, 2);
    }
    printf("Variance of completion times: %.2f\n", secondMoment/compTimes.size());
}
