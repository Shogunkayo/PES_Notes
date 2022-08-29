# DOUBLY LINKED LIST
----

| Singly Linked List     | Doubly Linked List             |
| ---------------------- | ------------------------------ |
| Node has 2 fields      | Node has 3 fields              |
| Less memory            | More memory                    |
| Access is slow         | Access is fast                 |
| Only forward traversal | Forward and backward traversal |

### Application -
- Evaluation of polynomials
- Arithmatic operation on large integers
- Designing text editor, web browser, image viewer, audio player
- SLL is used to implement stacks, DLL is used for trees

### Advantages -
- Insertion and deletion is easy
- Runtime allocation

### Disadvantages - 
- Slow access
- More memory consumption


```
typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;
```



## BASIC OPERATIONS


#### 1.  Insertion
```
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
```
```
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
        temp->previous = present;
    }
}
```
```
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
```

#### 2. Display
```
void display(node** n){
    node* present = (*n);
    while(present != NULL){
        printf("%d ",present->data);
        present = present->next;
    }
    printf("\n");
}
```

#### 3. Deletion
```
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
```
```
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
```

```
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
```
## Ordered Doubly Linked List

```
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
```
## Questions
> Given a doubly linked list with head and tail pointers, print the list so that alternate elements from the begining and the end are printed 

> Specify a DNODE structure of an integer doubly linked list

> Write a function to delete a node based on the specified index position in doubly linked list. 0 should delete the head node, 1 should delete the node after head and so on. Handle all the boundary conditions

