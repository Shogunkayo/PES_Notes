#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node* left;
    struct Node* right;
}node;

typedef struct Tree{
    node* root;
}tree;

typedef struct Stack{
    node* s[50];
    int top;
}stack;

void initialize_tree(tree* t){
    t->root = NULL;
}

void initialize_stack(stack* s){
    s->top = -1;
}

void push(stack* s, node* root){
    if(s->top < 50){
        s->s[++(s->top)] = root;
    }
}

node* pop(stack* s){
    if(s->top != -1){
        return s->s[(s->top)--];
    }
}

int is_operator(char x){
    switch(x){
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default: 
            return 0;
    }
}

void create(tree* t, stack* s, char* postfix){
    node* temp;
    int i=0;
    
    while(postfix[i] != '\0'){
        temp = (node*)malloc(sizeof(node));
        temp->data = postfix[i];
        temp->left = NULL;
        temp->right = NULL;

        if(is_operator(postfix[i])){
            temp->right = pop(s);
            temp->left = pop(s);
        }

        push(s, temp);
        
        i++;
    }
    
    t->root = pop(s);
}

void in_order(node* root){
    if(root!=NULL){
        in_order(root->left);
        printf("%c\n", root->data);
        in_order(root->right);
    }
}

float evaluate(node* root){
    switch(root->data){
        case '+': 
            return evaluate(root->left) + evaluate(root->right);
        case '-': 
            return evaluate(root->left) - evaluate(root->right);
        case '*': 
            return evaluate(root->left) * evaluate(root->right);
        case '/': 
            return evaluate(root->left) / evaluate(root->right);
        default:
            return root->data - '0';
    }
}

int main(){
    tree t;
    stack s;
    char postfix[20] = "12+";
    initialize_tree(&t);
    initialize_stack(&s);
    create(&t, &s, postfix);
    in_order(t.root);
    printf("%f\n", evaluate(t.root));
}