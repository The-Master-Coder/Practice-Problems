#include<stdio.h>
#include<stdlib.h>

#define white 0
#define gray 1
#define black 2

void enqueue(int queue[],int *front,int *rear,int data)
{
	if ((*front) == -1 && (*rear) == -1) {
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

void BFS(int arr[100][100],int color[],int s,int v,int queue[],int *front,int *rear)
{
	int current, i;
	enqueue(queue,front,rear,s);
	color[s - 1] = gray;
	while(!is_empty(front,rear)) {
		current = dequeue(queue,front,rear);
		color[current - 1] = black;
		for(i = 0 ; i < v; i++) {
			if( arr[current - 1][i] == 1 && color[i] == white) {
				enqueue(queue,front,rear,i + 1);
				color[i] = gray;
			}
		}
	}
}
		
int main()
{
	int arr[100][100];
	int color[100] = {white};
	int queue[100];
	int front = -1;
	int rear = -1;
	int i, j, v, c = 0;
	scanf("%d", &v);
	
	for(i = 0; i < v; i++) {
		for(j = 0; j < v; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\n");
	for(i = 0; i < v; i++) {
		if (color[i] == white) {
			BFS(arr,color,i + 1,v,queue,&front,&rear);
			c++;
		}
	}
	printf("%d\n",c);
	return 0;
}
