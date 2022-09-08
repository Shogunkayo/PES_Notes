# IMPLEMENTATION OF STACK
-----

## Using Array

#### 1. Insert
```
void push(char* s, int* t, char ch, int size){
    if(*t == size-1){
	    printf("Stack Overflow\n");
    }
    else{
	    s[++(*t)] = ch;
    }
    
}
```

#### 2. Delete
```
char pop(char* s, int* t, int size){
	if(*t == -1){
		printf("Stack Underflow\n");
	}
	else{
		return s[(*t)--];
	}
}
```

#### 3.  Display
```
void display(char* s, int* t){
    if(*t == -1){
        printf("Stack Underflow\n");
    }
    else{
        for(int i=*t; i>-1; i--){
            printf("%c ",s[i]);
        }
    }
    printf("\n");
}
```

#### 4. Peek
```
char peek(char* s, int* t){
    return s[*t];
}
```


