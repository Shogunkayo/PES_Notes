# LINEAR PROBING
---
- The hash table is searched sequentially that starts from the original location of the hash. If in case the location that we get is already occupied, we check for the next available location.
`hash(key) = (hash(key) + i) % table_size` where `i = 0,1,2,3....`
