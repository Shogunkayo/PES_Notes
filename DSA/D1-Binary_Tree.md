# BINARY TREE
---
- Nodes have maximum of 2 child nodes
- A child node cannot have different parents

### Types:
---
1. Full Binary Tree
   - Every node has either 0 or 2 child nodes
2. Perfect Binary Tree 
   - All leaf nodes are at the same level
   - If the depth is `d`, there are `0 to d` levels and `2^(d+1) - 1` total number of nodes
   - The number of leaf nodes is 1 + the number of internal nodes
3. Complete Binary Tree
   - Every level must be completely filled 
   - All leaf elements must lean to the left
   - The last leaf element might not have a right sibling
   - [Binary Heap](https://www.geeksforgeeks.org/binary-heap/) is a practical example
4. Degenerate Tree
   - Every internal node has 1 child 
   - Equivalent to linked lists
   - Traversal is O(n)
5. Skewed Tree
   - Degenerate tree with either left nodes or right nodes
6. [[D3-Expression_Tree | Expression Tree]]


## Binary Search Tree
----
- Binary tree that is either empty or contains nodes which satisfies the following conditions
  - The key in the left child node is lesser than the key in the parent node
  - The key in the right child node is greater than the key in the parent node
  - The right and left subtrees are also binary search trees

### Implementation:
----
#### 1. Array Implementation:
```
int t[100];
for(int i=0; i<100; i++){
	t[i] = -1;
}
```
-> unused nodes are set to -1

##### 1. Insertion
```
void insert(int* t, int x){
    int i=0;
    while(t[i] != -1){
        if(t[i]>x){
            i = i*2 + 1;
        }
        else{
            i = i*2 + 2;
        }
    }
    t[i] = x;
```

##### 2. Traversal
```
void preorder(int* t, int i){
    if(t[i]!=-1){
        printf("%d ",t[i]);
        preorder(t, i*2 + 1);
        preorder(t, i*2 + 2);
    }
}
```

```
void inorder(int* t, int i){
    if(t[i]!=-1){
        inorder(t, i*2 + 1);
        printf("%d ",t[i]);
        inorder(t, i*2 + 2);
    }
}
```

```
void postorder(int* t, int i){
    if(t[i]!=-1){
        postorder(t, i*2 + 1);
        postorder(t, i*2 + 2);
        printf("%d ",t[i]);
    }
}
```

#### 2. [[D2-Linked_List_Implementation || Linked List Implementation]]

