# Hierarchical Paging
---
- Most modern computer systems support a large logical address space (2^32 to 2^64). In such an environment, the page table itself becomes excessively large. Simple solution is to divide the page table into smaller pieces
- One way is to use a two-level paging algorithm, in which the page table itself is also paged

![[twolevel.png]]
![twolevel](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/twolevel.png)

Consider a system with a 32-bit logical address space and a page size of 4KB. A logical address is divided into a page number consisting of 20 bits and a page offset consisting of 12 bits. The page number is further divided into a 10-bit page number and a 10-bit page offset

![[twolevel1.png]]
![twolevel1](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/twolevel1.png)

- `p1` is an index into the outer page table and `p2` is the displacement within the page of the inner page table 
- As the address translation works from the outer page table inward, this scheme is also known as forward-mapped page table

For a system with a 64-bit logical address space, a two-level paging scheme is no longer appropriate. Suppose that the page size in such a system is 4KB (2^12). The page table consists of upto 2^52 entries (2^64 / 2^12). The inner page tables can conveniently be one page long, or contain 2^10 4-byte entries. The outer page table consists of 2^42 entries, or 2^42 bytes

![[twolevel2.png]]
![twolevel2](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/twolevel2.png)

To avoid such a large table, the outer page table can be divided into smaller pieces in various ways

![[twolevel3.png]]
![twolevel3](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/twolevel3.png)

The 64-bit UltraSPARC would require seven levels of paging - a prohibitive number of memory accesses - to translate each logical address. For 64-bit architectures, hierarchical page tables are generally considered inappropriate

# Hashed Page Tables
---
- A common approach for handling address spaces larger than 32 bits is to use a hashed page table, with the hash value being the virtual page number
- Each entry in the hash table contains a linked list of elements that hash to the same location (to handle collisions)
- Each element consists of three fields: 
	1. virtual page number
	2. value of the mapped page number
	3. a pointer to the next element in the linked list

- The virtual page number in the virtual address is hashed into the hash table 
- The virtual page number is compared with field 1 in the first element of the linked list
- If there is a match, the corresponding page frame (field 2) is used to form the desired physical address
- If there is no match, subsequent entreis in the linked list are searched for a matching virtual page number

![[hashedpage.png]]
![hashedpage](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/hashedpage.png)

- A variation of this scheme, useful for 64-bit address space, uses clustered page tables where each entry in the hast table refers to several pages rather than a single page
- A single page table entry can store the mappings for multiple physical page frames
- Clustered page tables are particularly useful for sparse address spaces, where memory references are noncontiguous and scattered throughout the address space

# Inverted Page Tables
---
- Each process has an associated page table
- The page tables has one entry for each page that the process is using
- Processes reference pages through the page's virtual addresses. The operating system must translate this reference into a physical memory address. 
- Since the table is sorted by virtual address, the operating system is able to calculate where in the table the associated physical address entry is located and to use that value directly

One of the drawbacks of this method is that each page table may consist of millions of entries. These tables may consume large amounts of physical memory just to keep track of how other physical memory is being used. To solve this problem, an inverted page table is used.
- An inverted page table has one entry for each real page (or frame) of memory
- Each entry consists of the virtual address of the page stored in the real memory location, with the information about the process that owns the page
- Only one page table is in the system, and it has only one entry for each page of physical memory
- Inverted page tables often require that an address-space identifier be stored in each entry of the page table, since the table usually contains several different address spaces mapping physical memory
- Storing the address-space identifier ensures that a logical page for a particular process is mapped to the corresponding physical page frame

![[invertedpage.png]]
![invertedpage](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/invertedpage.png)

- IBM was the first major company to use inverted page tables, starting with the IBM System 38
- In IBM RT, each virtual address in the system consists of a triple`<process-id, page-number, offset>`
- Each inverted page table entry is a pair `<process-id, page-number>` where the process-id assumes the role of the address-space identifier
- Although this scheme decreases the amount of memory needed to store each page table, it increases the amount of time needed to search the table when a page reference occurs
- Inverted page table is sorted by physical addresses, but lookups occur on virtual addresses. The whole table might need to be searched before a match is found. This can be alleviated by using a hash table
- Systems that use inverted page tables have difficulty implementing shared memory. Shared memory is usually implemented as multiple virtual addresses (one for each process sharing the memory) that are mapped to one physical address. This standard method cannot be useed with inverted page tables as there is only virtual page entry for every physical page
- A simple technique for addressing this issue is to allow the page table to contain only one mapping of a virtual address to the shared physical address. This means that references to virtual addresses that are not mapped result in page faults