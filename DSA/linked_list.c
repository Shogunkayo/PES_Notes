#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link; 
}node;

typedef struct linkedlist{
    node* head;
}list;



//--------------- BASIC OPERATIONS 

void initialize(list* l){
    l->head = NULL;
}

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

void insert_end(list* l, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = NULL;

    if(l->head == NULL){
        l->head = temp;
    }
    else{
        node* present = l->head;
        while(present->link != NULL){
            present = present->link;
        }
        present->link = temp;
    }
}

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
        printf("Element found at node %d\n",(pos+1));
    }
}

void display(const list* l){
    node* temp = l->head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

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
            previous->link = temp;
            temp->link = present;
        }
    }
}

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


//--------------- MERGE SORT
/*
void front_back_split(list* l, node** frontref, node** backref){
    node* fast;
    node* slow;

    slow = l->head;
    fast = l->head->link;

    while(fast!=NULL){
        fast = fast->link;
        if(fast!=NULL){
            slow = slow->link;
            fast = fast->link;
        }
    }

    *frontref = l->head;
    *backref = slow->link;
    slow->link = NULL;
}

void merge_sort(list* l){
    node* a;
    node* b;
    
    if(l->head == NULL || l->head->link == NULL){
        return;
    }

    front_back_split(l->head, &a, &b);
    merge_sort(&a);
    merge_sort(&b);

    l->head = sorted_merge(a,b);
}

node* sorted_merge(node* a, node* b){
    node* result = NULL;

    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }

    if(a->data <= b->data){
        result = a;
        result->link = sorted_merge(a->link, b);
    }
    else{
        result = b;
        result->link = sorted_merge(a, b->link);
    }

    return(result);
}
*/

//--------------- ORDERED LIST

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

void what1(struct node** p){
    struct node* pres;
    pres = *p;
    while(pres!=NULL){
        printf("%d ",pres->data);
        pres = pres->link->link;
    }
}

void what2(struct node* p){
    if(p == NULL){
        return;
    }
    what2(p->link);
    printf("%d",p->data);
}

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

// WRITE A PROGRAM TO MERGE TWO SINGLY LINKED LIST -
// 1 3 5 7
// 2 4 6
// Output - 1 2 3 4 5 6 7 
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

void reverse_list(list* l){
    node* present = l->head;
    node* previous = NULL;
    node* temp;
    
    while(present != NULL){
        temp = present->link;
        present->link = previous;
        previous = present;
        l->head = present;
        present = temp;
    }
}


// WRITE A PROGRAM TO REMOVE DUPLICATE NODES
void remove_duplicate(list* l){
    
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

int main(){
    list l;
    initialize(&l);
    
    insert_start(&l,20);

    
    list l2;
    initialize(&l2);
    insert_start(&l2,2);
    insert_start(&l2,1);
    insert_start(&l2,1);
    insert_start(&l2,2);
    insert_start(&l2,1);
    display(&l2);
    remove_duplicate(&l2);
    display(&l2);
}

