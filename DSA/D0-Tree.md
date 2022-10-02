 
 # TREE
---
- Non-linear and heirarchical data structure consisting of a collection of nodes such that each node stores a value and a set of references to the other nodes
![[tree.png]]

- Data is not in a sequential manner

| Terminology   | Meaning                                                  |
| ------------- | -------------------------------------------------------- |
| Parent node   | The predecessor node                                     |
| Child node    | The immediate successor node                             |
| Root node     | Topmost node of a tree which does not have a parent node |
| Leaf node     | Node which does not have a child node                    |
| Ancestor      | Any predecessor node on the path to the root node        |
| Descendant    | Any node on the path towards the leaf node               |
| Sibling       | Nodes of the same parent node                            |
| Internal node | A node with atleast one child                            |
| Subtree       | Any node of the tree along with its descendants          |

### Properties:
---
- If a tree has `n` nodes, it will have `n-1`edges. There is only one path from one node to another
- Depth of a node is the number of edges in the path from the root node to that particular node
- Height of a node is the length of the longest path from that node to a leaf node
- Height of a tree is the length of the longest path from the root node to a leaf node
- The total number of subtrees attached to a node is the degree of the node. The degree of a leaf node must be 0,  and the degree of the tree is maximum degree of a node
- Traversing is done by breadth-first and depth-first

### Implementation:
----
```
struct Node
{
   int data;
   struct Node *left_child;
   struct Node *right_child;
};
```

### ADT for Tree:
----

| Function                   | Function Name |
| -------------------------- | ------------- |
| Create a tree              | create        |
| Insert data in a tree      | insert        |
| Search for a specific data | search        |

There are 3 types of traversal in a tree-
1. Pre-order traversal 
   - root -> left -> right                                             
2. Post-order traversal
   - left-> right-> root
3. In-order traversal
   - left-> root -> right
   - In-orded for a binary search tree always gives data in ascending order

### Types:
---
1. General tree
   - No restriction on the number of nodes
2. Binary tree [[D1-Binary_Tree]]
   - A node can have maximum of two child nodes
3. Balanced tree
   - Heigth of the left subtree and right subtree are equal or differ by 1
   - Traversal is O(log n)

### Applications:
----
- Spanning trees which are the shortest path used in routers to direct packets
- Binary search tree which is used in searching and sorting algorithms
- Storing hierarchical data
- Synatx tree represents structure of a program and is sued in compilers
- Trie(prefix tree) is fast and efficient for dynamic spell checking
- Heap is also a tree data structure, used to implement priority queues