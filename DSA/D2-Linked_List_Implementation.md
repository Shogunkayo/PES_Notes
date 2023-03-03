# LINKED LIST IMPLEMENTATION
----

```
typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}node;
```

```
typedef struct Tree{
	node* root;
}tree;
```

##### 1. Creation
```
void create_tree(tree* t){
    t->root = NULL;
}
```

##### 2. Insertion
```
void insert(tree* t, int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;

    if(t->root == NULL){
        t->root = temp;
    }
    else{
        node* root = t->root;
        while(1){
            if(root->data > temp->data){
                if(root->left == NULL){
                    root->left = temp;
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right == NULL){
                    root->right = temp;
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
    }
}
```

#### 3. Traversal
```
void pre_order(node* n){
    if(n!=NULL){
        printf("%d\n", n->data);
        pre_order(n->left);
        pre_order(n->right);
    }
}
```

```
void in_order(node* n){
    if(n!=NULL){
        in_order(n->left);
        printf("%d\n", n->data);
        in_order(n->right);
    }
}
```

```
void post_order(node* n){
    if(n!=NULL){
        post_order(n->left);
        post_order(n->right);
        printf("%d\n", n->data);
    }
}
```

#### 4. Deletion
- There are 3 cases which arises while deleteing a node
1. Node with no child
   - Set corresponding field to NULL in the parent node
2. Node with 1 child
   - Connect the child to the parent of the node
3. Node with 2 child
   - Replace the node to be deleted with either its inorder successor or its inorder predecessor
   - Delete the predecessor/successor node according to the first 2 cases
   - The successor is used for the implementation below

```
node* delete(node* root, int x){
    if(root!=NULL){
        if(root->data > x){
            root->left = delete(root->left, x);
            return root;
        }
        else if(root->data < x){
            root->right = delete(root->right, x);
            return root;
        }
       
        if(root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        
        node* successor = root->right;
        node* successor_root = root;
        while(successor->left != NULL){
            successor_root = successor;
            successor = successor->left;
        }

        if(successor_root != root){
            successor_root->left = successor->right;
        }
        else{
            successor_root->right = successor->right;
        }

        root->data = successor->data;
        free(successor);
        return root;
    }
}
```