# BAYER'S TREE
---
- Special tree where a node can have more than one key and any number of children
- Stores data in a sorted order
- Also called as B Tree , Balanced M-way Search Tree and K way tree                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        

## Properties
- A tree of order `n` can have a maximum of `n` children
- Every node except root node should contain a minimum of `(n/2) - 1`  and a maximum `n-1` keys
- Root node should have a minimum of 1 key
- All the non leaf nodes must have `(n/2)` keys
- All the keys must be in sorted increasing order
- The tree grows and shrinks from the leaf node
- If the root is a non leaf, then it must have atleast two children
- Minimum height of a B tree with `N` nodes is `log{base n}(N+1) -1`
- 
## Advantages
- Reduces number of reads made on a disk
- Can be easily optimized according to the disk size
- Specially designed to handle bulky amout of data
- Useful algorithm for databases and file systems

## Insertion 
### Algorithm
1. Travers the B-Tree to find the appropriate leaf node
2. If the tree contains `n-1` keys, insert the element in increasing order
3. Else, 
   1. Insert the new element in increasing order 
   2. Split the node into two at the median 
   3. Push the median element to the parent node
   4. Repeat the above procedure if the parent node also contains `n-1` keys
 
