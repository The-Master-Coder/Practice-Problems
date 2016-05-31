#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *repr;
};

void make_set(int value,struct node *A[])
{
	if(A[value] != NULL) {
		return;
	}
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = value;
	temp -> next = NULL;
	temp -> repr = temp;
	A[value] = temp;
}

struct node* find_set(int value,struct node *A[])
{
	return (A[value] -> repr);
}

void unionn(int v1,int v2,struct node *A[])
{
	if (A[v2] == NULL) {
		return;
	}
	if (v1 == v2) {
		return;
	}
	struct node *temp1, *temp2;
	temp1 = A[v1];
	temp2 = A[v2] -> repr;
	
	if (temp1 -> repr -> data != temp2 -> data) {
		while(temp1 -> next != NULL) {
			temp1 = temp1 -> next;
		}
		temp1 -> next = temp2;
		while (temp2 != NULL) {
			temp2 -> repr = A[v1] -> repr;
			temp2 = temp2 -> next;
		}
	}
}

void connected_components(struct node *A[],int n,int B[n][n])
{
	int i, j, k, c = 0;
	int C[2 * n];
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
	for(i = 1; i <= n; i++) {
		if (A[i] -> repr == A[i]) {
			C[c] = A[i] -> data;
			c++;
		}
	}
	printf("No. of Connected Components are : %d\n",c);
	for(i = 0; i < c; i++) {
		printf("%d ",C[i]);
	}
	printf("\n");
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
		connected_components(A,n,B);
	}
	return 0;
}
