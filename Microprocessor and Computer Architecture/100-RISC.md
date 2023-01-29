# Microprocessors and Computer Architecture
---
- A microprocessor is the basic computing unit on an Integrated Chip
- Instruction set (the set of instructions that the microprocessor can execute), bandwidth(the number of bits processed in a single instruction) and clock speed(the number of instructions per second the processor can execute in MHz) differentiate different microprocessors

## Microprocessor
- Accepts digital data as input, processes it according to the instructions stored in its memory, and provides the result as its output
- Dont have ROM, RAM, and other peripheral components
- Memory, I/O and other components need to be connected externally
- Cannot be used in compact systems
- Power consumption is high

## Microcontroller
- Comprises of CPU, in addition with a fixed amount of ROM, RAM and other peripherals all embedded on a single chip
- Also called as a mini computer
- Designed to perform specific tasks 
- Reduces the size and cost

# Processor design trade-offs
---
> The art of processor design is to define an instruction set that supports the functions that are useful to the programmer whilst allowing an implementation that is as efficient as possible

- The semantic gap between a high-level language construct and a machine instruction is bridged by a compiler
- Prior to 1980 => increasing complexity to reduce the semantic gap. Single instruction procedure entries and exits were incorporated
- Common misconception that computers spend their time computing, carrying out arithmetic operations on user data
- In practice they spend very little time 'computing'. Most of the work is in moving the relevant data items and program routines rather than processing it in any transformational sense

![[instrusage.png]]

To improve data movement =>
- Pipelining
- Use of cache memory
- Super-scalar instruction execution - A superscalar processor executes more than one instruction during a clock cycle by simultaneously dispatching multiple instructions to different execution units on the processor.

# Reduced Instruction Set Computer
----
- Paper by Patterson and Ditzel => optimal architecture for a single chip processor need not be the same as the optimal architecture for a multi-chip processor

## Key Features of RISC 1
- A fixed 32-bit instruction size with few formats whereas CISC processors had variable length instruction sets with many formats
- A load-store architecture where instructions that process data operate only on registers and are separate from instructions that access memory; CISC processors typically allowed values in memory to be used as operands in data processing instructions
- A large register bank of thirty-two 32-bit registers, all of which could be used for any purpose, to allow the load-store architecture to operate efficiently; CISC register sets were getting larger, but none was this large and most had different registers for different purposes

## RISC Organization
- Hard-wired instruction decode logic; CISC processors used large microcode ROMs to decode their instructions.
- Pipelined execution; CISC processors allowed little, if any, overlap between con secutive instructions (though they do now).
- Single-cycle execution; CISC processors typically took many clock cycles to complete a single instruction.

## RISC Advantages
- A smaller die size => A simple processor should require fewer transistors and less silicon area. Whole CPU will fit on a chip, leaving more die area free for performance-enhancing features like cache memory, memory management functions, floating-point hardware 
- A shorter development time => A simple processor should take less design effort and therefore have a lower design cost
- A higher performance => "smaller things have higher natural frequencies => insects flap their wings faster than small birds", so a simple processor ought to allow a high clock rate

## Pipelining
- Simplest form of concurrency to implement in a processor
-  Delivers around two to three times speed-up
- Simple instruction set greatly simplifies the design of the pipeline

> It was entirely feasible to implement a fixed-length instruction load-store architecture using microcode, multi-cycle execution and no pipeline, but such an implementation would exhibit no advantage over an off-the-shelf CISC. It was not possible, at that time, to implement a hard-wired, single-cycle execution pipelined CISC. 

## RISC Drawbacks
- Generally has poor code density compared with CISC => consequence of fixed-length instruction set. In the absence of cache, poor code density leads to more main memory bandwidth
- Doesn't execute x86 code

## RISC vs CISC
- Number of lines of code in the program increased compared to CISC, but the amount of work done by each individual instruction decreased


```
mov ax, 10
mov bx, 5
mul bx, ax
```
CISC => (2 movs × 1 cycle) + (1 mul × 30 cycles) = 32 cycles

```
mov ax, 0
mov bx, 10
mov cx, 5

Begin
	add ax, bx
	dec cx
	bne Begin
```
RISC => (3 movs × 1 cycle) + (5 adds × 1 cycle) + (5 dec x 1 cycle)+(5 loops × 1 cycle) = 18 cycles

| RISC                               | CISC                                         |
| ---------------------------------- | -------------------------------------------- |
| Simple instructions, few in number | Many complex instructions                    |
| Fixed length instructions          | Variable length instructions                 |
| Multiple register sets             | Single register set                          |
| Three operands per instruction     | One or two register operands per instruction |
| Single-cycle instructions          | Multi-cycle instructions                     |
| Highly pipelined                   | Less pipelined                               |
| Few addressing modes               | Many addressing modes                                             |


