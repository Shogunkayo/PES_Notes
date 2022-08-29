#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;

void insert_start(node** n, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    if((*n) == NULL){
        (*n) = temp;
    }
    else{
        temp->next = (*n);
        (*n)->prev = temp;
        (*n) = temp;
    }
}

void insert_end(node** n, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    if((*n) == NULL){
        (*n) = temp;
    }
    else{
        node* present = (*n);
        while(present->next != NULL){
            present = present->next;
        }
        present->next = temp;
        temp->prev = present;
    }
}

void insert_pos(node** n, int x, int pos){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;

    
    if((*n) == NULL){
        (*n) = temp;
    }
    else{
        int valid = 1;
        int i;
        node* present = (*n);
        
        for(i=1; i<pos; i++){
            present = present->next;
            if(present == NULL){
                valid = 0;
                break;
            }
        }

        if(valid){
            if(present->prev == NULL){
                temp->next = (*n);
                temp->next->prev = temp;
                (*n) = temp;
            }
            else{
                temp->next = present;
                temp->prev = present->prev;
                present->prev->next = temp;
                present->prev = temp;
            }
        }
        else if(pos-i == 1){
            node* present = (*n);
            while(present->next != NULL){
                present = present->next;
            }
            present->next = temp;
            temp->prev = present;
        }
        else{
            printf("Invalid position\n");
        }
    }
}

void display(node** n){
    node* present = (*n);
    while(present != NULL){
        printf("%d ",present->data);
        present = present->next;
    }
    printf("\n");
}

void delete_start(node** n){
    if((*n) == NULL){
        printf("Empty List\n");
    }
    else if((*n)->next == NULL){
        free((*n));
        (*n) = NULL;
    }
    else{
        node* present = (*n);
        (*n) = (*n)->next;
        (*n)->prev = NULL;
        free(present);
    }
}

void delete_end(node** n){
    if((*n) == NULL){
        printf("Empty List\n");
    }
    else if((*n)->next == NULL){
        free((*n));
        (*n) = NULL;
    }
    else{
        node* present = (*n);
        while(present->next != NULL){
            present = present->next;
        }
        present->prev->next = NULL;
        free(present);
    }
}

void delete_pos(node** n, int pos){
    if((*n) == NULL){
        printf("Empty list\n");
    }
    else if((*n)->next == NULL){
        free((*n));
        (*n) = NULL;
    }
    else{
        node* present = (*n);
        int valid = 1;
        int i;

        for(i=1;i<pos;i++){
            present = present->next;
            if(present->next == NULL){
                valid = 0;
                break;
            }
        }

        if(valid){
            if(present->prev == NULL){
                (*n) = present->next;
                free(present);
            }
            else{
                present->prev->next = present->next;
                present->next->prev = present->prev;
                free(present);
            }

        }
        else if(pos-i == 1){
            present->prev->next = NULL;
            free(present);
        }
        else{
            printf("Invalid position\n");
        }
    }   
}




//--------------- ORDERED DOUBLY LINKED LIST
void insert_ordered(node** n, int x){
    node* temp = (node*)malloc(sizeof(temp));
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;

    if((*n) == NULL){
        (*n) = temp;
    }
    else{
        node* present = (*n);
        node* previous = NULL;
        while(present != NULL && present->data < x){
            previous = present;
            present = present->next;
        }

        if(previous == NULL){
            (*n)->prev = temp;
            temp->next = (*n);
            (*n) = temp;
        }
        else if(present==NULL){
            previous->next = temp;
            temp->prev = previous;
        }
        else{
            previous->next = temp;
            temp->prev = previous;
            present->prev = temp;
            temp->next = present;
        }
    }
}


//--------------- SEARCH FOR A NODE AND RETURN POSITION
int search(node** n, int x){
    int pos = 0;
    node* present = (*n);
    while(present != NULL){
        pos++;
        if(present->data == x){
            break;
        }
        present = present->next;
    }
    if(present==NULL){
        return -1;
    }
    else{
        return pos;
    }
}


//--------------- FIND SUM OF ALL NODES IN THE LIST
int sum(node** n){
    int s = 0;
    node* present = (*n);
    while(present!= NULL){
        s += present->data;
        present = present->next;
    }
    return s;
}



int main(){
    node* head = NULL;
    insert_ordered(&head,10);
    insert_ordered(&head,50);
    insert_ordered(&head,40);
    insert_ordered(&head,20);
    display(&head);
    printf("Position is %d\n",search(&head, 60));
    printf("Sum is %d\n",sum(&head));
    return 0;
}
