# Memory
---
CPU basic components:
- RAM (latches and decoder)
- Register
	- Instruction Register
	- Program Counter
	- Accumulator
- Buses
	- Address
	- Data
	- Control

- Memory latency is the time it takes to transfer a word of data to or from memory
- Memory bandwidth is the number of bits or bytes that can be transferred in one second

## Speed vs Size vs Cost
Fast memory is more expensive per bit than slower
90/10 rule => a program spends 90% of its time in 10% of its code

## CPU Cache
- Cache memory is an architectural arrangement which makes the main memory appear faster to the processor than it really is
- Level 3 > 2 > 1 in size, 1 > 2 > 3 in speed

## Cache Terminology
Block -> Main memory
Line -> Cache memory

- Block placement
- Block identification
- Block replacement
- Write strategy

- 3 mapping
1. Direct mapping -> Block(i) % no of lines
	- If there is free space in the cache, not possible to use it
	- 4 bit for word, 5bit for tag, 7bit address
1. Associative mapping -> divide by 
	- K way division
	- Only word and tag
	- Time complexity is higher as it needs to check all lines
1. Set-associative mapping
	 - K way sets
	 - Combination of direct and associative

## Least Recently Used
Random simple to buiild in the hardware
LRU becomes expensive as the number of blocks increases

Consider a fully associative mapped cache of size 16KB with block size 256bytes. The size of main memory is 128KB. Find number of tag bits

# Replacement Policies
---
