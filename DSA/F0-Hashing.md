# HASHING
---
- Process of maping keys and values into a hash table using a hashing function
- Usually represented by a smaller key, such that the original key is easier to find
- A hash function is a function which maps key value into a hash table range. It usually involves folding, truncation and modulo operations

## Collision
- Since a hash function gets us a small number for a key which is a big integer or string, there is a possibility that two keys result in the same value
- Handled using some collision resolution technique

### 1.  Open Addressing (Closed Hashing)
- Handles collisions by storing all data in the hash table
- Seeks out availability in the next spot created by the algorithm
- The size of the table must be greater than the total number of keys
- [[F2-Linear_Probing]]
- [[F3-Double_Hashing]]

### 2. Seperate Chaining(Open Hashing) 
- Handles collisions by making every hash table cell point to linked lists of records with identical hash function values
- [[F1-Seperate_Chaining]]

### 3. Rehashing 
- Increases the table size when the load factor becomes more than a predefined value 
`Load Factor = No of filled records / Total capacity`
- Hashes all the keys again and stores it in the new table