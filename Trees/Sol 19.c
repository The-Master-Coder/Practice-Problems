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

void enqueue(struct bstnode *queue[],int *front,int *rear,struct bstnode *node)
{
	if (is_empty(front,rear)) {
		*front = *front + 1;
		*rear = *rear + 1;
	} else {
		*rear = *rear + 1;
	}
	queue[*rear] = node;
}

struct bstnode* dequeue(struct bstnode *queue[],int *front,int *rear)
{
	struct bstnode *temp;
	temp = queue[*front];
	if (*front == *rear) {
		*front = *rear = -1;
	} else {
		*front = *front + 1;
	}
	return temp;
}

int is_empty(int *front,int *rear)
{
	if (*front == -1 && *rear == -1) {
		return 1;
	} else {
		return 0;
	}
}


void BFS(struct bstnode *node,struct bstnode* queue[],int *front,int *rear)
{
	enqueue(queue,front,rear,node);
	while (!is_empty(front,rear)) {
		node = dequeue(queue,front,rear);
		printf("%d ",node -> data);
		if (node -> left != NULL) {
			enqueue(queue,front,rear,node -> left);
		}
		if (node -> right != NULL) {
			enqueue(queue,front,rear,node -> right);
		}
	}
}

int main()
{
	int v, n, i;
	struct bstnode *queue[100];
	int front = -1;
	int rear = -1;
	struct bstnode *root;
	root = NULL;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		root = insert(root,v);
	}
	printf("\n");
	BFS(root,queue,&front,&rear);
	printf("\n");
	return 0;

}
