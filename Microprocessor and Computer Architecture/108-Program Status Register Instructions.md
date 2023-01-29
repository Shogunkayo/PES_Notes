# Program Status Register Instructions
---
- ARM instruction set provides two instructions to directly control a program status register `psr`
- The `MRS` instruction transfers the contents of either the `cpsr` or `spsr` into a register or vice versa
![[psr.png]]
- `fields` can be any combination of control `c` , extension `x`, status `s` and flags `f`
![[psr2.png]]

```
/* Move to register from status register */
MRS R0, CPSR
MRS R1, SPSR

/* Move to status register from register */
MSR CPSR_field, R0
MSR SPSR_field, R1
```

```
.text
MOVS R1, #-10
MRS R0, CPSR     ; take a copy of the CPSR
AND R0, R0, #0000; clear the mode bits
MSR CPSR_F, R0   ; write back the modified CPSR
```