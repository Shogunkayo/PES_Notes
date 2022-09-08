#include<stdio.h>
#include<math.h>

//--------------- EVALUATE POSTFIX

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

void push(int* s, int* t, int r){
    s[++(*t)] = r;
}

int pop(int* s, int* t){
    return s[(*t)--];
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

int main(){
    char postfix[20];
    printf("Enter the postfix expression: ");
    scanf("%s",postfix);
    printf("The result is: %d\n",eval(postfix));
    return 0;
}