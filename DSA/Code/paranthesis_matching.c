#include<stdio.h>

//--------------- USING ARRAYS
char pop(char* s, int* t){
    return(s[(*t)--]);
}

void push(char* s, int* t, char x){
    s[++(*t)] = x;
}

int compare(char* s, int* t, char x){
    char popped;
    if(*t == -1){
        return 0;
    }
    else{
        popped = pop(s,t);
        switch(x){
            case ')':   if(popped == '(') return 1;
            case '}':   if(popped == '{') return 1;
            case ']':   if(popped == '[') return 1;
        }
        return 0;
    }
}

int par_match(char* e){
    char s[20];
    int top=-1;
    int i=0;
    int match=1;

    while(e[i] != '\0'){
        switch(e[i]){
            case '(':
            case '[':
            case '{':
                push(s,&top,e[i]);
                break;
            case ')':
            case ']':
            case '}':
                match = compare(s,&top,e[i]);
                break;
            default:    return -1;
        }
        if(!match){
            return 0;
        }
        i++;
    }
    if(top != -1){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    char expression[20];
    printf("Enter the expression: ");
    scanf("%s",expression);
    if(par_match(expression)){
        printf("Paranthesis are matching\n");
    }
    else{
        printf("Paranthesis are not matching\n");
    }
}

//--------------- USING LINKED LIST


// Design a method for keeping two stacks within a single linear array so that neither stack overflows until all of the memory is used and an entire stack is never shifted to a different location within the array. Write C routines push1, push2, pop1, pop2 to manipulate two stacks.
// Hint - the two stacks grow towards each other