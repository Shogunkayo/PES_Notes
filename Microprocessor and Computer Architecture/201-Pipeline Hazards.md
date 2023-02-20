# Pipeline Hazards
---
- Hazards prevent the next instruction in the instruction stream from executing during its designated clock cycle
- They reduce the performance from the ideal speedup gained by pipelining
- There are 3 classes of hazards:
1.  Structural hazards arise from resource conflicts when the hardware cannot support all possible combinations of instructions simultaneously in overlapped execution
2. Data hazards arise when an instruction depends on the results of a previous instruction in a way that is exposed by overlapping of instructions in the pipeline
3. Control hazards arise from the pipelining of branches and other instructions that change the PC
- Hazards in pipelines can make it necessary to stall the pipeline

![[pipeline1.png]]
![pipeline1](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/pipeline1.png)

![[pipeline2.png]]
![pipeline2](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/pipeline2.png)

![[pipeline3.png]]
![pipeline3](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/pipeline3.png)

## Structural Hazards
- When a processor is pipelined, the overlapped execution of instructions requires pipelining of functional units and duplication of resources to allow all possible combinations of instructions in the pipeline
- If some combination of instructions cannot be accomodated because of resource conflicts, the processor is said to have a structural hazard
- The most common instances of structural hazards arise when some functional unit is not fully pipelined and when some resource has not been duplicated enough to allow all combinations of instructions in the pipeline to execute
- For example, a processor may have only one register-file write port, but under certain circumstances, the pipeline might want to perform two writes in a clock cycle
- To resolve this hazard, we stall the pipeline for 1 clock cycle when the data memory access occurs
- A stall is commonly called a pipeline bubble

## Data Hazards
- Data hazards occur when the pipeline changes the order of read/write accesses to operands so that the order differs from the order seen by sequentially executing instructions on an unpipelined processor
- Data hazards can be minimized by forwarding
1. The ALU result from both the EX/MEM and MEM/WB pipeline registers is always fed back to the ALU inputs
2. If the forwarding hardware detects that the previous ALU operation has written the register corresponding to a source for the current ALU operation, control logic selects the forwarded result as the ALU input rather than the value read from the register file

## Branch Hazards
