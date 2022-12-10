# MULTILIST
----

> What is a multilist data structure? Can we call a doubly linked list as a multilist? Mention the applications of a multilist data structure.
- A multilist is a special type of linked list where each node contains two or more pointers
- Doubly linked lists are a special case of Multi-linked lists. It is special in two ways:
    - Each node has just 2 pointers.
    - The pointers are exact inverses of each other.
- Multilist can be used to represent list of lists
```
typedef struct node{
    int data;
    struct node* col;
    struct node* next;
}node;
```
![list_of_lists](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/multilist1.jpg?raw=true)


- Multilist can be used to represent multple orders of a set
 
 ![set](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/multilist2.jpg?raw=true)
- Another application of multilist is a sparse matrix



# SPARSE MATRIX
----

- A matrix with most of the elements 0
- As there are less non zero elements, memory needed to store them is less
- Computing time can be saved by logically designing a data structure traversing only non-zero elements


## [Representations](https://www.geeksforgeeks.org/sparse-matrix-representation/)
- If a sparse matrix is stored as a 2 dimensional matrix, it wastes a lot of space
- Alternate representations - 

### 1. Triple notation - Array representation
- Sparse matrix is represented as an array of tuples
- Each tuple consists of row number, column number and value

![sparse_matrix](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/sparse_matrix.png?raw=true)

```
typedef struct sparse{
    int col;
    int row;
    int data;
}term;
```

### 2. Linked List representation
- Two types of nodes are used - header node and data node
- Header node consists of pointers to next, down and right
- Data node consists of row number, column number, value and the pointers to down and right



