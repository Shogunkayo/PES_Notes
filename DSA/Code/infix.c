#include<stdio.h>
#include<stdlib.h>

//--------------- INFIX TO POSTFIX

void push(char* s, int* t, char ch){
    s[++(*t)] = ch;
}

char peek(char* s, int* t){
    return s[*t];
}

char pop(char* s, int* t){
    return s[(*t)--];
}

int stkprec(char ch){
    switch(ch){
        case '+':
        case '-': return 2;

        case '*':
        case '/': return 4;

        case '$': return 5;

        case '(': return 0;

        case '#': return -1;

        default: return 8;
    }
}

int ipprec(char ch){
    switch(ch){
        case '+':
        case '-': return 1;

        case '*':
        case '/': return 3;

        case '$': return 6;

        case '(': return 9;

        case ')': return 0;

        default: return 7;
    }
}

void infix_postfix(char* infix, char* postfix){
    char s[20];
    int top=-1, i=0, j=0;

    push(s,&top,'#');

    while(infix[i]){
        while(stkprec(peek(s,&top)) > ipprec(infix[i])){
            postfix[j++]  = pop(s,&top);
        }

        if(stkprec(peek(s,&top)) < ipprec(infix[i])){
            push(s,&top,infix[i]);
        }
        else{
            pop(s,&top);
        }

        i++;
    }
    
    while(peek(s,&top)!='#'){
        postfix[j++]=pop(s,&top);
        postfix[j]='\0';
    }

}

int main(){
    char infix[20], postfix[20];
    printf("Enter the infix expression\n");
    scanf("%s",infix);
    infix_postfix(infix, postfix);
    printf("Postfix Expression:\n%s\n",postfix);
}