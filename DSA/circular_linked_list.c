#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node;


//--------------- BASIC OPERATIONS

void insert_start(node** n, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = temp;

    if(*n == NULL){
        *n = temp;
    }
    else{
        temp->link = (*n)->link;
        (*n)->link = temp;
    }
}

void insert_end(node** n, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = temp;

    if(*n == NULL){
        *n = temp;
    }
    else{
        temp->link = (*n)->link;
        (*n)->link = temp;
        *n = temp;
    }
}

void insert_pos(node** n, int x, int pos){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = temp;

    if(*n == NULL){
        *n = temp;
    }
    else{
        int i;
        node* present = (*n);
        for(i=1; i<pos; i++){
            present = present->link;
        }

        temp->link = present->link;
        present->link = temp;
    }
}

void display(node** n){
    if(*n == NULL){
        printf("Empty List");
    }
    else{
        node* present = (*n)->link;
        while(present != *n){
            printf("%d ",present->data);
            present = present->link;
        }
        printf("%d ",present->data);
    }
    printf("\n");
}   

void delete_start(node** n){
    if(*n == NULL){
        printf("Empty List \n");
    }
    else{
        node* temp = (*n)->link;
        (*n)->link = temp->link;
        free(temp);
    }
}

void delete_end(node** n){
    if(*n == NULL){
        printf("Empty List\n");
    }
    else{
        node* temp = (*n)->link;
        while(temp->link != *n){
            temp = temp->link;
        }
        temp->link = (*n)->link;
        free(*n);
        *n = temp;
    }
}

void delete_pos(node** n, int pos){
    if(*n == NULL){
        printf("Empty List\n");
    }
    else{
        node* present = (*n)->link;
        node* previous = (*n);
        for(int i=1; i<pos; i++){
            previous = present;
            present = present->link;
        }
        previous->link = present->link;
        if(present == *n){
            *n = previous;
        }
        free(present);
    }
}


//--------------- ORDERED LIST

void insert_ordered(node** n, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = temp;

    if(*n == NULL){
        *n = temp;
    }
    else if((*n)->link == (*n)){
        temp->link = (*n);
        (*n)->link = temp;
        if(temp->data > (*n)->data){
            (*n) = temp;
        }
    }
    else{
        node* present = (*n)->link;
        node* previous = *n;
        while(present != *n && present->data < x){
            previous = present;
            present = present->link;
        }
        if(present == *n){
            temp->link = (*n)->link;
            (*n)->link = temp;
            *n = temp;
        }
        else{
            previous->link = temp;
            temp->link = present;
        }
    }
}

/*
int main(){
    node* tail = NULL;
    insert_ordered(&tail, 30);
    insert_ordered(&tail, 20);
    insert_ordered(&tail, 10);
    insert_ordered(&tail, 40);
    display(&tail);
}
*/


//--------------- CIRCULAR LINKED LIST USING HEAD

node* create_header(){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = 0;
    temp->link = temp;
    return temp;
}

void insert_start_header(node* n, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = NULL;

    temp->link = n->link;
    n->link = temp;
    n->data++;
}

void insert_end_header(node* n, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = temp;

    node* present = n->link;
    while(present->link != n){
        present = present->link;
    }
    present->link = temp;
    temp->link = n;
    n->data++;
}

void display_header(node* n){
    node* present = n->link;
    
    while(present != n){
        printf("%d ",present->data);
        present = present->link;
    }
    printf("Number of nodes: %d\n",n->data);
}

void delete_value_header(node* n, int x){
    if(n->link == n){
        printf("No nodes in list\n");
    }
    else{
        node* present = n->link;
        node* previous = n;
        int found = 0;
        
        while(present != n){
            if(present->data == x){
                found = 1;
                previous->link = present->link;
                free(present);
                n->data--;
                break;
            }
            previous = present;
            present = present->link;
        }

        if(!found){
            printf("Node not found\n");
        }
    }
}

int main(){
    node* head = create_header();
    insert_start_header(head, 10);
    insert_start_header(head, 20);
    insert_start_header(head, 30);
    insert_start_header(head, 40);
    insert_end_header(head, 50);
    display_header(head);
    delete_value_header(head, 0);
    display_header(head);
}
