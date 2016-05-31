#include<stdio.h>
#include<stdlib.h>

#define white 0
#define gray 1
#define black 2

void push(int stack[],int item,int *head)
{
	*head = *head + 1;
	stack[*head] = item;
}

int pop(int stack[], int *head)
{
	int temp;
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

void DFS(int arr[100][100],int color[],int s,int v,int stack[],int *head)
{
	int current, i;
	push(stack,s,head);
	color[s - 1] = gray;
	while(!is_empty(head)) {
		current = pop(stack,head);
		printf("%d ",current);
		color[current - 1] = black;
		for(i = v - 1; i >= 0; i--) {
			if( arr[current - 1][i] == 1 && color[i] == white) {
				push(stack,i + 1,head);
				color[i] = gray;
			}
		}
	}
}
		
int main()
{
	int arr[100][100];
	int color[100] = {white};
	int stack[100];
	int head = -1;
	int i, j, v, s;
	scanf("%d", &v);
	scanf("%d", &s);
	
	for(i = 0; i < v; i++) {
		for(j = 0; j < v; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\n");
	DFS(arr,color,s,v,stack,&head);
	printf("\n");
	return 0;
}
