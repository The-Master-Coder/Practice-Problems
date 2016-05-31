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

int height(struct bstnode *node)
{
	int l, r;
	if (node == NULL) {
		return -1;
	}
	l = height(node -> left);
	r = height(node -> right);
	if (l > r) {
		return l + 1;
	} else {
		return r + 1;
	}
}

int search(struct bstnode* node,int value,int *c,int C[],int *x)
{
	int h;
	if (node -> data == value) {
		h = height(node);
		C[*x] = h;
		*x = *x + 1;
		return *c;
	} else if (value <= node -> data) {
		*c = *c + 1;
		return search(node -> left,value,c,C,x);
	} else {
		*c = *c + 1;
		return search(node -> right,value,c,C,x);
	}
}

void depth(struct bstnode* root,int n,int A[],int B[],int C[])
{
	int c = 0, i, t, x = 0;
	for(i = 0; i < n; i++) {
		B[i] = search(root,A[i],&c,C,&x);
		c = 0;
	}
}

int main()
{
	int v, n, i, k;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	int A[n], B[n], C[n];
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		A[i] = v;
		root = insert(root,v);
	}
	depth(root,n,A,B,C);
	for(i = 0; i < n; i++) {
		printf("%d %d %d\n",A[i],B[i],C[i]);
	}
	return 0;
}
