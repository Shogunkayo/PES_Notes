# SEPERATE CHAINING
---
- A linked list is used to implement this technique
- When multiple elements are hashed into the same index, the elements are inserted into a singly linked list to form a chain

![[seperate_chaining.png]]

### Advantages
- Simple to implement
- Hash table never fills up 
- Less sensitive to the hash function 
- Usually used when the number of elements to be inserted is not known

### Disadvantages
- Cache performance is not good compared to open addressing
- Wastage of space as some parts of the table are never used
- If the chain becomes long, search time can become linear in the worst case
- Extra space is needed for the links
