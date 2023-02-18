# 3-Stage Pipeline
----
![[3stage.png]]
![3stage](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/3stage.png)

The principal components are
- The register bank which stores the processor state. Has two read ports and one write port to access any register. An additional read port and write port for special access to program counter `r15`
- The barrel shifter, which can shift or rotate one operand by any number of bits
- The ALU, which performs the arithmetic and logic functions required by the instruction set
- The address register and incrementer, which select and hold all memory addresses and generate sequential addresses when required
- The data registers, which hold data passing to and from memory
- The instruction decoder and associated control logic

In a single-cycle data processing instruction, two register operands are accessed, the value on the B bus is shifted and combined with the value on the A bus in the ALU, then the result is written back into the register bank. The program counter value
is in the address register, from where it is fed into the incrementer, then the incremented value is copied back into `rl5` in the register bank and also into the address register to be used as the address for the next instruction fetch.

## Pipeline Stages
1. Fetch: the instruction is fetched from memory and placed in the instruction pipeline
2. Decode: the instruction is decoded and the datapath control signals prepared for the next cycle. The instruction 'owns' the decode logic but not the datapath
3. Execute: the instruction 'owns' the datapath. The register bank is read, an operand is shifted, the ALU result is generated and written back into a destination register

- At any one time, three different instructions may occupy each of these stages. The hardware in each stage has to be capable of independent operation
- For simple data processing instructions, the pipeline enables one instruction to be completed every clock cycle
- An individual instruction takes three clock cycles to complete => three-cycle latency
- The throughput is one instruction per cycle
![[3stage1.png]]
![3stage1](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/3stage1.png)

- The flow is less regular for a multi-cycle instruction
- All parts of the processor are active in every cycle and the memory is the limiting factor  
![[3stage2.png]]
![3stage2](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/3stage2.png)

The simplest way to view breaks in the ARM pipeline is to observe that:
- All instructions occupy the datapath for one or more adjacent cycles
- For each cycle that an instruction occupies the datapath, it occupies the decode logic in the immediately preceding cycle
- During the first datapath cycle, each instruction issues a fetch for the next instruction except one (5th one in the above image)
- Branch instructions flush and refill the instruction pipeline

## PC Behaviour
- The program counter must run ahead of the current instruction 
by two instructions (eight bytes ahead)
- Unpredictable behaviour if `r15` is used after the first cycle of an instruction, as the instruction will itself have incremented the PC during its first cycle

## Disadvantages
- 3-stage pipeline is very cost-effective, but higher performance requires the processor organization to be rethought
- Time required to execute a given program is given by 
	- `T = (N inst * CPI) / f clk` where 
	- `N inst` is the number of ARM instructions executed in the course of the program, which is constant
	- `CPI` is the average number of clock cycles per instruction
	- `f clk` is the processor's clock frequency
- Increasing the clock rate to increase performance requires the logic in each pipeline stage to be simplified => number of pipeline stages to be increased
- Reducing the `CPI` to increase performance requires that either
	-  a 3-stage pipeline ARM instruction which occupies more than one pipeline slot is re-implemented to occupy fewer slots
	-  pipeline stalls caused by dependencies between instructions are reduced
	- or a combination of both

## Memory Bottleneck
- Problem with reducing CPI relative to a 3-stage core => von Neumann bottleneck: any stored-program computer with a single instruction and data memory will have its performance limited by the available memory bandwidth
- Tightening up on the few cycles where the memory is not used will yield only a small performance gain
- The memory system must deliver more than one value in each clock cycle either by delivering more than 32 bits per cycle from a single memory, or by having seperate memories for instruction and data access
- As a result, higher performance ARM cores employ a 5-stage pipeline and have seperate instruction and data memories
- Breaking instruction execution down into 5 components instead of 3 reduces the maximum work which must be completed in a clock cycle, allowing a higher clock frequency to be used
- The seperate instruction and data memories (which may be seperate caches connected to a unified instruction and data main memory) allow a significant reduction in the core's CPI

# 5-Stage Pipeline
---
ARM processors with 5-stage pipeline have the following stages:
1. Fetch:  the instruction is fetched from memory and placed in the instruction pipeline
2. Decode: the instruction is decoded and the registed operands read from the register file. Most ARM instructions can source all their operands in one cycle as there are three operand read ports in the register file
3. Execute: an operand is shifted and the ALU result is generated. The memory address is computed in the ALU if the instruction is a load or store
4. Buffer/data: data memory is accessed if required. Else the ALU result is buffered for one clock cycle to give the same pipeline flow for all instructions
5. Write-back: the results generated by the instruction are written back to the register file, including any data loaded from the memory

![[5stage.png]]
![5stage](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/5stage.png)

## Data Forwarding
- Data dependencies arise when an instruction needs to use the result of one of its predecessors before that result has returned to the register file
- Forwarding paths allow results to be passed between stages as soon as they are available
- 5-stage ARM pipeline requires each of the three source operands to be forwarded from any of three intermediate result registers 
- In certain cases where a value is loaded and immediately used in the next instruction, the processor cannott avoid a one-cycle stall as the value loaded enters the processor at the end of the buffer/data stage and it is needed by the following instruction at the start of the execute stage
- To avoid stall => dont put a dependent instruction immediately after a load instruction
```
/* this causes a stall */
LDR R7, [from data]
ADD R2, R1, R7    @ using R7 immediately
```
- Such programs will run correctly, but could probably be rewritten to run faster by simple reordering the instructions to remove these dependencies

## PC Generation
- The 5-stage pipeline reads the instruction operands one stage earlier in the pipeline => `PC + 4`
- To prevent unacceptable code incompatibilities, all 5-stage pipeline ARMs emulate the behaviour of the older 3-stage designs
- The incremented PC value from the fetch stage is fed directly to the register file in the decode stage, bypassing the pipeline registers between the two stages
- `PC + 4` for the next instruction is equal to `PC + 8` for the current instruction, so the correct `r15` value is obtained


# Data Hazard 2
---
