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


![[instr1.png]]
![instr](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr1.png)
- 15 different conditions can be used, the sixteenth `1111` is reserved
- In the absence of a suffix, the condition field of most instructions is set to `AL`
![[instr2.png]]
![instr2](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr2.png)


![[instr3.png]]
![instr3](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr3.png)

- Example:
![[instr4.png]]
![instr4](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr4.png)

![[instr5.png]]
![instr5](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr5.png)

## Branch Instructions

![[instr6.png]]
![instr6](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr6.png)

## Multiplication Instructions
- For 32 bit multiplication: 

![[mul.PNG]]
![mul](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/mul.PNG)

- For 64 bit multiplication:
 
![[instr7.png]]
![instr7](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr7.png)

## Data Transfer Instructions

![[trans.PNG]]
![instr8](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/trans.PNG)

![[instr9.png]]
![instr9](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr9.png)

## Block Transfer Instructions

![[instr10.png]]
![instr10](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr10.png)

![[instr11.png]]
![instr11](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr11.png)

## Swap

![[instr12.png]]
![instr12](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/instr12.png)
