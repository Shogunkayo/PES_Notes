# POSTFIX EXPRESSION
---

- Postfix expression is an expression where the operator is placed after the two operands

A+B  = AB+

- To evaluate an infix expression, the compiler scans the expression repeatedly untill all the operations are performed
- Evaluating a postfix/prefix expression is more efficient

## Algorithm
1. Scan the infix expression from left to right
2. As long as the stack precedence value of the symbol on the top of the stack is greater than the input precedence value of the input symbol, pop the character and place it in the postfix array. If it fails, proceed to the next step
3. If the stack precedence value is not equal to the input precedence value, push the current value onto the stack. Else delete the item from the stack.
4. Repeat untill the string ends

| Stack Precedence  | Value |
| ----------------- | ----- |
| +, -              | 2     |
| /,*               | 4     |
| $                 | 5     |
| (                 | 0     |
| #                 | -1    |
| default(operands) | 8     | 

| Input Precedence  | Value |
| ----------------- | ----- |
| +, -              | 1     |
| /, *               | 3     |
| $                 | 6     |
| (                 | 9     |
| )                 | 0     | 
| default(operands) | 7     |

## Implementation
```
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
```





