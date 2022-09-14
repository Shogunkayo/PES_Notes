# PRIORITY QUEUE
---

>Priority Queue is an abstract data type that is similar to a queue, and every element has some priority value associated with it. The priority of the elements in a priority queue determines the order in which elements are served (i.e., the order in which they are removed). If in any case the elements have same priority, they are served as per their ordering in the queue.

## Applications
1. Dijskstra’s shortest path algorithm
2. Prims algorithm
3. Artificial Intelligence - search algorithm
4. Data compression in Huffman code

## Implementation
### 1. Using Arrays
```
typedef struct priority_queue{
    int data;
    int priority;
}queue;

void insert(queue *pq, int* count, int x, int p){
    int j = *count - 1;
    queue temp;
    temp.data = x;
    temp.priority = p;

    while(j>=0 && pq[j].priority > temp.priority){
        pq[j+1] = pq[j];
        j--;
    }

    pq[j+1] = temp;
    (*count)++;
}

void display(queue *pq, int count){
    if(count){
        for(int i=0; i<count; i++){
            printf("Data:%d Priority:%d\n",pq[i].data,pq[i].priority);
        }
    }
    else{
        printf("Empty Queue\n");
    }
}

queue delete(queue *pq, int* count){
    queue temp;
    if(count == 0){
        temp.data = 0;
        temp.priority = -1;
    }
    else{
        temp = pq[0];
        for(int j=1; j<*count; j++){
            pq[j-1] = pq[j];
        }
        (*count)--;
    }
    return temp;
}
```

*Above implementation has insert method in O(n). It has been improved to O(1) in the below code. Delete method always has O(n) complexity*

```
void insert(queue *pq, int* count, int x, int p){
    pq[++(*count)].data = x;
    pq[(*count)].priority = p;
}

void display(queue *pq, int count){
    if(count > -1){
        for(int i=0; i<count+1; i++){
            printf("Data:%d Priority:%d\n",pq[i].data,pq[i].priority);
        }
    }
    else{
        printf("Empty Queue\n");
    }
}

int max_priority(queue *pq, int count){
    int max = -1;
    for(int i=0; i<count+1; i++){
        if(pq[i].priority > max){
            max = pq[i].priority;
        }
    }
    
    // +1 to take care of deleting the highest priority node
    return max+1;
}

void delete(queue *pq, int* count){
    if(*count == -1){
        printf("Empty Queue\n");
    }
    else{
        queue temp;
        temp.priority = max_priority(pq, *count);
        int index = -1;

        for(int i=0; i<*count+1; i++){
            if(pq[i].priority < temp.priority){
                temp = pq[i];
                index = i;
            }
        }
        
        for(int i=index; i<*count; i++){
            pq[i] = pq[i+1];
        }

        (*count)--;
    }
}
```
