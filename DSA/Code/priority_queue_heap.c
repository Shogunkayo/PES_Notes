#include<stdio.h>

typedef struct Element{
    int data;
    int priority;
}element;

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

int main(){
    element queue[100];
    int count = -1;
    enqueue(queue, &count, 10, 4);
    enqueue(queue, &count, 20, 2);
    enqueue(queue, &count, 30, 1);
    enqueue(queue, &count, 40, 3);
    enqueue(queue, &count, 50, 5);
    display(queue,count);
    dequeue(queue, &count);
    display(queue,count);
    dequeue(queue, &count);
    display(queue,count);
}