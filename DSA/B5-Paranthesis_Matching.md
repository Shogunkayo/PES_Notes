# PARANTHESIS MATCHING
----

-> Matching - (), {}, [()], [({})], [(){}]
-> Not Matching - ({), (, ], {[}]

## Algorithm
1. Declare an empty stack.
2. Traverse the input string
3. If the character is an opening paranthesis, push it onto the stack
4. If the character is a closing paranthesis, provided the stack is not empty, pop the top of the stack and compare. 
5. If they match, return 1 (successful)
6. Else return 0(unsuccessful)
7. After traversal, if there are any other paranthesis left in the stack, return 0

## Implementation
```
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
```