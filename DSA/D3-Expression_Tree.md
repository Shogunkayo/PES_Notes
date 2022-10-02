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

