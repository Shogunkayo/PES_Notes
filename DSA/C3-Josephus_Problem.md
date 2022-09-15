# JOSEPHUS PROBLEM USING CIRCULAR QUEUE
---

## Problem Statement:
>There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of person n and a number k which indicates that k-1 persons are skipped and the kth person is killed in a circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.

## Code:
```
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int position;
    struct Node* link;
}node;

void insert(node** n, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->position = x;
    temp->link = temp;

    if(*n == NULL){
        *n = temp;
    }
    else{
        temp->link = (*n)->link;
        (*n)->link = temp;
    }
}

int josephus(node** n, int k){
    node* present = (*n)->link;
    node* previous = *n;
    int i=1;
    while(present->link != present){
        if(i%k == 0){
            previous->link = present->link;
            free(present);
            present = previous->link;
        }
        else{
            previous = present;
            present = present->link;
        }
        i++;
    }
    return present->position;
}

int main(){
    node* head = NULL;
    int n=10, k=4;
    for(int i=n; i>0; i--){
        insert(&head, i);
    }
    printf("%d\n",josephus(&head,k));
}
```
