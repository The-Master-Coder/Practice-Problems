#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	int rank;
	struct node *parent;
};

void make_set(int value,struct node *A[])
{
	if(A[value] != NULL) {
		return;
	}
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = value;
	temp -> rank = 0;
	temp -> parent = temp;
	A[value] = temp;
}

struct node* find_set(int value,struct node *A[])
{
	struct node *temp1, *temp2, *temp3;
	temp1 = A[value];
	while(temp1 -> parent != temp1) {
		temp1 = temp1 -> parent;
	}
	temp2 = A[value];
	while(temp2 -> parent != temp1) {
		temp3 = temp2 -> parent;
		temp2 -> parent = temp1;
		temp2 = temp3;
	}
	return temp1;
}

void unionn(int v1,int v2,struct node *A[])
{
	int x, y;
	if (A[v2] == NULL) {
		return;
	}
	if (v1 == v2) {
		return;
	}
	struct node *temp1, *temp2;
	temp1 = find_set(v1,A);
	temp2 = find_set(v2,A);
	if (temp1 -> data != temp2 -> data) {
		if (temp1 -> rank > temp2 -> rank || temp1 -> rank == temp2 -> rank) {
			temp2 -> parent = temp1;
			if (temp1 -> rank == temp2 -> rank) {
				temp1 -> rank = temp1 -> rank + 1;
			} 
		} else {
			temp1 -> parent = temp2;
		}
	}
}

void connected_or_not(struct node *A[],int n,int B[n][n])
{
	int i, j, k, x, flag = 0;
	for(i = 1; i <= n; i++) {
		make_set(i,A);
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(B[i][j] == 1) {
				unionn(i + 1, j + 1, A);
			}
		}
	}
	x = find_set(1,A) -> data;
	for(i = 2; i <= n; i++) {
		if (find_set(i,A) -> data != x) {
			flag = 1;
			break;
		} else {
			flag = 2;
		}
	}
	if (flag == 2) {
		printf("This Graph is connected\n");
	} else {
		printf("This Graph is not connected\n");
	}
}

int main()
{
	int t, n, i, j, k, l;
	scanf("%d", &t);
	for(i = 0 ; i < t; i++) {
		scanf("%d", &n);
		struct node *A[2 * n];
		for(l = 0; l < 2 * n; l++) {
			A[l] = NULL;
		}
		int B[n][n];
		for(j = 0; j < n; j++) {
			for(k = 0; k < n; k++) {
				scanf("%d", &B[j][k]);
			}
		}
		connected_or_not(A,n,B);
	}
	return 0;
}
