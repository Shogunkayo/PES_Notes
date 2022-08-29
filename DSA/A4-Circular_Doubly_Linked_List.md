# CIRCULAR DOUBLY LINKED LIST
----

> Circular Doubly Linked List has properties of both doubly linked list and circular linked list in which two consecutive elements are linked or connected by previous and next pointer and the last node points to first node by next pointer and also the first node points to last node by the previous pointer.

```
typedef struct node{
    int data;
    struct node* next; 
    struct node* prev; 
}node;
```

## Basic Operations

#### 1. Insertion
```
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
```
```
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
```
```
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
```

#### 2. Display
```
void display(node** n){
    node* present = (*n)->next;
    while(present != *n){
        printf("%d ",present->data);
        present = present->next;
    }
    printf("%d\n",present->data);    //To print data of *n
}
```

#### 3. Deletion
```
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
```
```
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
```
```
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
```