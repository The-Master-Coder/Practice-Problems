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

int search(struct bstnode* node,int value,int *c)
{
	if (node -> data == value) {
		return *c;
	} else if (value <= node -> data) {
		*c = *c + 1;
		return search(node -> left,value,c);
	} else {
		*c = *c + 1;
		return search(node -> right,value,c);
	}
}

void depth(struct bstnode* root,int n,int A[],int B[])
{
	int c = 0, i, t;
	for(i = 0; i < n; i++) {
		B[i] = search(root,A[i],&c);
		c = 0;
	}
}

int main()
{
	int v, n, i, k;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	int A[n], B[n];
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		A[i] = v;
		root = insert(root,v);
	}
	scanf("%d", &k);
	depth(root,n,A,B);
	for(i = 0; i < n; i++) {
		if (B[i] == k) {
			printf("%d ", A[i]);
		}
	}
	printf("\n");
	return 0;
}
