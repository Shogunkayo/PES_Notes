# Paging
---
- Paging is another memory management scheme that also permits the phyisical address space of a process to be noncontiguous.
- However paging avoids external fragmentation and need for compaction, whereas segmentation does not. 
- It also solves the problem of fitting memory chunks of varying sizes onto the backing store. The problem arises because, when code fragments or data residing in main memory need to be swapped out, space must be found on the backing store
- The backing store has the same fragmentation problems discussed in connection with main memory, but access is much slower, so compaction is impossible

## Basic Method
- The basic method for implementing paging involves breaking physical memory into fixed-size blocks called frames and breaking logical memory into blocks of the same size called pages
- When a process is to be executed, its pages are loading into any available memory frames from their source (file system or backing store)
- The backing store is divided into fixed-sized blocks that are the same size as the memory frames or clusters of multiple frames
- The logical address space is now totally seperate from the physical address space, so a process can have 64-bit address space even though the systemm has less than `2^64` bytes of physical memory

![[basicmet.png]]
![basicmet](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/basicmet.png)

- Every address generated by the CPU is divided into two parts
- Page number `p` is used as an index into a page table which contains the base address of each page in physical memory
- Page offset `d` is combined with the base address to define the physical memory address that is sent to the memory unit

![[pagemodel.png]]
![pagemodel](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/pagemodel.png)

- The page size is defined by the hardware.  Size of a page is a power of 2. The selection of a power of 2 as a page size makes the translation of a logical address into a page number and page offset particularly easy

![[pagetable.png]]
![pagetable](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/pagetable.png)

- Paging is a form of dynamic relocation
- There is no external fragmentation, any free frame can be allocateed to a process that needs it. There may be some internal fragmentation: if a process needs `n` pages plus 1 byte, it would be allocated `n + 1` frames. 
- If process size is independent size, internal fragmentation can be expected to average one-half page per process. This consideration suggests that small page sizes are desirable
- Overhead is invovled in each page table entry, and this overhead reduces as the size of the pages increases. Also, disk I/O is more efficient when the amount of data being transferred is larger

When a process arrives in the system to be executed, its size, expressed in pages, is examined. Each page of the process needs one frame. Thus, if the process requires `n` pages, at least `n` frames must be available in memory. If `n` frames are available, they are allocated to this arriving process. The ﬁrst page of the process is loaded into one of the allocated frames, and the frame number
is put in the page table for this process. The next page is loaded into another frame, its frame number is put into the page table, and so on

An important aspect of paging is the clear seperation between the programmer's view of memory and the actual physical memory. The difference between the views of memory is reconciled by the address-translation hardware. The mapping of logical to physical addresses is hidden from the programmer and is controlled by the operating system. The user program has no way of addressing memory outside of its page table, and the table includes only those pages that the processor owns

- The frame table stores the allocation details of physical memory
- It has one entry for each physical page frame, indicating whether the latter is free or allocated, and, if it is allocated, to which page of which process or processes
- The operating system maintains a copy of the page table for each process, just as it maintains a copy of the instruction counter and register countents. This copy is used to translate logical addresses to physical addresses whenever the operating system must map a logical address to a physical address manually 
- It is also used by the CPU dispatcher to define the hardware page table when a process is to be allocated
- Paging therefore increases the context switching time

## Hardware Support
- Each operating system has its own methods for storing page tables
- Some allocate a page table for each process. A pointer to the page table is stored with the other register values in the process control block. When the dispatcher is told to start a process, it must reload the user registers and define the correct hardware page-table values from the stored user page table
- Other operating systems provide one or at most a few page tables, which decreases the overhead involved when processes are context-switched

The hardware implementation of the page table can be done in several ways
- In the simplest case, the page table is implementeed as a set of dedicated registers which should be built with very high speed logic to make the paging address
- Every access to memory must go through the paging map, so efficiency is a major consideration
- The CPU dispatcher reloads these registers. Instructions to load or modify the page table registers are privileged so that only the operating system can change the memory map
- The use of registers for the page table is satisfactory if the page table is reasonaly small. Most contemporary computers, however, allow the page table to be very large. For these machines, the page table is kept in main memory, and a page table base register (PTBR) points to the page table. Changing page tables requires changing only this one register, substantially reducing context-switch time
- The problem with this approach is the time required to access a user memory location. To acess location `i`, we must first index into the page table, using the value in the PTBR offset by the page number for `i`, which requires a memory access. It provides us with the frame number, which is combined with the page offset to produce the actual address. We can then access the desired place in memory.
- With this scheme, two memory accesses are needed to access a byte. Thus, memory access is slowed by a factor of 2

The standard solution to this problem is to use a special, small, fast-lookup hardware cache called a translation look-aside buffer (TLB)
- The TLB is associative, high speed memory
- Each entry consists of two parts: a key and a value
- When the associative memory is presented with an item, the item is compared with all keys simultaneously. If the item is found, the corresponding value field is returned
- The search is fast; a TLB lookup in modern hardware is part of the instruction pipeline, essentially adding no performance penalty
- Some CPUs implement separate instruction and data address TLBs. That can double the number of TLB entries available as those lookups can occur in different pipeline steps

The TLB contains only a few of the page-table entries. When a logical address is generated by the CPU, its page number is presenteed to the TLB. If the page number is found, its frame number is immediately available and is used to access memory. 
- These steps are executed as part of the instruction pipeline within the CPU, adding no performance penalty compared with a system that does not implement paging
- If the page number is not in the TLB (TLB miss), a memory reference to the page table must be made. When the frame number is obtained, we can use it to access memory. The page number and frame number is added to the TLB so that they will be found quickly on the next reference
- If the TLB is already full of entries, an existing entry must be selected for replacement. Replacement policies range from least recently used through round robin to random
- Some TLBs allow certain entries (key kernel code) to be wired down, meaning that they cannot be removed from the TLB

![[tlb.png]]
![tlb](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/tlb.png)

- Some TLBs store address space identifiers (ASIDs) in each TLB entry. It uniquely identifies each process and is used to provide address-space protection for that process
- When the TLB attempts to resolve virtual page numbers, it ensures that the ASID for the currently running process matches the ASID associated with the virtual page. If the ASIDs do not match, the attempt is treated as a TLB miss
- ASID also allows the TLB to contain entries for several different processes simultaneously. If the TLB does not support separate ASIDs, then everu time a new page table is selected, the TLB must be flushed to ensure that the next executing process does not use the wrong translation information

The percentage of times that the page number of interest is found in the TLB is called the hit ratio.
- A 80% hit ration means that we find the desired page number in the TLB 80% of the time
- If it takes 100ns to access memory, then a mapped memory access takes 100ns when the page number is in the TSB
- If the page number is not in the TSB, we must first access memory for the page table and frame number, and then access the desired byte in memory (100ns + 100ns = 200ns)
- Effective memory-access time for the above scenario is given as `effective access time = 0.80*100 + 0.20*200 = 120ns`
- In this example, there is a 20% slowdown in average memory access time (from 100ns to 120ns)

CPUs may provide multiple levels of TLBs. Calculating memory access time in modern CPUs is therefore much more complicated

## Protection
- Memory protection in a paged environment is accomplished by protection bits (usually kept in the page table) associated with each frame
- One bit can define a page to be read-write or read-only. Every reference to memory goes through the page table to find the correct frame number
- At the same time that the physical address is being computed, the protection bits can be checked to verify that no writes are being made to a read-only page. An attempt to write to a read-only page causes a hardware trap to the operating system or memory-protection violation
- One additional bit is generally attached to each entry in the page table: a valid-invalid bit. When this bit is set to valid, the associated page is in the process's logical address space. When the bit is set to invalid, the page is not in the process's logical address space. Illegal addresses are trapped by use of the valid-invalid bit

Suppose that in a system with 14-bit address space (0 to 16383), there is a program that should use only addresses 0 to 10468. Page size is 2KB
- Addresses in pages 0, 1, 2, 3, 4 and 5 are mapped normally through the page table
- Any attempt to generate an address in page 6 or 7 will find that the valid-invalid bit is set to invalid, and the computer will trap to the operating system
- Because the program extends only to address 10468, any reference beyond that address is illegal. However, references to page 5 are classified as valid, so access to addresses up to 12287 are valid, addresses from 12288 to 16383 are invalid

![[valinval.png]]
![valinval](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/valinval.png)

- This problem is a result of the 2KB page size and reflects the internal fragmentation of paging
- Many processes use only a small fraction of the address space available to them
- It would be wasteful in these cases to create a page table with entries for every page in the address range. Most of this table would be unused but would take up valuable memory space
- Some systems provide hardware, in the form of a page-table length register (PTLR), to indicate the size of the page table

## Shared Pages
- An advantage of paging is the possibility of sharing common code. This consideration is important in a time-sharing environment

![[codeshare.png]]
![codeshare](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/codeshare.png)

- Reentrant code is non-self modifying code: it never changes during execution. Reentrant code (or pure code) can be shared
- Two or more processes can execute the same code at the same time. Each process has its own copy of registers and data storage to hold the data for the process's execution
- Only one copy of the application needs to be kept in physical memory. Each user's page table maps onto the same physical copy of the editor, but data pages are mapped onto different frames
- If a text editor consists of 150KB of code and 50KB of data space, and the system needs to support 40 users, then we need only one copy of the editor (150KB) plus 40 copies of the 50KB of data space per user
- Compilers, window systems, runtime libraries and database systems too can be shared
- The read-only nature of shared code should not be left to the correctness of the code; the operating system should enforce this property