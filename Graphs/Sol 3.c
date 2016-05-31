#include<stdio.h>
#include<stdlib.h>

#define white 0
#define gray 1
#define black 2

void enqueue(int queue[],int *front,int *rear,int data)
{
	if (is_empty(front,rear)) {
		*front = *front + 1;
		*rear = *rear + 1;
	} else {
		*rear = *rear + 1;
	}
	queue[*rear] = data;
}

int dequeue(int queue[],int *front,int *rear)
{
	int temp;
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

void BFS(int arr[100][100],int color[],int s,int v,int queue[],int *front,int *rear,int A[], int *t)
{
	int current, i;
	enqueue(queue,front,rear,s - 1);
	color[s - 1] = gray;
	while(!is_empty(front,rear)) {
		current = dequeue(queue,front,rear);
		A[*t] = current + 1;
		*t = *t + 1;
		for(i = 0 ; i < v; i++) {
			if( arr[current][i] == 1 && color[i] == white) {
				enqueue(queue,front,rear,i);
				color[i] = gray;
			}
		}
		color[i] = black;
	}
}
		
int main()
{
	int arr[100][100];
	int color[100] = {white};
	int queue[100];
	int front = -1;
	int rear = -1;
	int i, j, v, n1, n2, t = 0, flag = 0;
	scanf("%d", &v);
	scanf("%d", &n1);
	scanf("%d", &n2);
	int A[v];
	for(i = 0; i < v; i++) {
		for(j = 0; j < v; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	BFS(arr,color,n1,v,queue,&front,&rear,A,&t);
	for(i = 0; i < t; i++) {
		if (A[i] == n2) {
			flag = 1;
			break;
		} else {
			flag = 2;
		}
	}
	if (flag == 1) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
