# Segmentation
---
- Memory can be viewed as a collection of variable sized segments, with no necessary ordering among the segments
  - Segmentation is a memory management scheme that supports this view of memory. 
  - A logical address is a collection of segments. Each segment has a name and a length. The address specify both the segment name and the offset within the segment
  - The programmer specifies each address by two quantities: a segment name and an offset. For simplicity of implementation, segments are numbered and are referred to by a segment number rather than by a segment name.
  - Logical address consists of a two tuple: `<segment-number, offset>`
  - Libraries that are linked in during compile time might be assigned seperate segments. The loader would take all

## Segmentation Hardware
- Although a programmer can now refer to objects in the program by a two dimensional address, the actual physical memory is still a one dimensional sequence of bytes
- The mapping is effected by a segment table
- Each entry in the segment table has a segment base and a segment limit. The segment base contains the starting physical address where the segment resides in memory, and the segment limit specifies the length of the segment

![[segmenttable.png]]

![segmenttable](https://github.com/Shogunkayo/PES_Notes/blob/main/Operating%20Systems/images/segmenttable.png)

- Logical address consists of two parts: a segment number `s` and an offset into that segment `d`
- The segment number is used as an index to the segment table
- The offset must be between 0 and the segment limit. 
- When the offset is legal, it is added to the segment base to produce the address in physical memory of the desired byte
- If it is illegal, it will result in a trap to the operating system