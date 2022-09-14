# DATA STRUCTURES 
---

- Data -> raw fact
- Data structure -> arrangement of data with logical relationship between individual elements
- Data must be accessed as fast as possible

> Algorithm -> Flow chart -> Program

- Textbook - Data Structures using C/C++, Langsum Yedidyah 2nd edition


## Classification 

1. Built-in DS - Integer, float, character, pointer
- directly operated upon machine instruction
- all data types are primitive data structures

2. User Defined DS - Arrays, Lists, Files
- Grouping of homogenous or heterogenous data types
	1. Linear Data Structures- linked list, stack, queue
	2. Non-Linear Data Structures - tree, graph


## Representation

1. Logical - Mathematical - Abstract
2. Implementation - Code

One program can have multiple implementations


# Static Memory
----

- Memory is assigned before the execution of the program i.e. during the compilation time, in the stack region
- Used when data is fixed and known before processing

### Advantages 
- Stack region is a more structured memory area
- Faster execution than dynamic memory
- No need of pointers to access data

### Disadvantages
- As memory is allocated in compile time, the memory allocated is fixed and cannot be modified
- Can lead to under utilization or over utilization of memory
- Memory cannot be deleted explicitly
- Insertion and deletion of elements to/from intermediate positions is difficult


# Dynamic Memory
----
- Memory is allocated/deallocated at runtime in the heap region
- stblib.h library is used 

### Functions 
- malloc() - allocates requested size of bytes and returns a void pointer pointing to the first byte of the allocated space
- calloc() - allocates space for an array of elements, initializes them to 0 and then returns a void pointer to the memory
- realloc() - modifies the size of the previously allocated dynamic memory
- free() - releases the memory

### Advantages
- Memory is allocated only when the program is unit is active
- Memory is effectively utilized
- Allocated memory can be resized using runtime

### Disadvantages
- Heap region is less structured
- Execution is comparatively slower
- Pointers are required to work with dynamically allocated memory



# INDEX
----

### UNIT 1 - [[A0-Linked_List]]
### UNIT 2 - [[B0-Stack]] [[C0-Queue]]
