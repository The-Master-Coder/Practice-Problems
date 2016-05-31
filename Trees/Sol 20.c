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

void inorder_array(struct bstnode *node,int A[],int *t)
{
	if (node == NULL) {
		return;
	}
	inorder_array(node -> left,A,t);
	A[*t] = node -> data;
	*t = *t + 1;
	inorder_array(node -> right,A,t);
}

void preorder(struct bstnode *node)
{
	if (node == NULL) {
		return;
	}
	printf("%d ",node -> data);
	preorder(node -> left);
	preorder(node -> right);
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

void postorder(struct bstnode *node)
{
	if (node == NULL) {
		return;
	}
	postorder(node -> left);
	postorder(node -> right);
	printf("%d ",node -> data);
}

void print_bst(struct bstnode *root)
{
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n\n");
}

int main()
{
	int v, n, i, j, t = 0;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	int A[n];
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		root = insert(root,v);
	}
	inorder_array(root,A,&t);
	printf("\n");
	print_bst(root);
	for(i = 0; i < n; i++) {
		if((i == 0) || (i > 0 && A[i] != A[i - 1])) {	
			for(j = i + 1; j < n; j++) {
				if(A[i] == A[j]) {
					root = delete(root,A[j]);
				} else {
					break;
				}
			}
		}
	}
	print_bst(root);
	return 0;
}
