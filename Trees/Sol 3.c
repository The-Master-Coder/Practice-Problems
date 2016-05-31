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

void preorder(struct bstnode *node,int Arr[],int *i)
{
	if (node == NULL) {
		return;
	}
	Arr[*i] = node -> data;
	*i = *i + 1;
	preorder(node -> left,Arr,i);
	preorder(node -> right,Arr,i);
}

int main()
{
	int v, n, i, j, k, l, m, t, p;
	int A[2*n], B[2*n];
	int a = 0, b = 0;
	int flag = 0;
	struct bstnode* root1;
	struct bstnode* root2;
	scanf("%d", &t);
	scanf("%d", &n);
	for(i = 0; i < t; i++) {
		root1 = NULL;
		root2 = NULL;
		for(j = 0; j < n; j++) {
			scanf("%d", &v);
			root1 = insert(root1,v);
		}
		for(k = 0; k < n; k++) {
			scanf("%d", &v);
			root2 = insert(root2,v);
		}
		preorder(root1,A,&a);
		preorder(root2,B,&b);
		for(p = 0; p < a; p++) {
			if (A[p] != B[p]) {
				flag = 1;
				break;
			} else {
				flag = 2;
			}
		}
		if (flag == 1) {
			printf("n\n");
		} else {
			printf("y\n");
		}
		a = b = 0;
	}		
	return 0;
}
