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

