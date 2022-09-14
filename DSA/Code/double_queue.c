#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}node;

typedef struct Deque{
    node* front;
    node* rear;
}deque;

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

void display(deque* dq){
    node* temp = dq->front;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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

int main(){
    deque dq;
    dq.front = NULL;
    dq.rear = NULL;
    insert_front(&dq, 10);
    insert_front(&dq, 20);
    insert_front(&dq, 30);
    insert_last(&dq, 100);
    insert_last(&dq, 200);
    insert_front(&dq, 1000);
    display(&dq);
    delete_front(&dq);
    delete_front(&dq);
    display(&dq);
    delete_rear(&dq);
    delete_rear(&dq);
    delete_rear(&dq);
    display(&dq);
    delete_rear(&dq);
    display(&dq);
    delete_front(&dq);
    delete_rear(&dq);
    delete_rear(&dq);
    delete_front(&dq);
    insert_last(&dq, 100);
    insert_last(&dq, 200);
    insert_front(&dq, 1000);
    display(&dq);
}