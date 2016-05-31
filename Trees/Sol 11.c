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

int search(struct bstnode* node,int value)
{
	if (node == NULL) {
		return 0;
	} else if (node -> data == value) {
		return 1;
	} else if (value <= node -> data) {
		return search(node -> left,value);
	} else {
		return search(node -> right,value);
	}
}

void ancestor(struct bstnode* node,struct bstnode* root,int value)
{
	if (search(root,value) == 0) {
		printf("%d doesnot exist in the BST\n",value);
		return;
	}
	if (node -> data != value) {
		printf("%d ",node -> data);
	}
	if (node -> data == value) {
		return;
	} else if (value <= node -> data) {
		ancestor(node -> left,root,value);
	} else {
		ancestor(node -> right,root,value);
	}
}

int main()
{
	int v, n, i, k;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		root = insert(root,v);
	}
	scanf("%d", &k);
	ancestor(root,root,k);
	printf("\n");
	return 0;
}
