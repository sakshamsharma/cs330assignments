// addrspace.cc
//  Routines to manage address spaces (executing user programs).
//
//  In order to run a user program, you must:
//
//  1. link with the -N -T 0 option
//  2. run coff2noff to convert the object file to Nachos format
//      (Nachos object code format is essentially just a simpler
//      version of the UNIX executable object code format)
//  3. load the NOFF file into the Nachos file system
//      (if you haven't implemented the file system yet, you
//      don't need to do this last step)
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "addrspace.h"
#include "noff.h"

//----------------------------------------------------------------------
// SwapHeader
//  Do little endian to big endian conversion on the bytes in the
//  object file header, in case the file was generated on a little
//  endian machine, and we're now running on a big endian machine.
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
//  Create an address space to run a user program.
//  Load the program from a file "executable", and set everything
//  up so that we can start executing user instructions.
//
//  Assumes that the object code file is in NOFF format.
//
//  First, set up the translation from program memory to physical
//  memory.  For now, this is really simple (1:1), since we are
//  only uniprogramming, and we have a single unsegmented page table
//
//  "executable" is the file containing the object code to load into memory
//----------------------------------------------------------------------

ProcessAddrSpace::ProcessAddrSpace(OpenFile *executable, int& error)
{
    NoffHeader noffH;
    unsigned int i, size;
    error = 0;

    executable->ReadAt((char *)&noffH, sizeof(noffH), 0);
    if ((noffH.noffMagic != NOFFMAGIC) &&
        (WordToHost(noffH.noffMagic) == NOFFMAGIC))
        SwapHeader(&noffH);
    ASSERT(noffH.noffMagic == NOFFMAGIC);

    // how big is address space?
    size = noffH.code.size + noffH.initData.size + noffH.uninitData.size
        + UserStackSize;    // we need to increase the size
    // to leave room for the stack
    numPagesInVM = divRoundUp(size, PageSize);
    size = numPagesInVM * PageSize;

    // check we're not trying to run anything too big --
    // at least until we have virtual memory
    if (!(numPagesInVM + machine->PhysPagesUsed <= NumPhysPages)) {
        // Return error by reference
        error = -1;
        return;
    }

    DEBUG('a', "Initializing address space, num pages %d, size %d\n",
          numPagesInVM, size);

    // first, set up the translation
    NachOSpageTable = new TranslationEntry[numPagesInVM];
    for (i = 0; i < numPagesInVM; i++) {
        NachOSpageTable[i].virtualPage = i; // virtual page # + Physical
        //pages already used = phys page #
        NachOSpageTable[i].physicalPage = i + machine->PhysPagesUsed;
        NachOSpageTable[i].valid = TRUE;
        NachOSpageTable[i].use = FALSE;
        NachOSpageTable[i].dirty = FALSE;
        NachOSpageTable[i].readOnly = FALSE;  // if the code segment was entirely on
        // a separate page, we could set its
        // pages to be read-only
    }

    // zero out the entire address space, to zero the unitialized data segment
    // and the stack segment
    bzero(machine->mainMemory + machine->PhysPagesUsed * PageSize, size);

    // then, copy in the code and data segments into memory
    if (noffH.code.size > 0) {
        DEBUG('a', "Initializing code segment, at 0x%x, size %d\n",
              noffH.code.virtualAddr, noffH.code.size);
        executable->ReadAt(&(machine->mainMemory[noffH.code.virtualAddr + machine->PhysPagesUsed*PageSize]),
                           noffH.code.size, noffH.code.inFileAddr);
    }
    if (noffH.initData.size > 0) {
        DEBUG('a', "Initializing data segment, at 0x%x, size %d\n",
              noffH.initData.virtualAddr, noffH.initData.size);
        executable->ReadAt(&(machine->mainMemory[noffH.initData.virtualAddr + machine->PhysPagesUsed*PageSize]),
                           noffH.initData.size, noffH.initData.inFileAddr);
    }

    machine->PhysPagesUsed += numPagesInVM;     //Update Phys Pages used
}

//----------------------------------------------------------------------
//ProcessAddrSpace::ProcessAddrSpace
//  Constructs a Process address space with the specified number of pages
//
//  The method is same as the other constructor
//
//----------------------------------------------------------------------

ProcessAddrSpace::ProcessAddrSpace(unsigned int NumPagesReqd, int& error)
{
    unsigned int i, size;
    error = 0;

    numPagesInVM = NumPagesReqd;
    size = numPagesInVM * PageSize;

    // check we're not trying to run anything too big --
    // at least until we have virtual memory
    if (!(numPagesInVM + machine->PhysPagesUsed <= NumPhysPages)) {
        // Return error by reference
        error = -1;
        return;
    }

    DEBUG('a', "Initializing address space for copying, num pages %d, size %d\n",
          numPagesInVM, size);

    // first, set up the translation
    NachOSpageTable = new TranslationEntry[numPagesInVM];

    // Set the virtual and physical addresses of the pages
    // in this newly created address space translation entry
    for (i = 0; i < numPagesInVM; i++) {
        NachOSpageTable[i].virtualPage = i; // virtual page # + physicalpages used = physical page #
        NachOSpageTable[i].physicalPage = i + machine->PhysPagesUsed;

        // Temporarily set these values to default
        // to aid later translation requests in CopyAddrSpace
        NachOSpageTable[i].valid = TRUE;
        NachOSpageTable[i].use = FALSE;
        NachOSpageTable[i].dirty = FALSE;
        NachOSpageTable[i].readOnly = FALSE;
        // These flags will later be copied from the SourceSpace
        // in the CopyAddrSpace routine, and these default values
        // would be overwritten
    }

    // zero out the entire address space, to zero the unitialized data segment
    // and the stack segment
    bzero(machine->mainMemory + machine->PhysPagesUsed * PageSize, size);

    //update number of allotted physical pages
    machine->PhysPagesUsed += numPagesInVM;
}

//----------------------------------------------------------------------
// ProcessAddrSpace::~ProcessAddrSpace
//  Dealloate an address space.  Nothing for now!
//----------------------------------------------------------------------

ProcessAddrSpace::~ProcessAddrSpace()
{
    delete NachOSpageTable;
}

//----------------------------------------------------------------------
// ProcessAddrSpace::InitUserCPURegisters
//  Set the initial values for the user-level register set.
//
//  We write these directly into the "machine" registers, so
//  that we can immediately jump to user code.  Note that these
//  will be saved/restored into the currentThread->userRegisters
//  when this thread is context switched out.
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
//  On a context switch, save any machine state, specific
//  to this address space, that needs saving.
//
//  For now, nothing!
//----------------------------------------------------------------------

void ProcessAddrSpace::SaveStateOnSwitch()
{}

//----------------------------------------------------------------------
// ProcessAddrSpace::RestoreStateOnSwitch
//  On a context switch, restore the machine state so that
//  this address space can run.
//
//      For now, tell the machine where to find the page table.
//----------------------------------------------------------------------

void ProcessAddrSpace::RestoreStateOnSwitch()
{
    machine->NachOSpageTable = NachOSpageTable;
    machine->pageTableSize = numPagesInVM;
}

//----------------------------------------------------------------------
// ProcessAddrSpace::CopyAddrSpace
//      While a fork operation, Copy the whole memory of the parent
//      thread to child thread so that child runs from the state
//      that parent was on right before the fork Syscall
//
//      Get starting physical addresses of both virtual memory
//      through translate and copy one-one byte from the parent
//      to the child
//----------------------------------------------------------------------

void ProcessAddrSpace::CopyAddrSpace(ProcessAddrSpace *SourceSpace)
{
    ASSERT(interrupt->getLevel() == IntOff);

    // So that subsequent translations work in context of
    // this source address space
    SourceSpace->RestoreStateOnSwitch();

    // numPages in the Virtual memory should have been set
    // for this thread
    ASSERT(numPagesInVM == machine->pageTableSize);

    int PASourceSpace, PADestSpace;
    unsigned int size = numPagesInVM * PageSize, i;

    // Converts 0 virtual address to phy address
    // stores it in PASourceSpace
    machine->Translate(0, &PASourceSpace, 1, FALSE);

    // Page table's size should not exceed memory size
    ASSERT((PASourceSpace >= 0) && (PASourceSpace + size <= MemorySize));

    // Set machine to state of newly created addr space
    // For the next translate command
    this->RestoreStateOnSwitch();

    // Find phy address of 0 in the newly created address space
    // This is where we will copy the source space
    machine->Translate(0, &PADestSpace, 1, TRUE);

    ASSERT(PADestSpace >= 0);
    ASSERT(PADestSpace + size <= MemorySize)

    for (i = 0; i < size; i++) {
        machine->mainMemory[PADestSpace + i] =
            machine->mainMemory[PASourceSpace + i];
    }

    // Since we cannot access Page table of SourceSpace
    // but we need to copy the flags anyway
    // We will provide pointer to the newly created page table
    // and let the source space copy it's own flags to that location
    SourceSpace->CopyFlagsToPageTableNamed(NachOSpageTable);
}

// Copy the private page table flags to the supplied location
// Require this because NachOSPageTable is private member
void ProcessAddrSpace::CopyFlagsToPageTableNamed(TranslationEntry *DestPageTable) {
    for (unsigned int i = 0; i < numPagesInVM; i++) {
        DestPageTable[i].valid = NachOSpageTable[i].valid;
        DestPageTable[i].use = NachOSpageTable[i].use;
        DestPageTable[i].dirty = NachOSpageTable[i].dirty;
        DestPageTable[i].readOnly = NachOSpageTable[i].readOnly;
    }
}
