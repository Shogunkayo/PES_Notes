#include<stdio.h>
#include<stdlib.h>

/*
void insert(int* t, int x){
    int i=0;
    while(t[i] != -1){
        if(t[i]>x){
            i = i*2 + 1;
        }
        else{
            i = i*2 + 2;
        }
    }
    t[i] = x;
}

void preorder(int* t, int i){
    if(t[i]!=-1){
        printf("%d ",t[i]);
        preorder(t, i*2 + 1);
        preorder(t, i*2 + 2);
    }
}

void inorder(int* t, int i){
    if(t[i]!=-1){
        inorder(t, i*2 + 1);
        printf("%d ",t[i]);
        inorder(t, i*2 + 2);
    }
}

void postorder(int* t, int i){
    if(t[i]!=-1){
        postorder(t, i*2 + 1);
        postorder(t, i*2 + 2);
        printf("%d ",t[i]);
    }
}

int main(){
    int t[100];
    for(int i=0; i<100; i++){
        t[i] = -1;
    }
}
*/

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}node;

typedef struct Tree{
    node* root;
}tree;

void create_tree(tree* t){
    t->root = NULL;
}

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

void pre_order(node* root){
    if(root!=NULL){
        printf("%d\n", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(node* root){
    if(root!=NULL){
        in_order(root->left);
        printf("%d\n", root->data);
        in_order(root->right);
    }
}

void post_order(node* root){
    if(root!=NULL){
        post_order(root->left);
        post_order(root->right);
        printf("%d\n", root->data);
    }
}

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

int main(){
    tree* t;
    create_tree(t);
    insert(t, 19);
    insert(t, 16);
    insert(t, 22);
    insert(t, 14);
    insert(t, 17);
    insert(t, 11);
    insert(t, 15);
    insert(t, 18);
    insert(t, 20);
    insert(t, 26);
    insert(t, 24);
    insert(t, 29);
    insert(t, 35);
    insert(t, 30);
    insert(t, 32);
    insert(t, 8);
    pre_order(t->root);
    delete(t->root, 19);
    pre_order(t->root);
}



/*
What does the following code do
int what(struct tnode* t){
    if(t==NULL) return 0;
    if(t->left==NULL &&t->right==NULL)  return 1;
    int l = what(t->left);
    int r = what(t->right);
    return (l+r);
}
find max and minimum node value
*/


// Construct a binary search tree for the following 11, 19, 15, 8, 10, 14, 12, 13, 5, 3, 7, 6, 17
// Delete the node 11 nad 13
// Reconstruct the tree after deleting and inserting 16 and 18 and 9, delete 8

// Construct a binary search tree for the following 
// Inorder: D B E A F C
// Preoorder: A B D E C F