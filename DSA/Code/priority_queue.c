#include<stdio.h>

typedef struct priority_queue{
    int data;
    int priority;
}queue;

/*
void insert(queue *pq, int* count, int x, int p){
    int j = *count - 1;
    queue temp;
    temp.data = x;
    temp.priority = p;

    while(j>=0 && pq[j].priority > temp.priority){
        pq[j+1] = pq[j];
        j--;
    }

    pq[j+1] = temp;
    (*count)++;
}

queue delete(queue *pq, int* count){
    queue temp;
    if(count == 0){
        temp.data = 0;
        temp.priority = -1;
    }
    else{
        temp = pq[0];
        for(int j=1; j<*count; j++){
            pq[j-1] = pq[j];
        }
        (*count)--;
    }
    return temp;
}
*/

void insert(queue *pq, int* count, int x, int p){
    pq[++(*count)].data = x;
    pq[(*count)].priority = p;
}

void display(queue *pq, int count){
    if(count > -1){
        for(int i=0; i<count+1; i++){
            printf("Data:%d Priority:%d\n",pq[i].data,pq[i].priority);
        }
    }
    else{
        printf("Empty Queue\n");
    }
}

int max_priority(queue *pq, int count){
    int max = -1;
    for(int i=0; i<count+1; i++){
        if(pq[i].priority > max){
            max = pq[i].priority;
        }
    }
    
    // +1 to take care of deleting the highest priority node
    return max+1;
}

void delete(queue *pq, int* count){
    if(*count == -1){
        printf("Empty Queue\n");
    }
    else{
        queue temp;
        temp.priority = max_priority(pq, *count);
        int index = -1;

        for(int i=0; i<*count+1; i++){
            if(pq[i].priority < temp.priority){
                temp = pq[i];
                index = i;
            }
        }
        
        for(int i=index; i<*count; i++){
            pq[i] = pq[i+1];
        }

        (*count)--;
    }
}

int main(){
    queue q[20];
    int count = -1;
    insert(q, &count, 10, 2);
    insert(q, &count, 20, 1);
    insert(q, &count, 30, 4);
    insert(q, &count, 40, 3);
    delete(q, &count);
    delete(q, &count);
    delete(q, &count);
    delete(q, &count);
    delete(q, &count);
    display(q, count);
    insert(q, &count, 20, 1);
    insert(q, &count, 30, 4);
    insert(q, &count, 40, 3);
    display(q, count);
    
    
}
