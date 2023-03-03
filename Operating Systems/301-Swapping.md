# Swapping
----
A process must be in memory to be executed. It can be swapped temporarily out of memory to a backing store and then brought back into memory for continued execution. Swapping makes it possible for the total physical address space of all processes to exceed the real physical memory of the system, thus increasing the degree of multiprogramming in a system

## Standard Swapping
- Involves moving processes between main memory and a backing store
- The backing store is commanly a fast disk. It must be large enough to accomodate copies of all memory images for all users, and it must provide direct access to these memory images
- The system maintains a ready queue consisting of all processes whose memory images are on the backing store or in memory and are ready to run
- Whenever the CPU scheduler decides to execute a process, it calls the dispatcher. 
- The dispatcher checks to see whether the next process in the queue is in memory. If it is not, and if there is no free memory region, the dispatcher swaps out a process currently in memory and swaps in the desired process. It then reloads registers and transfers control to the selected process.

![[backingstore.png]]![backingstore](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/backingstore.png)

- The context switch time in such a swapping system is fairly high. Total swap time = swap in time  + swap out time
- The major part of the swap time is transfer time. The total transfer time is directly proportional to the amount of memory swapped
- A process with dynamic memory requirements will need to issue system calls (`request_memory()` and `release_memory()`) to inform the operating system of its changing memory needs
- Only an idle process can be swapped. If an operation is asynchronously accessing the user memory, then the process cannot be swapped.
- Transfers between operating system buffers and process memory occur only when the process is swapped in. This double buffering adds overhead as we now need to copy the data again, from kernel memory to user memory, before the user process can access it
- Standard swapping is not used in modern operating systems as it requires too much swapping time and provides too little execution time to be a reasonable memory management solution
- In one variation, swapping is normal disabled but will start if the amount of free memory falls below a threshold amount. Swapping is halted when the amount of free memory increases
- Another variation involves swapping portions of processes rather than entire processes, to decrease swap time

## Swapping on Mobile Systems
- Mobile systems typically do not support swapping in any form
- Mobile devices generally use flash memory rather than spacious hard disks as their persistent storage, resulting in memory space constraint
- There is also a limited number of writes that flash memory can tolerate before it becomes unreliable
- There is also a limited number of writes that flash memory can tolerate before it becomes unreliable