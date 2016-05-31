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

int find_min(struct bstnode* node)
{
	if (node == NULL) {
		return -99;
	} else if (node -> left == NULL) {
		return node -> data;
	}
	return find_min(node -> left);
}

struct bstnode* delete(struct bstnode *node,int value)
{
	if (node == NULL) {
		return node;
	} else if (value < node -> data) {
		node -> left = delete(node -> left,value);
	} else if (value > node -> data) {
		node -> right = delete(node -> right,value);
	} else {
		if (node -> left == NULL && node -> right == NULL) {
			free(node);
			node = NULL;
		} else if (node -> left == NULL) {
			struct bstnode *temp;
			temp = node;
			node = node -> right;
			free(temp);
		} else if (node -> right == NULL) {
			struct bstnode *temp;
			temp = node;
			node = node -> left;
			free(temp);
		} else {
			int min;
			min = find_min(node -> right);
			node -> data = min;
			node -> right = delete(node -> right,min);
		}
	}
	return node;
}

struct bstnode* leafs(struct bstnode *node,struct bstnode *root)
{
	if (node == NULL) {
		return root;
	}
	if (node -> left == NULL && node -> right == NULL) {
		root = delete(root,node -> data);
		return root;
	}
	leafs(node -> left,root);
	leafs(node -> right,root);
	return root;
}

int main()
{
	int v1, v2, n, i, x, choice;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &v1);
		root = insert(root,v1);
	}
	root = leafs(root,root);
	while(1) {
		printf("Choices:\n");
		printf("1. Search for an element in the BST\n");
		printf("2. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to be searched\n");
				scanf("%d", &v2);
				x = search(root,v2);
				if (x == 1) {
					printf("Node with value %d found!!\n",v2);
				} else {
					printf("Node with value %d not found!!\n",v2);
				}
				break;
			case 2:
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
