# DOUBLE HASHING
---
- Double hashing uses the idea of applying a second hash function to key when a collision occurs

`hash(new) = (hash1(key) + i * hash2(key)) % table_size`

- The first hash function is typically `hash1(key) = key % table_size`
- The second hash function is usually `hash2(key) = prime - (key % prime)` where `prime` is a prime number smaller than the table size
- The second hash function must ensure that
  - It must never evaluate to zero
  - Make sure all the cells can be probed

### Advantages
- Produces a uniform distribution of records throughout a hash table
- Does not yield any clusters
- Effective method for resolving collisions 

### Implementation
