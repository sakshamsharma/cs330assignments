// addrspace.cc
//	Routines to manage address spaces (executing user programs).
//
//	In order to run a user program, you must:
//
//	1. link with the -N -T 0 option
//	2. run coff2noff to convert the object file to Nachos format
//		(Nachos object code format is essentially just a simpler
//		version of the UNIX executable object code format)
//	3. load the NOFF file into the Nachos file system
//		(if you haven't implemented the file system yet, you
//		don't need to do this last step)
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "addrspace.h"
#include "utility.h"

//----------------------------------------------------------------------
// SwapHeader
// 	Do little endian to big endian conversion on the bytes in the
//	object file header, in case the file was generated on a little
//	endian machine, and we're now running on a big endian machine.
//----------------------------------------------------------------------

static void
SwapHeader (NoffHeader *noffH)
{
	noffH->noffMagic = WordToHost(noffH->noffMagic);
	noffH->code.size = WordToHost(noffH->code.size);
	noffH->code.virtualAddr = WordToHost(noffH->code.virtualAddr);
	noffH->code.inFileAddr = WordToHost(noffH->code.inFileAddr);
	noffH->initData.size = WordToHost(noffH->initData.size);
	noffH->initData.virtualAddr = WordToHost(noffH->initData.virtualAddr);
	noffH->initData.inFileAddr = WordToHost(noffH->initData.inFileAddr);
	noffH->uninitData.size = WordToHost(noffH->uninitData.size);
	noffH->uninitData.virtualAddr = WordToHost(noffH->uninitData.virtualAddr);
	noffH->uninitData.inFileAddr = WordToHost(noffH->uninitData.inFileAddr);
}

//----------------------------------------------------------------------
// ProcessAddrSpace::ProcessAddrSpace
// 	Create an address space to run a user program.
//	Load the program from a file "executable", and set everything
//	up so that we can start executing user instructions.
//
//	Assumes that the object code file is in NOFF format.
//
//	First, set up the translation from program memory to physical
//	memory.  For now, this is really simple (1:1), since we are
//	only uniprogramming, and we have a single unsegmented page table
//
//	"executable" is the file containing the object code to load into memory
//----------------------------------------------------------------------

ProcessAddrSpace::ProcessAddrSpace(OpenFile *execfile, char *programname, int _pid)
{
    unsigned int i, size;
    unsigned vpn, offset;
    TranslationEntry *entry;
    unsigned int pageFrame;

    pid = _pid;

    fileName = copyFileName(programname);

    execfile->ReadAt((char *)&noffH, sizeof(noffH), 0);
    if ((noffH.noffMagic != NOFFMAGIC) &&
		(WordToHost(noffH.noffMagic) == NOFFMAGIC))
    	SwapHeader(&noffH);
    ASSERT(noffH.noffMagic == NOFFMAGIC);

    // how big is address space?
    size = noffH.code.size + noffH.initData.size + noffH.uninitData.size
        + UserStackSize;	// we need to increase the size
    // to leave room for the stack
    numPagesInVM = divRoundUp(size, PageSize);
    size = numPagesInVM * PageSize;
    swapMemory = new char[size];

    DEBUG('a', "Initializing address space, num pages %d, size %d\n",
          numPagesInVM, size);
    // first, set up the translation
    NachOSpageTable = new TranslationEntry[numPagesInVM];
    for (i = 0; i < numPagesInVM; i++) {
        NachOSpageTable[i].virtualPage = i;
        NachOSpageTable[i].physicalPage = -1;
        NachOSpageTable[i].valid = FALSE;
        NachOSpageTable[i].use = FALSE;
        NachOSpageTable[i].dirty = FALSE;
        NachOSpageTable[i].shared = FALSE;
        NachOSpageTable[i].ifUsed = FALSE;

        // if the code segment was entirely on
        // a separate page, we could set its
        // pages to be read-only
        NachOSpageTable[i].readOnly = FALSE;
    }
}

//----------------------------------------------------------------------
// ProcessAddrSpace::ProcessAddrSpace (ProcessAddrSpace*) is called by a forked thread.
//      We need to duplicate the address space of the parent.
//----------------------------------------------------------------------

ProcessAddrSpace::ProcessAddrSpace(ProcessAddrSpace *parentSpace, int _pid)
{
    pid = _pid;
    printf("Forking off %d from %d\n", pid, currentThread->GetPID());

    numPagesInVM = parentSpace->GetNumPages();
    noffH = parentSpace->noffH;
    unsigned i, numSharedPages = 0;

    fileName = copyFileName(parentSpace->fileName);

    TranslationEntry* parentPageTable = parentSpace->GetPageTable();

    for(i = 0; i < numPagesInVM; ++i) {
        if (parentPageTable[i].shared) {
            ++ numSharedPages;
        }
    }

    unsigned int size = (numPagesInVM - numSharedPages) * PageSize;
    swapMemory = new char[size];
    bzero(swapMemory, size);

    // first, set up the translation
    NachOSpageTable = new TranslationEntry[numPagesInVM];
    for (i = 0; i < numPagesInVM; i++) {
        NachOSpageTable[i].virtualPage = i;
        NachOSpageTable[i].shared = parentPageTable[i].shared;
        NachOSpageTable[i].ifUsed = parentPageTable[i].ifUsed;
        NachOSpageTable[i].valid = parentPageTable[i].valid;
        NachOSpageTable[i].use = parentPageTable[i].use;
        NachOSpageTable[i].dirty = parentPageTable[i].dirty;
        NachOSpageTable[i].readOnly = parentPageTable[i].readOnly;
    }
    // Copying of data will be done later on
}

// Copies all valid pages from the parent's space in case of forked process
void ProcessAddrSpace::CopyParentAddrSpace(ProcessAddrSpace *parentSpace) {
    unsigned startAddrParent, startAddrChild, newPhysPage;

    TranslationEntry* parentPageTable = parentSpace->GetPageTable();
    memcpy(swapMemory, parentSpace->swapMemory, numPagesInVM*PageSize);

    for (int i = 0; i < numPagesInVM; i++) {
        NachOSpageTable[i].ifUsed = parentPageTable[i].ifUsed;
        NachOSpageTable[i].valid = parentPageTable[i].valid;

        TranslationEntry* parentPageTable = parentSpace->GetPageTable();
        // If shared memory, then physical page is from parent's address space
        if (!parentPageTable[i].shared) {

            // if (parentPageTable[i].ifUsed && !(parentPageTable[i].valid)) {
            //     parentSpace->PageFaultHandler(i);
            // }

            if (parentPageTable[i].valid) {
                // Get new page, but do not overwrite parent's page
                newPhysPage = GetNextPageToWrite(i, parentPageTable[i].physicalPage);

                NachOSpageTable[i].physicalPage = newPhysPage;

                startAddrParent = parentPageTable[i].physicalPage*PageSize;
                startAddrChild = newPhysPage*PageSize;

                // Copy the contents
                memcpy(&(machine->mainMemory[startAddrChild]),
                       &(machine->mainMemory[startAddrParent]), PageSize);

                stats->numPageFaults ++;
            }
        } else {
            NachOSpageTable[i].physicalPage = parentPageTable[i].physicalPage;
            stats->numPageFaults ++;
        }

        // if (NachOSpageTable[i].valid && !(NachOSpageTable[i].shared)) {
        //     currentThread->SortedInsertInWaitQueue (1000+stats->totalTicks);
        // }
    }
    printf("Parent is finished\n");
}

//----------------------------------------------------------------------
// ProcessAddrSpace::AddSharedSpace
//  Appends Shared Memory, creates a new page table, copies old
//  Translation Entries and creates TE for shared pages
//----------------------------------------------------------------------

int ProcessAddrSpace::AddSharedSpace(int SharedSpaceSize) {
    unsigned int i, numSharedPages = divRoundUp(SharedSpaceSize, PageSize);
    TranslationEntry* NewTranslation = new TranslationEntry[numPagesInVM + numSharedPages];

    for (i = 0; i < numPagesInVM; ++ i) {
        NewTranslation[i].virtualPage = NachOSpageTable[i].virtualPage;
        NewTranslation[i].physicalPage = NachOSpageTable[i].physicalPage;

        NewTranslation[i].shared = NachOSpageTable[i].shared;
        NewTranslation[i].valid = NachOSpageTable[i].valid;
        NewTranslation[i].use = NachOSpageTable[i].use;
        NewTranslation[i].dirty = NachOSpageTable[i].dirty;
        NewTranslation[i].readOnly = NachOSpageTable[i].readOnly;
        NewTranslation[i].ifUsed = NachOSpageTable[i].ifUsed;
    }

    for (; i < numSharedPages + numPagesInVM; ++ i) {
        NewTranslation[i].virtualPage = i;
        NewTranslation[i].physicalPage = GetNextPageToWrite(i, -1);
        bzero(&machine->mainMemory[(NewTranslation[i].physicalPage)*PageSize], PageSize);
        NewTranslation[i].shared = TRUE;
        NewTranslation[i].valid = TRUE;
        NewTranslation[i].use = FALSE;
        NewTranslation[i].dirty = FALSE;
        NewTranslation[i].readOnly = FALSE;
        NewTranslation[i].ifUsed = TRUE;

        machine->isShared[NewTranslation[i].physicalPage] = 1;

        printf("Sharing phys at vpn %d: %d\n", NewTranslation[i].physicalPage, i);
    }

    numPagesInVM += numSharedPages;

    delete NachOSpageTable;

    NachOSpageTable = NewTranslation;
    RestoreStateOnSwitch();

    return (numPagesInVM - numSharedPages) * PageSize;
}

bool ProcessAddrSpace::isVpnShared(int vpn) {
    return NachOSpageTable[vpn].shared;
}

//----------------------------------------------------------------------
// ProcessAddrSpace::GetNextPageToWrite
//  Finds next page for page fault handler
//  and write it to swap array if it was dirty
//----------------------------------------------------------------------
int ProcessAddrSpace::GetNextPageToWrite(int vpn, int notToReplace) {
    int i, foundPage = -1;
    if (replacementAlgo == NO_REPL) {
        // If all pages have been allocated,
        // we cannot proceed
        if(numPagesAllocated >= NumPhysPages) {
            printf("%d %d\n", numPagesAllocated, NumPhysPages);
            ASSERT(false);
        }
    }

    printf("[%d] wants a page for vpn %d\n", pid, vpn);
    if (usedPages == NumPhysPages) {
        switch(replacementAlgo) {
            case RANDOM_REPL:
                printf("Entering random replacement algorithm\n");
                foundPage = Random()%(NumPhysPages);

                // If this is a shared page or not to be replaced, loop
                while (machine->isShared[foundPage] ||
                       foundPage == notToReplace) {
                    foundPage = Random()%(NumPhysPages);
                };

                if (machine->memoryUsedBy[foundPage] != -1) {
                    threadArray[machine->memoryUsedBy[foundPage]]->space->SaveToSwap(machine->virtualPageNo[foundPage]);
                    printf("Swapped phys page %d!\n", foundPage);
                }

                break;

            case LRU_CLOCK_REPL:
                printf("Entering clock lru replacement algorithm\n");

                while(machine->referenceBit[LRU_Clock_ptr] ||
                      machine->isShared[LRU_Clock_ptr] ||
                      LRU_Clock_ptr == notToReplace) {

                    printf("Ptr: %d, bit %d\n", LRU_Clock_ptr, machine->referenceBit[LRU_Clock_ptr]);
                    machine->referenceBit[LRU_Clock_ptr] = 0;
                    LRU_Clock_ptr = (LRU_Clock_ptr+1)%NumPhysPages;
                }

                foundPage = LRU_Clock_ptr;

                // set the refernce Bit of replaced page
                machine->referenceBit[foundPage]=TRUE;

                // Swap out the replaced page
                // if the process owner exists
                if(machine->memoryUsedBy[foundPage] != -1) {
                    threadArray[machine->memoryUsedBy[foundPage]]->space->SaveToSwap(machine->virtualPageNo[foundPage]);
                    printf("[%d] Swapped phys page %d!\n", foundPage);
                }

                // Increment the Clock pointer
                LRU_Clock_ptr = (LRU_Clock_ptr+1)%NumPhysPages;
                break;

            case LRU_REPL:
                printf("Entering clock lru replacement algorithm\n");

                long long int val = (1LL)<<60 -1;
                for(int i = 0; i<NumPhysPages; i++){
                    if( machine->LRUTimeStamp[i] < val  && machine->isShared[i] == FALSE  && i != notToReplace ){
                        foundPage = i;
                        val = machine->LRUTimeStamp[i];
                    }
                }
                ASSERT(foundPage != -1);
                // Swap out the replaced page
                // if the process owner exists
                if(machine->memoryUsedBy[foundPage] != -1) {
                    threadArray[machine->memoryUsedBy[foundPage]]->space->SaveToSwap(machine->virtualPageNo[foundPage]);
                }
                printf("Swapped phys page %d!\n", pid);
                break;

        }
    } else {
        if (replacementAlgo == NO_REPL) {
            foundPage = numPagesAllocated++;
        } else {
            // Iterate over physical address to
            // find an unused address
            for (i=0; i<NumPhysPages; i++) {
                if (machine->memoryUsedBy[i] == -1) {
                    foundPage = i;
                    machine->referenceBit[foundPage] = 1;
                    break;
                }
            }
        }

        // Since inside this 'else' block, we always use up
        // a new page:
        usedPages++;
    }

    machine->memoryUsedBy[foundPage] = this->pid;
    machine->virtualPageNo[foundPage] = vpn;

    ASSERT(foundPage != -1);

    printf("FoundPage is: %d\n", foundPage);
    return foundPage;
}

//----------------------------------------------------------------------
// ProcessAddrSpace::PageFaultHandler
// 	Handles Page fault for virtual page number vpn
// 	Allocates physical page for it and copies the
// 	required data from executable
//----------------------------------------------------------------------

void ProcessAddrSpace::PageFaultHandler(unsigned virtAddr) {
    printf("[%d] Page fault for %d\n", currentThread->GetPID(), virtAddr);

    stats->numPageFaults ++;

    unsigned vpn = virtAddr/PageSize;
    ASSERT(vpn <= numPagesInVM);

    unsigned offset, i;
    unsigned startVirtAddr = PageSize * vpn;
    unsigned endVirtAddr = startVirtAddr + PageSize;

    unsigned newPhysPage = GetNextPageToWrite(vpn, -1);

    // Modify the contents of Page Table Entry for Virtual Page vpn
    NachOSpageTable[vpn].physicalPage = newPhysPage;
    NachOSpageTable[vpn].valid = TRUE;

    bzero(&(machine->mainMemory[newPhysPage*PageSize]), PageSize);

    OpenFile *executable = fileSystem->Open(fileName);

    if (!NachOSpageTable[vpn].ifUsed) {
        unsigned start = max(startVirtAddr, noffH.code.virtualAddr);
        unsigned end = min(endVirtAddr, noffH.code.virtualAddr+noffH.code.size);

        // A simplified approach to copying the page to memory
        executable->ReadAt(&(machine->mainMemory[newPhysPage * PageSize]),
                           PageSize, noffH.code.inFileAddr + vpn*PageSize);

        // For sake of complete correctness, this is the ideal copying
        // methodology:

        /*
        if (start < end) {
            offset = start - startVirtAddr;
            executable->ReadAt(&(machine->mainMemory[newPhysPage * PageSize + offset]),
                               (end - start), noffH.code.inFileAddr + (start - noffH.code.virtualAddr));
        }

        start = max(startVirtAddr, noffH.initData.virtualAddr);
        end = min(endVirtAddr, noffH.initData.virtualAddr+noffH.initData.size);

        if (start < end) {
            offset = start - startVirtAddr;
            executable->ReadAt(&(machine->mainMemory[newPhysPage * PageSize + offset]),
                               (end - start), noffH.initData.inFileAddr + (start - noffH.initData.virtualAddr));
        }
        */

        printf("[%d] Used first time vpn:%d at phys: %d\n", pid, vpn, newPhysPage);
    } else {
        // Get this from swap memory
        memcpy(&(machine->mainMemory[newPhysPage*PageSize]), &(swapMemory[vpn*PageSize]), PageSize);
    }

    delete executable;
    NachOSpageTable[vpn].ifUsed = 1;

    printf("[%d] Going to sleep\n", pid);
    currentThread->SortedInsertInWaitQueue (1000+stats->totalTicks);
    printf("[%d] Returned from sleep\n", pid);
    printf("Was faulting on vpn: %d\n", vpn);
    printf("It is now at phys: %d\n", NachOSpageTable[vpn].physicalPage);
}


//----------------------------------------------------------------------
// ProcessAddrSpace::SaveToSwap
//      if the speciied virtual page number is dirty, save it
//      to swap and set the corresponding Translation Entries
//      to their new values.
//
//----------------------------------------------------------------------

void ProcessAddrSpace::SaveToSwap(int vpn) {
    printf("[%d] Saving vpn:%d, phys:%d to swap\n",
           pid, NachOSpageTable[vpn].physicalPage, vpn);
    fflush(stdout);

    // Physical Page should Exist
    ASSERT(NachOSpageTable[vpn].valid);

    // If page is dirty, save it to swap
    if (NachOSpageTable[vpn].dirty) {
        unsigned pageFrame = NachOSpageTable[vpn].physicalPage;
        memcpy(&(swapMemory[vpn*PageSize]), &(machine->mainMemory[pageFrame*PageSize]),
                PageSize);
        NachOSpageTable[vpn].dirty = FALSE;
    }

    // Set Translation Entry's variables
    NachOSpageTable[vpn].physicalPage = -1;
    NachOSpageTable[vpn].valid = FALSE;
}

//----------------------------------------------------------------------
// ProcessAddrSpace::~ProcessAddrSpace
//  Dealloate an address space.  Nothing for now!
//----------------------------------------------------------------------

ProcessAddrSpace::~ProcessAddrSpace()
{
    int physPageNumber;
    for(int i = 0; i < numPagesInVM; i++) {
        if (!NachOSpageTable[i].shared && NachOSpageTable[i].valid) {
            physPageNumber = NachOSpageTable[i].physicalPage;
            machine->memoryUsedBy[physPageNumber] = -1;
            machine->virtualPageNo[physPageNumber] = -1;
            usedPages--;
        }
    }
    delete fileName;
    delete [] swapMemory;
    delete NachOSpageTable;
}

//----------------------------------------------------------------------
// ProcessAddrSpace::InitUserCPURegisters
// 	Set the initial values for the user-level register set.
//
// 	We write these directly into the "machine" registers, so
//	that we can immediately jump to user code.  Note that these
//	will be saved/restored into the currentThread->userRegisters
//	when this thread is context switched out.
//----------------------------------------------------------------------

void
ProcessAddrSpace::InitUserCPURegisters()
{
    int i;

    for (i = 0; i < NumTotalRegs; i++)
	machine->WriteRegister(i, 0);

    // Initial program counter -- must be location of "Start"
    machine->WriteRegister(PCReg, 0);

    // Need to also tell MIPS where next instruction is, because
    // of branch delay possibility
    machine->WriteRegister(NextPCReg, 4);

   // Set the stack register to the end of the address space, where we
   // allocated the stack; but subtract off a bit, to make sure we don't
   // accidentally reference off the end!
    machine->WriteRegister(StackReg, numPagesInVM * PageSize - 16);
    DEBUG('a', "Initializing stack register to %d\n", numPagesInVM * PageSize - 16);
}

//----------------------------------------------------------------------
// ProcessAddrSpace::SaveStateOnSwitch
// 	On a context switch, save any machine state, specific
//	to this address space, that needs saving.
//
//	For now, nothing!
//----------------------------------------------------------------------

void ProcessAddrSpace::SaveStateOnSwitch()
{}

//----------------------------------------------------------------------
// ProcessAddrSpace::RestoreStateOnSwitch
// 	On a context switch, restore the machine state so that
//	this address space can run.
//
//      For now, tell the machine where to find the page table.
//----------------------------------------------------------------------

void ProcessAddrSpace::RestoreStateOnSwitch()
{
    machine->NachOSpageTable = NachOSpageTable;
    machine->NachOSpageTableSize = numPagesInVM;
}

unsigned
ProcessAddrSpace::GetNumPages()
{
   return numPagesInVM;
}

TranslationEntry*
ProcessAddrSpace::GetPageTable()
{
   return NachOSpageTable;
}
