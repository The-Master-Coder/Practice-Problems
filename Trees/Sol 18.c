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

void push(struct bstnode* stack[],struct bstnode* node,int *head)
{
	*head = *head + 1;
	stack[*head] = node;
}

struct bstnode* pop(struct bstnode* stack[], int *head)
{
	struct bstnode *temp;
	temp = stack[*head];
	*head = *head - 1;
	return temp;
}

int is_empty(int *head)
{
	if (*head == -1) {
		return 1;
	} else {
		return 0;
	}
}


void DFS(struct bstnode *node,struct bstnode* stack[],int *head)
{
	push(stack,node,head);
	printf("%d ",node -> data);
	while (node -> left != NULL) {
		node = node -> left;
		push(stack,node,head);
		printf("%d ",node -> data);
	}
	while(!is_empty(head)) {
		node = pop(stack,head);
		if(node -> right != NULL) {
			push(stack,node -> right,head);
			printf("%d ",node -> right -> data);
		}
	}
}

int main()
{
	int v, n, i;
	struct bstnode *stack[100];
	int head = -1;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		root = insert(root,v);
	}
	printf("\n");
	DFS(root,stack,&head);
	printf("\n");
	return 0;
}
