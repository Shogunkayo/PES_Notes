# Load-Store Instructions
---
- Transfer data between memory and processor registers
- Three types:
	- Single-register transfer
	- Multiple-register transfer
	- Swap

## Single-Register Transfer
- Used for moving a single data item in and out of a register

| Code                 | Descritpion                          | Operation                       |
| -------------------- | ------------------------------------ | ------------------------------- |
| LDR Rd, addressing   | load word into a register            | Rd <- mem32[address]            |
| STR Rd, addressing   | save byte or word from a register    | Rd -> mem32[address]            |
| LDRB Rd, addressing  | load byte into a register            | Rd <- mem8[address]             |
| STRB Rd, addressing  | save byte from a register            | Rd -> mem8[address]             |
| LDRH Rd, addressing  | load halfword into a register        | Rd <- mem16[address]            |
| STRH Rd, addressing  | save halfword into a register        | Rd -> mem16[address]            |
| LDRSB Rd, addressing | load signed byte into a register     | Rd <- SignExtend(mem8[address]) |
| LDRSH                | load signed halfword into a register | Rd <- SignExtend(mem16[address])                                |

```
; load register r0 with the contents of the memory address pointed to by register r1

LDR r0, [r1]    ; = LDR r0, [r1, #0]

; store the contents of register r0 to the memory address pointed to by register r1

STR r0, [r1]    ; = STR r0, [r1, #0]

; Register r1 is called the base address register
```

### Load-Store Addressing Modes
- ARM instruction set provides different modes for addressing memory

| Index method            | Data                | Base address register | Example          |
| ----------------------- | ------------------- | --------------------- | ---------------- |
| Preindex with writeback | mem[base + offset]  | base + offset         | LDR r0 [r1, #4]! |
| Preindex                | mem [base + offset] | not updated           | LDR r0, [r1, #4] |
| Postindex               | mem[base]           | base + offset         | LDR r0, [r1], #4                 |

- `!` indicates that the instruction writes the calculated address back to the base address register
- Preindex with writeback calculates an address from a base register plus address offsett and then updates that address base register with the new address
- Preindex mode does not update the address base register
- Postindex only updates the address base register after the address is used
- Preindex is useful for accessing an element in a data structure. Postindex and preindex with writeback modes are useful for traversing an array
- Offset can be specified by immediate, register or a scaled register `LDR R0, [R1, R2, LSL #2] ; mem[R1 + R2 * 4]`


```
/* pre-indexed addressing */
LDR R0, [R1, R2]    ; R0 = mem[R1+R2], R1 unchanged

/* auto-indexing addressing */
LDR R0, [R1, R2]!   ; R0 = mem[R1+R2], R1 = R1 + R2

/* post-indexed addressing */
LDR R0, [R1], R2    ; R0 = mem[R1], R1=R1+R2
```

```
/* Program to find sum of N numbers using preindexing */

.data
A: .word 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
SUM: .word 0

.text
LDR R1, =A
LDR R2, =SUM
MOV R4, #0
MOV R5, #1

Loop:
	LDR R3, [R1, #4]
	ADD R4, R4, R3
	ADD R1, R1, #4
	ADD R5, R5, #1
	CMP R5, #11
	BNE Loop

STR R4, [R2]
SWI 0x011
```

```
/* Program to find the sum of N numbers using autoindexing */

.data
A: .word 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
SUM: .word 0

.text
LDR R1, =A
LDR R2, =SUM
MOV R4, #0
MOV R5, #1

Loop:
	LDR R3, [R1, #4]!
	ADD R4, R4, R3
	ADD R5, R5, #1
	CMP R5, #11
	BNE Loop

STR R4, [R2]
SWI 0x011
```
- The same works for post-indexing addressing as well, only replace line 102 with `LDR R3, [R1], #4`
- Preindexing and autoindexing skip the first element in the array


![[multrans.png]]![multrans](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/multrans.png)

## Multiple-Register Transfer
- Load-store multiple instructions can transfer multiple registers between memory and the processor in a single instruction
- More efficient than single-register transfers for moving blocks of data around memory
- Increases interrupt latency since it cannot be interrupted. In ARM7, a load mulitple takes `2 + Nt` cycles where `N` is the number of registers to load and `t` is the number of cycles required for each sequential access to memory
- Registers are considered in increasing order always

```
LDMIA R0, {R0, R1, R2}    ; R1 = mem[R0], R2 = mem[R0 + 4], R3 = mem[R0+8] 

LDMIA R0, {R0-R3}          ; same as above

```

| Code | Description             |
| ---- | ----------------------- |
| LDM  | load multiple registers |
| STM  | save multiple registers                        |

| Addressing Mode | Description      | Start Address  | End Address    |
| --------------- | ---------------- | -------------- | -------------- |
| IA              | increment after  | Rn             | Rn + 4 * N - 4 |
| IB              | increment before | Rn + 4         | Rn + 4 * N     |
| DA              | decrement after  | Rn - 4 * N + 4 | Rn             |
| DB              | decrement before | Rn - 4 * N     | Rn - 4               |

```
/* Program to transfer data from memory locations to registers using single load multiple with IA mode */

.data
A: .word 100, 200, 300, 400, 500, 600, 700, 800
B: .word 0, 0, 0, 0, 0, 0, 0, 0

.text
LDR R0, =A
LDR R9, =B
LDMIA R0, {R1-R8}
STMIA R9, {R1-R8}
```
- Same code works for other addressing modes too, only the working is different

## Stack Operations
- The memory can be treated like a stack
- Mainly used in procedural call
- Stack can grow upwards or downwards based on the moded used in the program
- `STM` is used to push to stack, `LDM` is used to pop from stack

Syntax: `<LDM/STM><Addressing Mode> R13 {!}, Registers`

| Addressing Mode       | Equivalent in LDM |
| --------------------- | ----------------- |
| Full ascending `FA`   | LDMDA             |
| Full descending `FD`  | LDMIA             |
| Empty ascending `EA`  | LDMDB             |
| Empty descending `ED` | LDMIB                  |

## Swap
Syntax : `SWP <Swap Destination>, <Original>, [<address>]`
```
.data
a:. word 10

.text
LDR R2, =a
MOV R1, #5
SWP R1, R1, [R2]
```
