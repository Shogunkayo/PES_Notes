# Data Processing Instructions
---
- ARM data processing instructions enable the programmer to perform arithmetic and logical operations on data values in the registers
- The only instructions which modify data values
- Typically require two operands and produce a single result, though there are exceptions

1. All operands are 32 bits wide and come from registers or are specified as literals in the instruction itself
2. The result, if there is one, is 32 bits wide and is placed in a register
3. Each of the operand registers and the result register are independently specified in the instruction (3 address format)

- Semicolons indicate that everything to the right of it is a comment and should be ignored by the assembler
- Operands must be written in correct order => result register first, then the first operand and lastly the second operand
- The second operand can be either a register or an immediate value (constant) preceded by `#`
- Any data processing instruction can set the condition codes. By default, they do not affect the condition flags

## Arithmetic operations
- Perform binary arithmetic on two 32-bit operands which may be signed or unsigned
- The carry-in, when used, is the current value of the `C` bit in the CPSR

| Code           | Description                 | Operation            |
| -------------- | --------------------------- | -------------------- |
| ADD r0, r1, r2 | simple addition             | r0 = r1 + r2         |
| ADC r0, r1, r2 | add with carry              | r0 = r1 + r2 + C     |
| SUB r0, r1, r2 | simple subtract             | r0 = r1 - r2         |
| SBC r0, r1, r2 | subtract with carry         | r0 = r1 - r2 + C - 1 |
| RSB r0, r1, r2 | reverse subtract            | r0 = r2 - r1         |
| RSC r0, r1, r2 | reverse subtract with carry | r0 = r2 - r1         |

## Bit-wise logical operations
- Perform the specified boolean logic operations on each bit pair of the input operands

| Code           | Description                                                                               | Operation         |
| -------------- | ----------------------------------------------------------------------------------------- | ------------------|
| AND r0, r1, r2 | AND operation on each bit                                                                 | r0 = r1 and r2    |
| ORR r0, r1, r2 | OR operation on each bit                                                                  | r0 = r1 or r2     |
| EOR r0, r1, r2 | XOR operation on each bit                                                                 | r0 = r1 xor r2    |
| BIC r0, r1, r2 | bit clear where every `1` in the second operand clears the corresponding bit in the first | r0 = r1 and not r2|

## Register movement operations
- These instructions ignore the first operand, which is omitted from the assembly language format, and simply move the second operand to the destination

| Code       | Description                  | Operation |
| ---------- | ---------------------------- | --------- |
| MOV r0, r2 | move the value from r2 to r0 | r0 = r2   |
| MVN r0, r2 | move negated                 | r0 = not r2          |

## Comparison operations
- These instructions do not produce a result, but just set the condition code bits in the CPSR

| Code       | Description     | Operation           |
| ---------- | --------------- | ------------------- |
| CMP r1, r2 | compare         | set cc on r1 - r2   |
| CMN r1, r2 | compare negated | set cc on r1 + r2   |
| TST r1, r2 | bit test        | set cc on r1 and r2 |
| TEQ r1, r2 | test equal      | set cc on r1 xor r2                    |

```
/* check if number is even */
MOV R0, #12
TST R0, #1 ; if Z is 1 in CPSR, r0 is even
```

```
/* if ((R0 == R1) && (R2 == R3)), do R4++ */

CMP R0, R1
CMPEQ R2, R3
ADDEQ R4, R4, #1
```

## Barrel Shifter
- Operand can be modified before it is used
- Useful for fast multiplication and dealing with lists, tables and other complex data structures
- ARM uses a 32x32 matrix cross bar switch

![[barrelshift.png]]

| Mnemonic | Description            |
| -------- | ---------------------- |
| LSL      | logical shift left     |
| LSR      | logical shift right    |
| ASR      | arithmetic shift right |
| ROR      | rotate right           |
| RRX      | rotate right extended                       |

```
.text
	MOV r0, #2
	MOV r1, r0, lsl#2

	MOV r0, #2
	ADD r3, r0, r0, lsl#2

	MOV r0, #4
	RSB r3, r0, r0, lsl#5

	MOV r0, #128
	MOV r1, r0, lsr#5

	MOV r0, #-128
	MOV r1, r0, asr#5

	MOV r0, #5
	MOV r1, #6
	and r2, r0, r1
	orr r3, r0, r1
	eor r2, r0, r1  ;xor
.end
```

```
MOV r5, #5
MOV r7, #0
MOV r7, r5, LSL #2 ; r7 = r5 * 4
```

- The second operand can be an immediate constant preceded by `#`, a register value or the the value of a register processed by a shift
- Barrel shifter can be used with arithmetic instructions too

### Multiplication using Barrel Shift

| Multiplication by    | Code                                             |
| -------------------- |:------------------------------------------------ |
| `2^n`                | `MOV Ra, Rb, LSL #n`                             |
| `2^n + 1`            | `ADD Ra, Ra, Ra, LSL #n`                         |
| `2^n - 1`            | `RSB Ra, Ra, Ra, LSL #n`                         |
| `6`                  | `ADD Ra, Ra, Ra, LSL #1` `MOV Ra, Ra, LSL #1`    |
| `10 + ` extra number | `ADD Ra, Ra, Ra, LSL#2` `ADD Ra, Rc, Ra, LSL #1` |


```
/* array indedx calculation */
ADD R0, R1, R2, LSL R3    ; R0 = R1 + R2*2^(R3)
```

```
/* fast multiply */
ADD R0, R0, R0, LSL #2    ; R0' = 5xR0
RSB R2, R0, R0, LSL #3    ; R2 = 7xR0'
```

## Multiply operations
- Multiply the contents of a pair of registers and, depending upon the instruction, accumulate the results in with another register
- The long multiply instructions produce a 64-bit result, which is placed in two registers labeled `RdLo` and `RdHi` which hold the lower and upper 32-bits respectively

| Code                     | Description                       | Operation                               |
| ------------------------ | --------------------------------- | --------------------------------------- |
| MLA Rd, Rm, Rs, Rn       | multiply and accumulate           | Rd = (Rm * Rs) + Rn                     |
| MUL Rd, Rm, Rs           | multiply                          | Rd = Rm * Rs                            |
| SMLAL RdLo, RdHi, Rm, Rs | signed multiply accumulate long   | [RdHi, RdLo] = [RdHi, RdLo] + (Rm * Rs) |
| SMULL RdLo, RdHi, Rm, Rs | signed multiply long              | [RdHi, RdLo] = Rm * Rs                  |
| UMLAL RdLo, RdHi, Rm, Rs | unsigned multiply accumulate long | [RdHi, RdLo] = [RdHi, RdLo] + (Rm * Rs) |
| UMULL RdLo, RdHi, Rm, Rs | unsigned multiply long            | [RdHi, RdLo] = Rm * Rs                                        |

```
/*Operation to store 12^3 + 1 in R3*/

MOV R0, #12
MOV R1, #1
MUL R4, R0, R0
MLA R3, R4, R0, R1
```

```
/* 64-bit multiplication */
UMULL R4, R5, R2, R3    ; R5:R4 = R2 * R3
SMLAL R4, R5, R2, R3    ; R5:R4 = (R2 * R3) + R5:R4
```


```
/* Matrix Multiplication */

.data
A: .word 1,3,5
B: .word 2,4,5
C: .word

.text
LDR R5,=A
LDR R6,=B
LDR R7,=C
MOV R3, #3 ;count of numbers
MOV R4, #0

Loop:    
	LDR R1, [R5], #4
	LDR R2, [R6], #4
	MUL R0, R1, R2
	ADD R4, R4, R0
	SUB R3, R3, #1
	TEQ R3, #0 ;test for equality
	BNE Loop
	
STR R4, [R7], #4
SWI 0x11 ;interrupt for termination of program
```
