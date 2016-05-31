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

void inorder(struct bstnode *node)
{
	if (node == NULL) {
		return;
	}
	inorder(node -> left);
	printf("%d ",node -> data);
	inorder(node -> right);
}

int find_min(struct bstnode* node)
{
	if (node == NULL) {
		return -99;
	} else if (node -> left == NULL) {
		return node -> data;
	}
	return find_min(node -> left);
}

struct bstnode* delete(struct bstnode *root)
{
	if (root == NULL) {
		return root;
	}
	else if (root -> left == NULL && root -> right == NULL) {
		free(root);
		root = NULL;
	} else if (root -> left == NULL) {
		struct bstnode *temp;
		temp = root;
		root = root -> right;
		free(temp);
	} else if (root -> right == NULL) {
		struct bstnode *temp;
		temp = root;
		root = root -> left;
		free(temp);
	} else {
		int min;
		min = find_min(root -> right);
		root -> data = min;
		root -> right = delete(root -> right);
	}
	return root;
}

int main()
{
	int v, v1, n, i, x, choice;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		root = insert(root,v);
	}
	for(i = 0; i < n; i++) {
		root = delete(root);
		inorder(root);
		printf("\n");	
	}
	return 0;
}
