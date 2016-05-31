#include<stdio.h>
#include<stdlib.h>

struct bstnode
{
	int data;
	struct bstnode *left;
	struct bstnode *right;
};

struct bstnode* getnewnode(int value)
{
	struct bstnode * temp;
	temp = (struct bstnode*)malloc(sizeof(struct bstnode));
	temp -> data = value;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

struct bstnode* insert(struct bstnode *node,int value)
{
	if (node == NULL) {
		node = getnewnode(value);
	} else if (value <= node -> data) {
		node -> left = insert(node -> left,value);
	} else {
		node -> right = insert(node -> right,value);
	}
	return node;
}

void leaf_traversal(struct bstnode* node,int value)
{
	if (node -> data != value) {
		printf("%d->",node -> data);
	}
	if (node -> data == value) {
		printf("%d\n",node -> data);
		return;
	} else if (value <= node -> data) {
		leaf_traversal(node -> left,value);
	} else {
		leaf_traversal(node -> right,value);
	}
}

void leafs(struct bstnode *node,struct bstnode *root)
{
	if (node == NULL) {
		return;
	}
	if (node -> left == NULL && node -> right == NULL) {
		leaf_traversal(root,node -> data);
	}
	leafs(node -> left,root);
	leafs(node -> right,root);
	return;
}

int main()
{
	int v, n, i;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		root = insert(root,v);
	}
	leafs(root,root);
	return 0;
}
