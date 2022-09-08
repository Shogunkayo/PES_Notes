# EVALUATION OF EXPRESSIONS
-----

## Postfix Expression
### Algorithm :
1. Scan the postfix expression from left to right
2. If the scanned element is a number, push it onto the stack
3. If the scanned element is an operator, pop the top two operands from the stack
4. Evaluate the result and push it back to the stack
5. Repeat till the entire expression is scanned
6. When the expression has ended, the number in the stack is the final result
7. Pop the result and display

### Implementation:
```
int is_operator(char ch){
    switch(ch){
        case '+':
        case '-':
        case '/':
        case '*':
        case '$':   return 1;
        default:    return 0;
    }
}

int eval(char* postfix){
    int s[20], top=-1, i=0;
    int op1, op2;
    char ch;
    int a;

    while(postfix[i] != '\0'){
        ch = postfix[i];
        if(is_operator(ch)){
            op2 = pop(s,&top);
            op1 = pop(s,&top);
            switch(ch){
                case '+': push(s,&top,op1+op2);
                break;
                case '-': push(s,&top,op1-op2);
                break;
                case '*': push(s,&top,op1*op2);
                break;
                case '/': push(s,&top,op1/op2);
                break;
                /*
                case '$': push(s,&top,pow(op1,op2));
                break;
                */
            }
        }
        else{
            printf("%c: ",ch);
            scanf("%d", &a);
            push(s,&top,a);
        }
        i++;
    }

    return(pop(s,&top));
}
```

## Prefix Expression
### Implementation
```
int eval(char* prefix){
    int s[20], top=-1;
    int op1, op2;
    int a;


    for(int i=strlen(prefix)-1;i>-1;i--){
        if(is_operator(prefix[i])){
            op1 = int_pop(s,&top);
            op2 = int_pop(s,&top);
            switch(prefix[i]){
                case '+': int_push(s,&top,op1+op2);
                break;
                case '-': int_push(s,&top,op1-op2);
                break;
                case '*': int_push(s,&top,op1*op2);
                break;
                case '/': int_push(s,&top,op1/op2);
                break;
                /*
                case '$': push(s,&top,pow(op1,op2));
                break;
                */
            }
        }
        else{
        
            printf("%c: ",prefix[i]);
            scanf("%d", &a);
            int_push(s,&top,a);
        }
    }

    return(int_pop(s,&top));
}
```

