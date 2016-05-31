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

void leafs(struct bstnode *node,int *sum)
{
	if (node == NULL) {
		return;
	}
	if (node -> left == NULL && node -> right == NULL) {
		*sum = *sum + (node -> data);
	}
	leafs(node -> left,sum);
	leafs(node -> right,sum);
	return;
}

int main()
{
	int v, n, i;
	int sum = 0;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		root = insert(root,v);
	}
	leafs(root,&sum);
	printf("Sum of values of all leaves in the BST is : %d\n",sum);
	return 0;
}
