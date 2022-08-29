#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

void insert_start(node** n, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = temp;
    temp->prev = temp;

    if(*n == NULL){
        *n = temp;
    }
    else{
        temp->next = (*n)->next;
        (*n)->next->prev = temp;
        (*n)->next = temp;
        temp->prev = (*n);
    }
}

void insert_end(node** n, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = temp;
    temp->prev = temp;

    if(*n == NULL){
        *n = temp;
    }
    else{
        temp->next = (*n)->next;
        (*n)->next->prev = temp;
        (*n)->next = temp;
        temp->prev = (*n);
        (*n) = temp;
    }
}

void insert_pos(node** n, int x, int pos){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = temp;
    temp->prev = temp;

    if(*n == NULL){
        *n = temp;
    }
    else{
        node* present = (*n)->next;

        for(int i=1; i<pos; i++){
            present = present->next;
        }

        temp->prev = present->prev;
        present->prev->next = temp;
        present->prev = temp;
        temp->next = present;
    }

}

void display(node** n){
    node* present = (*n)->next;
    while(present != *n){
        printf("%d ",present->data);
        present = present->next;
    }
    printf("%d\n",present->data);    //To print data of *n
}

void delete_start(node** n){
    if(*n == NULL){
        printf("Empty List\n");
    }
    else{
         node* temp = (*n)->next;
        (*n)->next = temp->next;
        temp->next->prev = (*n);
        free(temp);
    }

}

void delete_end(node** n){
    if(*n == NULL){
        printf("Empty List\n");
    }
    else{
        node* temp = (*n);
        (*n)->prev->next = (*n)->next;
        (*n)->next->prev = (*n)->prev;
        (*n) = (*n)->prev;
        free(temp);
    }
}

void delete_pos(node** n, int pos){
    if(*n == NULL){
        printf("Empty List\n");
    }
    else{
        node* temp = (*n)->next;
        node* previous = (*n);
        for(int i=1; i<pos; i++){
            previous = temp;
            temp = temp->next;
        }
        
        previous->next = temp->next;
        temp->next->prev = previous;
        if(temp == *n){
            *n = previous;
        }
        free(temp);
    }
}

int main(){
    node* last = NULL;
    insert_start(&last, 10);
    insert_start(&last, 20);
    insert_start(&last, 30);
    insert_start(&last, 40);
    insert_end(&last, 50);
    insert_end(&last, 60);
    insert_end(&last, 70);
    insert_end(&last, 80);
    insert_pos(&last, 100, 0);
    display(&last);
    delete_pos(&last, 10);
    display(&last);
}