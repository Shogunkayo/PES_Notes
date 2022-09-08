# PREFIX EXPRESSION
---

- Prefix expression is an expression where the operator is placed after the two operands

A+B  = +AB

## Algorithm
1. Reverse the input string
2. Change all '(' to ')' and vice versa
3. Find the postfix expression of the reversed infix
4. Reverse the above obtained string to get the prefix expression

## Implementation
```
void strrev(char* s){
    int len = strlen(s);
    char temp;
    for(int i=0; i<len/2; i++){
        temp = s[i];  
        s[i] = s[len - i - 1];  
        s[len - i - 1] = temp;  
    }
}

void infix_prefix(char* infix, char* prefix){
    strrev(infix);
    
    int i=0;

    while(infix[i] != '\0'){
        if(infix[i] == ')'){
            infix[i] = '(';
        }
        else if(infix[i] == '('){
            infix[i] = ')';
        }
        i++;
    }

    infix_postfix(infix, prefix); 
    strrev(prefix);
}
```

*Function to convert infix to postfix expression is in the previous file [[B2-Infix_to_Postfix]]*
