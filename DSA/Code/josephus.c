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