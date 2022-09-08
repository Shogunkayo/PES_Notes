#include<stdio.h>
#include<stdlib.h>

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

void display(int* q, int* f, int* r){
    if(*f == -1){
        printf("Queue Underflow\n");
    }
    for(int i=*f; i <= *r; i++){
        printf("%d ",q[i]);
    }
    printf("\n");
}

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

int main(){
    int f=-1, r=-1;
    int size = 4;
    int* q = (int*)malloc(sizeof(int));

    enqueue(q,&f,&r,size,10);
    enqueue(q,&f,&r,size,20);
    enqueue(q,&f,&r,size,30);
    enqueue(q,&f,&r,size,40);
    display(q,&f,&r);
}