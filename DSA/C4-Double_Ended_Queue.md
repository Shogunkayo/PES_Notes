# DOUBLE ENDED QUEUE
---
- Type of queue that allows insertion and deletion at both ends
- Does not follow FIFO
- Also called "Deque"

- Supports both stack and queue operations
- Supports clockwise and anti-clockwise rotations in constant time 

## Applications
- 

## ADT
- insert_head
- insert_tail
- delete_head
- delete_tail
- isEmpty
- isFull
- return_front
- return_rear

## Implementation
```
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}node;

typedef struct Deque{
    node* front;
    node* rear;
}deque;
```

## Basic Operations

#### 1. Insert
```
void insert_front(deque* dq, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;

    if(dq->front == NULL){
        dq->front = temp;
        dq->rear = temp;
    }
    else{
        temp->next = dq->front;
        dq->front->prev = temp;
        dq->front = temp;
    }
}
```

```
void insert_last(deque* dq, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    if(dq->front == NULL){
        dq->front = temp;
        dq->rear = temp;
    }
    else{
        dq->rear->next = temp;
        temp->prev = dq->rear;
        dq->rear = temp;
    }
}
```

#### 2. Display
```
void display(deque* dq){
    node* temp = dq->front;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
```

#### 3. Delete
```
void delete_front(deque* dq){
    if(dq->front == NULL){
        printf("Empty Queue\n");
    }
    else{
        node* temp = dq->front;
        dq->front = dq->front->next;
        // Condition to catch last remaining node 
        if(dq->front != NULL){
            dq->front->prev = NULL;
        }
        else{
            dq->front = NULL;
            dq->rear = NULL;
        }
        free(temp);
    }
}
```

```
void delete_rear(deque* dq){
    if(dq->front == NULL){
        printf("Empty Queue\n");
    }
    else{
        node* temp = dq->rear;
        dq->rear = dq->rear->prev;
        if(dq->rear != NULL){
            dq->rear->next = NULL;
        }
        else{
            dq->front = NULL;
            dq->rear = NULL;
        }
        free(temp);
    }
}
```


