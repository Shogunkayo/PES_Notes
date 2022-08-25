# CIRCULAR LINKED LIST
---

- All the nodes are interconnected  to form a circle - last node is connected to first node
- A tail pointer is often used instead of a head pointer

> In a singly linked list, for accessing any node of the linked list, we start traversing from the first node. If we are at any node in the middle of the list, then it is not possible to access nodes that precede the given node. This problem can be solved by slightly altering the structure of a singly linked list

> For the insertion of a node at the beginning, we need to traverse the whole list. Also, for insertion at the end, the whole list has to be traversed. If instead of start pointer, we take a pointer to the last node, then in both cases there won’t be any need to traverse the whole list. So insertion at the beginning or at the end takes constant time, irrespective of the length of the list.


## Basic Operations

#### 1. Insertion
```
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
```
```
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
        (*n) = temp;
    }
}
```
```
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
```

#### 2. Display
```
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
```

#### 3. Deletion
```
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
```
```
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
```

```
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
```

## Ordered Circular Linked List

```
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

```


## Header Node
- Header node keeps the count of nodes in the list
- An external pointer points to this node and the next node is the first node of the list

#### Creating a header node
```
node* create_header(){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = 0;
    temp->link = temp;
    return temp;
}
```

#### Insertion
```
void insert_start_header(node* n, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = NULL;

    temp->link = n->link;
    n->link = temp;
    n->data++;
}
```
```
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
```

#### Display
```
void display_header(node* n){
    node* present = n->link;
    while(present != n){
        printf("%d ",present->data);
        present = present->link;
    }
    printf("Number of nodes: %d\n",n->data);
}
```

#### Deletion
```
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
```