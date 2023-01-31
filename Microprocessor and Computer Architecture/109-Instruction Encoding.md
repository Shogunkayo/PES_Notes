# Instruction Encoding 
---
## Data Processing Instruction:

| Bits |  Purpose |
| ---- | -------- | 
| 31 to 28 | condition |
| 27 and 26 | always 0 for data processing |
| 25 | 0 if register and 1 if immediate value |
| 24 to 21 | opcode for mnemonic |
| 20 | 'S' flag |
| 19 to 16 | first operand register |
| 15 to 12 | destination register |
| 0 to 11 | operand 2 |

- If second operand is immediate => 0 to 7 bits is the immediate value and 8 to 11 is #rot. Else 0 to 3 bits is the second operand register and rest of the bits are 0
- When barrel shifter is used, 4th bit is 0 if the shift amount is specified as an immediate, else 1 if specified by a register. 5-6 bits indicate shitft type and 7-11 indicate shift amount

| Shift Type | Bits |
| ---------- | ---- |
| logical left | 00 |
| logical right | 01 |
| arithmetic right | 10 |
| rotate right | 11 |

- 15 different conditions can be used, the sixteenth `1111` is reserved
- In the absence of a suffix, the condition field of most instructions is set to `AL`
- Condition code: (will be given in question paper)
![[instr2.png]]
![instr2](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr2.png)

- Example:
![[instr4.png]]
![instr4](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr4.png)

![[instr5.png]]
![instr5](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr5.png)

## Branch Instructions

| Bits     | Purpose                  |
| -------- | ------------------------ |
| 31 to 28 | condition                |
| 27 to 25 | 101                      |
| 24       | Link, 1 if BL and 0 if B |
| 0 to 23  | offset                         |

## Multiplication Instructions
- For 32 bit multiplication: 

| Bits     | Purpose                |
| -------- | ---------------------- |
| 31 to 28 | condition              |
| 27 to 22 | 000000                 |
| 21       | 1 if accumulate else 0 |
| 20       | S flag                 |
| 19 to 16 | Rd                     |
| 15 to 12 | Rn                     |
| 11 to 8  | Rs                     |
| 7 to 4   | 1001                   |
| 3 to 0   | Rm (for accumulate)                      |

- For 64 bit multiplication:

| Bits     | Purpose                 |
| -------- | ----------------------- |
| 31 to 28 | condition               |
| 27 to 23 | 00001                   |
| 22       | 1 if signed, else 0     |
| 21       | 1 if accumulate, else 0 |
| 20       | S flag                  |
| 19 to 16 | RdHi                    |
| 15 to 12 | RdLo                    |
| 11 to 8  | Rs                      |
| 7 to 4   | 1001                    |
| 3 to 0   | Rm                        |

## Data Transfer Instructions

| Bits     | Purpose                                                               |
| -------- | --------------------------------------------------------------------- |
| 31 to 28 | condition                                                             |
| 27 to 26 | 01                                                                    |
| 25       | 1 if offset is register, 0 if offset is immediate                     |
| 24       | 1 for pre indexing, 0 for post indexing                               |
| 23       | 1 for up (add offset to base), 0 for down (subtract offset from base) |
| 22       | 1 for transfer byte quantity, 0 for transfer word quantity            |
| 21       | 1 if writeback, else 0                                                |
| 20       | 1 for load, 0 for store                                               |
| 19 to 16 | base register                                                         |
| 15 to 12 | source/destination register                                           |
| 11 to 0  | offset (similar to the format for data processing instructions)                                                                      |

![[instr9.png]]
![instr9](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr9.png)

## Block Transfer Instructions

| Bits     | Purpose                  |
| -------- | ------------------------ |
| 31 to 28 | condition                |
| 27 to 25 | 100                      |
| 24       | 1 if pre indexed, else 0 |
| 23       | 1 if up, else 0          |
| 22       | S flag                   |
| 21       | 1 if writeback, else 0   |
| 20       | 1 for load, 0 for store  |
| 19 to 16 | base register            |
| 15 to 0  | register list                         |

- Example: 
![[instr11.png]]
![instr11](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr11.png)

## Swap

| Bits     | Purpose                |
| -------- | ---------------------- |
| 31 to 28 | condition              |
| 27 to 23 | 00010                  |
| 22       | 1 for byte, 0 for word |
| 21 to 20 | 00                     |
| 19 to 16 | base register          |
| 15 to 12 | destination register   |
| 11 to 8  | 0000                   |
| 7 to 4   | 1001                   |
| 3 to 0   | source register        | 
