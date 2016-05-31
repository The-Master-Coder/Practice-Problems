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

void print_k(struct bstnode *node,int k,int h)
{
	int temp;
	if (node == NULL) {
		return;
	}
	print_k(node -> left,k,h);
	temp = height(node);
	printf("%d\n",temp);
	if (temp == h - k) {
		printf("%d ",node -> data);
	}
	print_k(node -> right,k,h);
}

int main()
{
	int v, n, i, k, h;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		root = insert(root,v);
	}
	scanf("%d", &k);
	h = height(root);
	print_k(root,k,h);
	return 0;
}
