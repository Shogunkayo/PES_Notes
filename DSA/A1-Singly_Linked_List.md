 # LINKED LIST
----

- Linear data structure where the elements are stored in the form of nodes
- First component of a node is the data and the second component is the link to the next node

```
typedef struct node{
	int data;
	struct node* link;
}node;

typedef struct linked_list{
	node* head;
}list;

void initialize(list* l){
    l->head = NULL;
}
```

| Array                               | Linked List                    |
| ----------------------------------- | ------------------------------ |
| Static time allocation              | Dynamic allocation             |
| Access is faster                    | Access is slower               |
| Fixed size                          | Variable size                  |
| Insertion and deletion is expensive | Insertion and deletion is easy |


## Types

1. Simply Linked List
2. Circular SImply Linked List
3. Doubly Linked List
4. Circular Doubly  Linked List


## Basic Operations

##### 1. Insertion of a node
```
void insert_start(list* l, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = NULL;

    if(l->head == NULL){
        l->head = temp;
    }
    else{
        temp->link = l->head;
        l->head = temp;
    }
}
```
```
void insert_end(list* l, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = NULL;

    if(l->head == NULL){
        l->head = temp;
    }
    else{
        node* present = l->head;
        while(present->link != NULL)
            present = present->link;
        }
        present->link = temp;
    }
}
```
```
void insert_pos(list* l, int x, int pos){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = NULL;

    if(l->head == NULL){
        printf("Inserted at the start as list did not exist\n");
        l->head = temp;
    }
    else{
        node* present = l->head;
        node* previous = NULL;

        int valid = 1;
        
        for(int i = 1; i<pos; i++){
            if(present == NULL){
                printf("Invalid position\n");
                valid = 0;
                break;
            }
            else{
                previous = present;
                present = present->link;
            }
        }
        
        if(valid){
            previous->link = temp;
            temp->link = present;
        }
    }
}
```


##### 2. Deletion of a node
```
void delete_start(list* l){
    if(l->head == NULL){
        printf("Empty list\n");
    }
    else{
        node* n = l->head;
        l->head = l->head->link;
        free(n);
    }
}
```

```
void delete_end(list* l){
    if(l->head == NULL){
        printf("Empty list\n");
    }
    else{
        node* present = l->head;
        node* previous = NULL;
        while(present->link != NULL){
            previous = present;
            present = present->link;
        }
        free(present);
        previous->link = NULL;
    }
}
```

```
void delete_list(list* l){
    if(l->head == NULL){
        printf("Empty list\n");
    }
    else{
        node* temp;
        while(l->head != NULL){
            temp = l->head;
            l->head = l->head->link;
            free(temp);
        }
    }
}
```

```
void delete_pos(list* l, int pos){
    if(l->head == NULL){
        printf("List is empty\n");
    }
    else{
        node* present = l->head;
        node* previous = NULL;

        int valid = 1;
        for(int i=1; i<pos; i++){
            if(present == NULL){
                printf("Invalid position\n");
                valid = 0;
                break;
            }
            else{
                previous = present;
                present = present->link;
            }
        }

        if(valid){
            previous->link = present->link;
            free(present);
        }
    }
}

```

```
void delete_duplicate(list* l){
    
    node* present = l->head;
    node* dup;
    node* temp;
    
    while(present != NULL && present->link != NULL){
        temp = present;
        while(temp->link != NULL){
            if(present->data == temp->link->data){
                dup = temp->link;
                temp->link = temp->link->link;
                free(dup);
            }
            else{
                temp = temp->link;
            }
        }
        
        present = present->link;        
    }
}

```

##### 3. Display
```
void display(const list* l){
    node* temp = l->head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
```
##### 4. Search
```
void search(list* l, int x){
    int pos = -1;
    node* present = l->head;
    while(present->link != NULL){
        pos++;
        if(present->data == x){
            break;
        }
        present = present->link;
    }

    if(pos == -1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at node %d\n",pos);
    }
}
```

##### 5. Concatenate
```
void list_merge(list* l1, list* l2, list* l3){
    node* present1 = l1->head;
    node* present2 = l2->head;
    node* temp1;
    node* temp2;
    l3->head = l1->head;

    while(present1 != NULL && present2 != NULL){
        temp1 = present1->link;
        temp2 = present2->link;

        present1->link = present2;
        present2->link = temp1;
        
        present1 = temp1;
        present2 = temp2;
    }

    // WHEN LIST 2 IS BIGGER THAN LIST 1
    if(present1 == NULL && present2 != NULL){
        node* present = l3->head;
        while(present->link != NULL){
            present = present->link;
        }
        while(present2 != NULL){
            present->link = present2;
            present2 = present2->link;
            present = present->link;
        }
    }
}
```

##### 6. Sort
- [Merge sort](http://en.wikipedia.org/wiki/Merge_sort) is often preferred for sorting a linked list. 
- The slow random-access performance of a linked list makes some other algorithms (such as [quicksort](https://www.geeksforgeeks.org/quick-sort/)) perform poorly, and others (such as [heapsort](https://www.geeksforgeeks.org/heap-sort/)) completely impossible.

##### 7. Reverse
```
void reverse(list* l){
    node* temp, *prev, *cur;
    prev = NULL;
    cur = l->head;
    while(cur!=NULL){
        temp = cur->link;
        cur->link = prev;
        prev = cur;
        cur = temp;
    }
    l->head = prev;
}
```

## Ordered List
```
void ordered_insert(list* l, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = NULL;

    if(l->head == NULL){
        l->head = temp;
    }
    else{
        node* present = l->head;
        node* previous = NULL;

        while(present != NULL && present->data < x){
            previous = present;
            present = present->link;
        }

        if(previous == NULL){
            temp->link = present;
            l->head = temp;          
        }
        else{
            previous->link = temp;
            temp->link = present;
        }
    }
}
```

## Questions

> Write a recursive method to determine whether a singly linked list is sorted in descending order or not. Assume NODE contains data and next pointer. Declare NODE structure and write the method. The method should return 1 if the list is sorted and 0 otherwise.
> Method definition - int isListSorted(NODE* linkedlist)

> x and y are two singly linked lists containing integer document ids. Write a function called merge that takes x and y and returns the third list z which contains only the document ids that are in x and not in y

> Give two reasons for prefering array over linked list. Similarly give two reasons for prefering list over an array

> Write the output of the following 
```
void what(struct node** p){
    node* temp, *prev, *cur;
    prev = NULL;
    cur = *p;
    while(cur!=NULL){
        temp = cur->link;
        cur->link = prev;
        prev = cur;
        cur = temp;
    }
    *p = prev;
}
```
```
void what1(struct node** p){
    struct node* pres;
    pres = *p;
    while(pres!=NULL){
        printf("%d ",pres->data);
        pres = pres->link->link;
    }
}
```
```
void what2(struct node* p){
    if(p == NULL){
        return;
    }
    what2(p->link);
    printf("%d",p->data);
}
```
```
void what3(struct node* head){
    if(head==NULL){
        return;
    }
    printf("%d", head->data);
    if(head->link != NULL){
        what3(head->link->link);
    }
    printf("%d", head->data);
}
```
