# Barrel Shift Register
---
- Shift or rotate operations
	- Shift Left: One left shift diagonal line is turned on : `LSL`
	- Shift Right: One right shift diagonal line is turned on : `LSR`
	- Arithmetic Shift Right: Uses sign extension rather than zero filling for unconnected output : `ASR`
	- Rotation Operations: `RSL` and `RSR`

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

## Multiplication using Barrel Shift

| Multiplication by    | Code                                             |
| -------------------- |:------------------------------------------------ |
| `2^n`                | `MOV Ra, Rb, LSL #n`                             |
| `2^n + 1`            | `ADD Ra, Ra, Ra, LSL #n`                         |
| `2^n - 1`            | `RSB Ra, Ra, Ra, LSL #n`                         |
| `6`                  | `ADD Ra, Ra, Ra, LSL #1` `MOV Ra, Ra, LSL #1`    |
| `10 + ` extra number | `ADD Ra, Ra, Ra, LSL#2` `ADD Ra, Rc, Ra, LSL #1` |

```
.text
	;Multiplication by 2^n
	MOV r1, #2
	MOV r2, #3
	MOV r0, r2, LSL #3

	ADD r0, r1, r1, LSL #2

	;Multiplication by 6
	ADD r0, r1, r1, LSL #1
	MOV r0, r1, LSL #1

	;Multiplication by 6 and add in extra number
	ADD r0, r1, r2, LSL #1
	ADD r0, r1, r2, LSL #1

	;Rotate right
	MOV r2, #0x0000031 ; 49
	MOV r0, r2, ROR #2
.end
```

Questions: 
1. Convert to ARM
	1. A = B + C
	2. D = A - C
	3. D = A - C using RSB instruction
2. F = (G + H) - (I + J) using registers R0 to R4 as operands F to J respectively
3. G = H + A\[10\]
