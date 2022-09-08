#include<stdio.h>
#include<stdlib.h>

void push(int* s, int* t, int size, int x){
    if(*t == size-1){
        printf("Stack Overflow\n");
    }
    else{
        (*t)++;
        s[*t] = x;
    }
}

void display(int* s, int* t){
    if(*t == -1){
        printf("Stack Underflow");
    }
    else{
        for(int i=*t; i>-1; i--){
            printf("%d ",s[i]);
        }
    }
    printf("\n");
}

void pop(int* s, int* t){
    if(*t == -1){
        printf("Stack Underflow\n");
    }
    else{
        (*t)--;
    }
}

int main(){
    int* s;
    int top, size, data;

    size = 4;
    s = (int*)malloc(sizeof(int));
    top = -1;

}