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

int main()
{
	int v1, v2, n1, n2, i, x;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n1);
	for(i = 0; i < n1; i++) {
		scanf("%d", &v1);
		root = insert(root,v1);
	}
	scanf("%d", &n2);
	for(i = 0; i < n2; i++) {
		scanf("%d", &v2);
		x = search(root,v2);
		if (x == 1) {
			printf("y\n");
		} else {
			printf("n\n");
		}
	}			
	return 0;
}
