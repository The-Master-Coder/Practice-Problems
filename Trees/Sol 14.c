#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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

int isbst_util(struct bstnode* node,int minvalue,int maxvalue)
{
	if (node == NULL) {
		return 1;
	}
	if (node -> data > minvalue && node -> data < maxvalue && isbst_util(node -> left,minvalue,node -> data) && isbst_util(node -> right,node -> data,maxvalue)) {
		return 1;
	} else {
		return -1;
	}
}

int isbst(struct bstnode *node)
{
	return isbst_util(node,INT_MIN,INT_MAX);
}

int main()
{
	int choice, v1, x;
	struct bstnode* root;
	root = NULL;
	
	while(1) {
		printf("Choices:\n");
		printf("1. Insert an element in the BST\n");
		printf("2. Find if the BT is a BST\n");
		printf("3. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to be inserted\n");
				scanf("%d", &v1);
				root = insert(root,v1);
				break;
			case 2:
				x = isbst(root);
				if (x == -1) {
					printf("The Present BT is not a BST!!\n");
				} else {
					printf("The Present BT is a BST!!!\n");
				}
				break;
			case 3:
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
