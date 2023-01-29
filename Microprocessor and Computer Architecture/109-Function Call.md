# Function Call
--- 
- `BL` instruction can be used to store the current value of `R15(PC)` in a register before the branch is taken, so that the program can resume its operation
- ARM has no dedicated stack. Advantage => subroutines which don't need to save can be called to return very quickly. Disadvantage => all other routines have the overhead of explicitly saving to R14
- To return from a subroutine, the program simply has to move `R14` back into `R15`: `MOV R15, R14` or `MOV PC, LR`

```
MOV R1, #3
BL Foo
ADD R2, R0, R1
SWI 0x11

Foo:
	MOV R0, #2
	MOV PC, LR
```

```
/* Parameter passing using stack */

.data
A: .word 0

.text
LDR R6, =A
MOV R1, #25         ; parameter 1
MOV R2, #25         ; parameter 2
STMFD R13!, {R1, R2}; parameters are pushed on stack
BL Link
STR R0, [R6]        ; store result
SWI 0x11

Link:
	LDMFD R13!, {R4, R5} ;parameters are popped from the stack
	ADD R0, R4, R5
	MOV PC, LR
```

```
/* Nested Procedure Call: Multiply(Add(a,b), c) */

.data
A: .word 0

.text
LDR R4, =A

MOV R1, #11
MOV R2, #10
MOV R3, #02
STMFD R13!, {R1-R3}

BL AddFunc        ; call to AddFunc
STR R0, [R4]
SWI 0x11

AddFunc:
	LDMFD R13!, {R5-R7}
	ADD R0, R5, R6
	STMFD R13!, {R0, R6, LR}
	BL MulFunc    ; call to MulFunc
	MOV PC, LR    ; return to main procecdure

MulFunc:
	LDMFD R13!, {R4, R5, LR}
	MUL R0, R4, R5
	MOV PC, LR    ; return to AddFunc

```