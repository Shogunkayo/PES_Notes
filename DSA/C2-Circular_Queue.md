# CIRCULAR QUEUE
---
- In a regular queue, elements cannot be inserted when a queue is full, even if some elements are deleted afterwards
- A circular queue is used  to overcome this drawback

## Operations
#### 1. Insert
```
void enqueue(int* q, int* f, int* r, int size, int x){
    if((*r)+ 1 %size == *f){
        printf("Queue is full\n");
    }
    else{
        *r = (*r)+1 % size;
        q[*r] = x;
        if(*f == -1){
            *f = 0;
        }
    }
}

```

#### 2. Display
```
void display(int* q, int f, int r, int size){
    if(f == -1){
        printf("Queue is empty\n");
    }
    else{
        while(f != r){
            printf("%d ",q[f]);
            f = (f+1)%size;
        }
        printf("%d\n",q[f]);
    }
}
```

#### 3. Delete
```
int dequeue(int* q, int* f, int* r, int size){
    if(*f == -1){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        int x = q[*f];
        if(*f == *r){
            *f = *r = -1;
        }
        else{
            *f = (*f)+1 %size;
        }
        return x;
    }
}
```

## Applications
1. Memory Management
2. Traffic System
3. CPU Scheduling

## Questions
>Implement enqueue and dequeue operations of a circular queue using an array Q of size n. Assume f is front and r is the next available cell in the array

> Write a method called 'alternate_split' to split an integer queue into two queues which contains alternate elements of the original queue. Use only queue methods that are usually defined in the queue ADT (enqueue, dequeue). For example, if the original queue has {1,2,3,4,5}, then Q1 = {1,3,5} and Q2 = (2,4). You do not have to write enqueue and dequeue methods
