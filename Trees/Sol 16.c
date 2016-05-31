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

void search(struct bstnode* node,int value,int Arr[],int *t)
{
	Arr[*t] = node -> data;
	*t = *t + 1;
	if (node -> data == value) {
		return;
	} else if (value <= node -> data) {
		search(node -> left,value,Arr,t);
	} else {
		search(node -> right,value,Arr,t);
	}
}

int main()
{
	int v, n, i, v1, v2, t1 = 0, t2 = 0, c = 0, d;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	int A[n], B[n];
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		root = insert(root,v);
	}
	while(1) {
		scanf("%d", &v1);
		scanf("%d", &v2);
		search(root,v1,A,&t1);
		search(root,v2,B,&t2);
		while (A[c] == B[c]) {
			c++;
		}
		d = t1 - c + t2 - c;
		printf("%d\n",d);
		d = t1 = t2 = c = 0;
	}
	return 0;
}
