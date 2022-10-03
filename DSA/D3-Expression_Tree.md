# EXPRESSION TREE
---
- Binary tree where each internal node corresponds to the operator and each node corresponds to an operand
- Inorder traversal gives the infix expression
- Preorder traversal gives the prefix expression 
- Postorder traversal gives the postfix expression

For each binary operator,
- The left sub tree contains operators and operands which come in the left side of the operator
- The right sub tree contains operators and operands which come in the right side of the operator

For each unary operator, 
- One of the subtrees will be empty 
- Negation, logarithm and trignometry operators are written on the left
- Factrorial, exponent operators are written on the right
- Derivative(d/dx of x or x'), increment and decrement operators can be written on either side

### Construction:
---
1. Scan the postfix expression
2. Create a node for every scanned character
3. If the character is an operand, push it onto the stack
4. If the character is an operator, pop the first node from the stack and attach it to the right of the corresponding parent node. Pop the second node and attach it to the left
5. Push the node corresponding to the operator onto the stack
6. Repeat the steps till the end of the expression
7. Return the node on top of the stack, which is the root node of the expression tree

### Evaluation:
----
1. Scan the root node
2. If it contains an operator,  recursively perform the specified operation with the left and right child nodes
3. If it contains a number, convert it from character to integer


### Implementation:
----
```
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
```
