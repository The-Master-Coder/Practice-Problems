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

void inorder(struct bstnode *node,int A[],int *c)
{
	if (node == NULL) {
		return;
	}
	inorder(node -> left,A,c);
	A[*c] = node -> data;
	*c = *c + 1;
	inorder(node -> right,A,c);
}

int getsuccessor(int value,int A[],int c)
{
	if (value == A[c - 1] || value > A[c - 1]) {
		return -99;
	}
	int x = 0;
	while (A[x] != value && x < c - 1) {
		x++;
	}
	if (x == c - 1) {
		return -99;
	} else {
		return A[x + 1];
	}
}

int getpredecessor(int value,int A[],int c)
{
	if (value == A[0] || value < A[0]) {
		return -99;
	}
	int x = 1;
	while (A[x] != value && x < c) {
		x++;
	}
	if (x == c) {
		return -99;
	} else {
		return A[x - 1];
	}
}


int main()
{
	int choice, v1, v2, v3, n, i, j, k;
	int c = 0;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	int A[n];
	for(i = 0; i < n; i++) {
		scanf("%d", &v1);
		root = insert(root,v1);
	}
	inorder(root,A,&c);
	while(1) {
		printf("Choices:\n");
		printf("1. Inorder successor of node with value 'x'\n");
		printf("2. Inorder predecessor of node with value 'x'\n");
		printf("3. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:	
				printf("Enter the value of node of which the successor is required\n");
				scanf("%d", &v2);
				j = getsuccessor(v2,A,c);
				if (j == -99) {
					printf("%d has no inorder successor or it doesnot exist in the BST\n",v2);
				} else {
					printf("Successor of %d is: %d\n",v2,j);
				}
				break;
			case 2:	
				printf("Enter the value of node of which the predecessor is required\n");
				scanf("%d", &v3);
				k = getpredecessor(v3,A,c);
				if (k == -99) {
					printf("%d has no inorder predecessor or it doesnot exist in the BST\n",v3);
				} else {
					printf("Predecessor of %d is: %d\n",v3,k);
				}
				break;
			case 3:
				exit(1);
		}
	}
	return 0;
}
