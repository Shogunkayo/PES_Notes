# N-ary Tree
---
- A rooted tree in which each node has a maximum of n children
- Either the maximum number of children nodes are fixed,
```
typedef struct Node{
	int data;
	struct Node* child[MAX];
}node;
```
Or only the first(oldest) node is linked to the parent node, and each node has a link to its sibling node
```
typedef struct Node{
	int data;
	struct Node* child;
	struct Node* sibling;
}node;
```

## Converting N-ary to Binary 

#### 1. Left child - right sibling
- Link all the siblings of a node
- Remove all the links of a node to its children, except for the leftmost child 
- The resulting binary tree will always have an empty right subtree for the root node as the root node does not have any siblings

#### 2. Forest 
- A forest is a collection of binary trees
- Convert each tree into a binary tree by the above method
- Link all the binary trees together through the right child of the root node


## Traversal

#### 1. Preorder
```
void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->info);
		preorder(root->child);
		preorder(root->sibling);
	}
}
```

#### 2. Postorder
```
void postorder(node *root)
{
	 if(root!=NULL)
	 {
		 postorder(root->child);
		 postorder(root->sibling);
		 printf("%d\n", root->info);
	 }
}
```

#### 3. Inorder
```
void inorder(node *root)
{
	 if(root!=NULL)
	 {
		 inorder(root->child);
		 printf("%d\n",root->info);
		 inorder(root->sibling);
	 }
}
```