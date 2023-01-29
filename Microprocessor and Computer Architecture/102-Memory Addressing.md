# Memory Addressing
---
There are two different conventions for ordering the bytes within a larger object. Little Endian byte order puts the byte whose address is `x.....x000` at the least-significat position in the double word. The bytes are numbered as `7 6 5 4 3 2 1 0`. Big Endian byte order puts the byte whose address is `x......x000` at the most significant position in the double word. The bytes are numbered `0 1 2 3 4 5 6 7`

- Byte order is a problem when exchanging data among computers with different orderings
- Little Endian ordering also fails to match the normal ordering of words when strings are compared. Strings appear backwards in the registers like `SDRAWKCAB`
- Accesses to objects larger than a byte must be aligned. An access to an object of size `s` bytes at byte address `A` is aligned if `A mod s = 0`. Programs with aligned accesses run faster in computers that allow misaligned access

![[memaddr.png]]![memaddr](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/memaddr.png)

## Addressing Modes
- Addressing modes specify constants and registers in addition to locations in memory
- When a memory location is used, the actual memory address specified by the addressing mode is called the effective address
- Below figure shows all the data addressing modes that have been used in recent computers
![[addrmode.png]]![addrmode](https://github.com/Shogunkayo/PES_Notes/blob/main/Microprocessor%20and%20Computer%20Architecture/Images/addrmode.png)
- Displacement, immediate and register indirect are the most popular addressing modes (75% to 99%)
- Size of immediate field should be atleast 8 to 16 bits
- Size of the address for displacement mode should be atleast 12 to 16 bits
