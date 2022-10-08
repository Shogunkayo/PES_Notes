# PRIORITY QUEUE
---
- Heap allows an efficient implementation of a priority queue - O(log n) for most operations
- This page contains only the implementation using a heap, for more details about priority queue please visit [[C5-Priority_Queue]]

```
void heapify(element* q, int i){
    element temp;
    while(i > 0 && q[i].priority > q[(i-1)/2].priority){
        temp = q[i];
        q[i] = q[(i-1)/2];
        q[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void enqueue(element* q, int* count, int x, int priority){
    q[++(*count)].data = x;
    q[(*count)].priority = priority;
    heapify(q, *count);
}

void display(element* q, int count){
    for(int i=0; i<=count; i++){
        printf("%d\n", q[i].data);
    }
    printf("\n");
}

void dequeue(element* q, int* count){   
    q[0] = q[(*count)--];
    for(int i=1; i<=*count; i++){
        heapify(q, i);
    }
}
```