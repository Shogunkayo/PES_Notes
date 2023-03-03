# Contiguous Allocation
---
- The memory is usually divided into two partitions: one for os and one for user processes
- Location of interrupt vector decides whether to place the os in low memory or high memory
- In contiguous memory allocation, each process is contained in a single section of memory that is contiguous to the section containing the next process

## Memory Protection
- The relocation register scheme provides an effective way to allow the operating system's size to change dynamically
- The operating system contains code and buffer space for device drivers
- If a device driver is not commonly used, its code and data is not kept in memory. Such code is called transient operating system code

## Memory Allocation
- One of the simplest methods for allocating memory is to divide memory into several fixed size partitions where each partition may contain exactly one process => degree of multiprogramming is bound by the number of partitions
- In the multiple partition method, when a partition is free, a process is selected from the input queue and is loaded into the free partition
- In the variable partition scheme, the operating systemk keeps a table indicating which parts of memory are available and which are occupied
- Initially, all memory is available for user processes and is considered one large block of available memory, a hole
- Memory contains a set of holes of various sizes. 
- When a process arrives and needs memory, the system searches the set for a hole that is large enough for this process. If the hole is too large, it is split into two parts: one allocated to the process and the other is returned to the set of holes
- When a process terminates, it releases its block of memory, which is then placed back in the set of holes. If the new hole is adjacent to other holes, these adjacent holes are merged to form one larger hole
- This procedure is a particular instance of the general dynamic storage allocation problem, which concerns how to satisfy a request of size `n` from a list of free holes
- The first-fit, best-fit and worst-fit strategies are the ones most commonly used to select a free hole from the set of available holes

#### First fit
- Allocate the first hole that is big enough
- Searching can start either at the beginning of the set of holes or at the location where the previous first-fit search ended
- Generally faster

#### Best fit
- Allocate the smallest hole that is big enough
- Must search entire list, unless the list is ordered by size
- Produces the smallest leftover hole

#### Worst fit
- Allocate the largest hole
- Must search entire list, unless the list is ordered by size
- Produces the largest leftover hole
- Simulations have shown that both first fit and best fit are better than worst fit in terms of decreasing time and storage utilization

## Fragmentation
- Memory fragmentation is when most of your memory is allocated in a large number of non-contiguous blocks, or chunks - leaving a good percentage of your total memory unallocated, but unusable for most typical scenarios. This results in out of memory exceptions, or allocation errors
- Both the first fit and best fit strategies suffer from external fragmentation
- External fragmentation exists when there is enough total memory space to satisfy a request but the available spaces are not contiguous: storage is fragmented into a large number of small holes
- In the worst case, there could be a block of free memory between every two processes. If all theses small pieces of memory were in one big free block instead, several more processes would be able to run
- 50 percent rule: Statistical analysis of first fit reveals that even with some optimization, given `N` allocated blocks, another `0.5N` blocks will be lost to fragmentation
- One solution to external fragmentation is compaction: shuffle the memory contents so as to place all free memory together in one large block
- Compaction is possible only if relocation is dynamic and is done at execution time. If relocation is static and is done at assembly or load time, compaction cannot be done
- The simplest compaction algorithm is to move all processes toward one end of memory, and all holes in the other direction. This scheme can be expensive
- The difference between memory allocated and required space or memory is called internal fragmentation