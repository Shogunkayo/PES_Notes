# HEAP
----
- Complete binary tree
- 2 types
  1. Max Heap - descending tree
  2. Min Heap - ascending tree

- 2 approaches to construct a binary heap
  1. Top Down Approach
  2. Bottom Up Approach

- Typically represented by arrays
```
Arr[(i-1)/2]	Returns the parent node
Arr[(2*i)+1]	Returns the left child node
Arr[(2*i)+2]	Returns the right child node
```

### Implementation:

-> Heapify operation - Converts a binary tree into a heap
```
void heapify(int* h, int n){
    int i, j, k, key;
    for(k=1; k<n; k++){
        i = k;
        key = h[i];
        j = (i-1)/2;
        while(i>0 && key>h[j]){
            h[i] = h[j];
            i = j;
            j=(i-1)/2;
        }
        h[i] = key;
    }
}
```


### Deletion of a node:
- The standard delete operation is to delete the element present at the root node of the heap
- Deleting an element at any intermediary position in a heap can be costly
- So replace the element to be deleted by the last node and delete the last node of the heap
- Perform `heapify` operation to ensure it remains as a max heap or min heap

### Applications:
1. Heap Sort - sort an array in O(n log n) time
2. [[D6-Priority_Queue_Heap|Priority Queue]] - supports insert, delete extractmax and decreasekey methods in O(log n) time
3. Graph algorithms like Dijkstra's shortest path and Prim's minimum spanning trees