# Software Interrupt Instruction
---
- Software interrupt is an exception caused by an assembly software instruction
- Causes a software interrupt exception, which provides a mechanism for applications to call operating system routines
- Interrupt is an exception caused by some hardware condition happening outside the processor
- Trap is an exception caused by a failure condition of the processor like undefined instruction and divided_by_zero
- Reset is a special interrupt to start the system. Occurs at power up or when reset button is pressed

Syntax: `SWI SWI_number`
Operation:
- `lr_svc` = address of instruction following the SWI
- `spsr_svc = cpsr`
- `pc` = vectors + `0x8`
- `cpsr` mode = SVC
- `cpsr I` =  1 (mask IRQ interrupts)

- When the processor executes an `SWI` instruction, it sets the program counter `pc` to the offset `0x8` in the vector table
- The instruction also forces the procecssor mode to `SVC`, which allows an operating system routine to be called in a privileged mode
- Each `SWI` instruction has an associated `SWI` number, which is used to represent a particular function call or feature
- Typically, the `SWI` instruction is executed in user mode

![[swi.png]]![swi](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/swi.png)

![[swi2.png]]![swi2](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/swi2.png)

```
/* Procedure to compute if(R0 == R1) R2++ */

MOV R0, #10
MOV R1, #10
BL Link
SWI 0x11    ; logical end - terminate the program

Link:
	CMP R0, R1
	ADDEQ R2, R2, #1
	MOV PC, LR
```

- String must always be loaded into R0

```
/* Procedure to display a string on the screen */

.data
A: .asciz "HELLO WORLD"

.text
LDR R1, =A

Loop:
	LDRB R0, [R1], #1
	CMP R0, #0
	SWINE 0x00    ; display a character on the screen
	BNE Loop
	SWI 0x11      ; terminate the program
```

```
.data 
A: .asciz "HELLO WORLD"

.text
LDR R0, =A
SWI 0x02    ; display a string on the screen
SWI 0x11
```
![[swi3.png]]
![swi3](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/swi3.png)
