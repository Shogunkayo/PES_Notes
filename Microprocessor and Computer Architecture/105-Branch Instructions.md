# Branch Instructions
---
- A branch instruction changes the flow of execution or calls a routine
- Allows programs to have subroutines, conditional statements and loops
- Forces the program counter `pc` to point to a new address

| Code         | Description               | Operation                                                     |
| ------------ | ------------------------- | ------------------------------------------------------------- |
| B label      | branch                    | pc = label                                                    |
| BL label     | branch with link          | pc = label, lr = address of the next instruction after the BL |
| BX Rm        | branch exchange           | pc = Rm & 0xfffffffe, T = Rm & 1                              |
| BLX label Rm | branch exchange with link | pc = label, T = 1, pc = Rm & 0xfffffffe, T = Rm & 1, lr = address of the next instruction after the BLX                                             |

```
BL subroutine    ; branch to subroutine
CMP r1, #5       ; compare r1 with 5
MOVEQ r1, #0     ; if (r1==5) then r1 = 0

subroutine
	/*subroutine code*/
	MOV pc, lr   ; return by moving pc = lr
```

- Program  to find the sum of N numbers using half word
```
.DATA
	A: .HWORD 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0x100,  
	SUM: .WORD 0

.TEXT
	LDR R1, = A
	LDR R2, = SUM
	MOV R4, #0 ;Initialization
	MOV R5, #1 ;Count

L1:     
	LDRH R3, [R1]
	ADD R4, R4, R3 ;Add next element
	ADD R1, R1, #2 ;Go to the next address, adding 2 as 2-byte boundary for half word
	ADD R5, R5, #1 ;Increment 
	CMP R5, #11    ;Check whether all numbers are added
	BNE L1         ;Else branch to L1 location
	STRH R4, [R2]  ;Store the result in location SUM
	SWI 0x011      ;Logical end of the program

```

- Program to find the sum of N numbers using Byte Data
```
.data
A: .byte 1,2,3,4,5,6,7,8,9,10
SUM: .word 0

.text
LDR R1, =A
LDR R2, =SUM
MOV R4, #0
MOV R5, #1

Loop:
	LDRB R3, [R1]
	ADD R4, R4, R3
	ADD R1, R1, #1
	ADD R5, R5, #1
	CMP R5, #11
	BNE Loop

STRB R4, [R2]
SWI 0x011

```