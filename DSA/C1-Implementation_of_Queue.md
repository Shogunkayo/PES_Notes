# IMPLEMENTATION OF QUEUE
---

## Using Arrays
#### 1. Insert
```
void enqueue(int* q, int* f, int* r, int size, int x){
    if(*r == size-1){
        printf("Queue Overflow\n");
    }
    else{
        q[++(*r)] = x;
    }
    if(*f == -1){
        *f=0;
    }
}
```

#### 2. Display
```
void display(int* q, int* f, int* r){
    if(*f == -1){
        printf("Queue Underflow\n");
    }
    for(int i=*f; i <= *r; i++){
        printf("%d ",q[i]);
    }
    printf("\n");
}
```

#### 3. Delete
```
int dequeue(int* q, int* f, int* r){
    if(*f == -1){
        printf("Queue Underflow\n");
        return -1;
    }
    else{
        int x = q[*f];
        if(*f == *r){
            f = r = -1;
        }
        else{
            (*f++);
        }
        return x;
    }
}
```


## Using Linked Lists
- Two pointers are used : one pointer at the front and another at the rear

#### 1. Insert
```
void enqueue(node** f, node** r, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;

    if(*f == NULL){
        *f = *r = temp;
    }
    else{
        (*r)->next = temp;
        (*r) = temp;
    }
}
```

#### 2. Display
```
void display(node** f, node** r){
    node* q = *f;
    if(q==NULL){
        printf("Queue is empty\n");
    }
    else{
        while(q != *r){
            printf("%d ",q->data);
        }
        printf("%d\n",q->data);
    }
}
```

#### 3. Delete
```
void dequeue(node** f, node** r){
    node* temp = *f;
    if(temp == NULL){
        printf("Queue is empty\n");
    }
    else{
        *f = (*f)->next;
        free(temp);
    }
}
```

## Questions
>Write a program to implement stack using queues.

> Write a program to implement queue using stacks.

