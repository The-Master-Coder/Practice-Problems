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

void is_sumtree(struct bstnode *node,int *flag)
{
	if (node -> left == NULL && node -> right == NULL) {
		return;
	}
	is_sumtree(node -> left,flag);
	if (node -> left == NULL) {
		if ((node -> data) == (node -> right -> data)) {
			*flag = 1;
			return;
		} else {
			*flag = 2;
			printf("This BT is not a Sum tree\n");
			exit(1);
		}
	} else if (node -> right == NULL) {
		if ((node -> data) == (node -> left -> data)) {
			*flag = 1;
			return;
		} else {
			*flag = 2;
			printf("This BT is not a Sum tree\n");
			exit(1);
		}
	} else {
		if ((node -> data) == (node -> left -> data) + (node -> right -> data)) {
			*flag = 1;
			return;
		} else {
			*flag = 2;
			printf("This BT is not a Sum tree\n");
			exit(1);
		}
	}
	is_sumtree(node -> right,flag);
}

int main()
{
	int v, n, i, flag = 0;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		root = insert(root,v);
	}
	is_sumtree(root,&flag);
	printf("This BT is a Sum Tree\n");
	return 0;
}
