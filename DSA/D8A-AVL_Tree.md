# AVL TREE
---
- Self balancing binary search tree where the difference of heights of the left and the right subtrees cannot be more than one for all nodes
- The height of a `n` node avl tree is always `log(n)`

> Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take **O(h)** time where **h** is the height of the BST. The cost of these operations may become **O(n)** for a **skewed Binary tree**. If we make sure that the height of the tree remains **O(log(n))** after every insertion and deletion, then we can guarantee an upper bound of **O(log(n))** for all these operations. 

## Insertion
- To maintain the property of AVL trees after every insertion, the tree is rebalanced by performing 
1. Left rotation:
   - ![left_rotation.png](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/left_rotation.png)
2. Right rotation
   - ![right_rotation.png](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/right_rotation.png)
- The tree can be rotated any number of times 

- Common combinations of rotations:
1. Left-Right rotation
- ![lr1.png](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/lr1.png)
- ![[lr2.png]](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/lr2.png)
2. Right-Left rotation
- ![rl1.png](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/rl1.png)
- ![[rl2.png]](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/rl2.png)

### Algorithm
1. Insert an element as you would for a binary search tree
2. Check the balance factor(difference of nodes in left and right sub tree)
3. If the balance factor of every node is less than or equal to 1, proceed
4. Else perform suitable rotation operations

## Deletion
- Deleting a node might cause an imbalance in the height of the tree

### Algorithm
1. Delete an element as you would for a binary search tree
2. Check the balance factor
3. If the balance factor of every node is less than or equal to 1, proceed
4. Else, if `balance factor > 1` refer the **left subtree** . Otherwise refer the **right subtree**

| Balance Factor of Tree | Balance  Factor of Subtree | Operation                                                                               |
| ---------------------- | -------------------------- | --------------------------------------------------------------------------------------- |
| greater than 1         | greater than 0             | left-left case: perform right rotation                                                  |
|                        | equal to 0                 | left-left case: perform right rotaion **OR** left-right case: perform left-right rotation   |
| lesser than -1         | lesser than 0              | right-right case: perform left rotation                                                 |
|                        | equal to 0                 | right-right case: perform left rotation **OR** right-left case: perform right-left rotation | 

