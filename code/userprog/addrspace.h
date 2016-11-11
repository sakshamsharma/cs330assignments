// addrspace.h
//	Data structures to keep track of executing user programs
//	(address spaces).
//
//	For now, we don't keep any information about address spaces.
//	The user level CPU state is saved and restored in the thread
//	executing the user program (see thread.h).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#ifndef ADDRSPACE_H
#define ADDRSPACE_H

#include "copyright.h"
#include "filesys.h"
#include "noff.h"

#define UserStackSize		1024 	// increase this as necessary!

class ProcessAddrSpace {
  public:
    // Create an address space,
    // initializing it with the program
    // stored in the file "executable"
    ProcessAddrSpace(OpenFile *threadexecutable, char *filename, int pid);

    ProcessAddrSpace (ProcessAddrSpace *parentSpace, int pid);	// Used by fork

    ~ProcessAddrSpace();			// De-allocate an address space

    void InitUserCPURegisters();		// Initialize user-level CPU registers,
        					// before jumping to user code

    void SaveStateOnSwitch();			// Save/restore address space-specific
    void RestoreStateOnSwitch();		// info on a context switch

    // Finds next page to write to
    int GetNextPageToWrite(int vpn, int notToReplace);

    unsigned GetNumPages();

    int AddSharedSpace(int SharedSpaceSize);    // appends SharedSPaceSize bytes of
                                                // shared memory
    void SaveToSwap(int virtualpagenumber);     // save this page to swap memory
                                                // so that next page can be brought

    TranslationEntry* GetPageTable();

    void PageFaultHandler(unsigned vpn);        // Allocates Physical Page for virtual
                                                // page number vpn

    char *fileName;                     // Store a pointer to the executable
                                        // our program is stored in

    char *swapMemory;
    int pid;
                                                // used while forking
    NoffHeader noffH;                           // stores the noffHeader data
  private:
    TranslationEntry *NachOSpageTable;	// Assume linear page table translation
					// for now!
    unsigned int numPagesInVM;		// Number of pages in the virtual
					// address space
};

#endif // ADDRSPACE_H
