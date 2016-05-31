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

struct node* find_parent(int value,struct node *A[])
{
	return(A[value] -> parent);
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

void display(int value,struct node *A[])
{
	struct node *temp;
	temp = A[value];
	while (temp -> parent != temp) {
		printf("%d ", temp -> data);
		temp = temp -> parent;
	}
	printf("%d\n", temp -> data);
}

int main()
{
	int choice, value, v1, v2, i;
	struct node *A[100];
	struct node *temp;
	for(i = 0; i < 100; i++) {
		A[i] = NULL;
	}
	while (1) {
		printf("Choices:\n");
		printf("1. Make set for an element\n");
		printf("2. Find set for an element\n");
		printf("3. Find parent of an element\n");
		printf("4. Union of two sets\n");
		printf("5. Display the set\n");
		printf("6. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value for the set\n");
				scanf("%d", &value);
				make_set(value,A);
				break;
			case 2:
				printf("Enter the value for which you want the set representative\n");
				scanf("%d", &value);
				temp = find_set(value,A);
				printf("%d\n", temp -> data);
				break;
			case 3:
				printf("Enter the value for which you want the parent\n");
				scanf("%d", &value);
				temp = find_parent(value,A);
				printf("%d\n", temp -> data);
				break;
			case 4:
				printf("Enter element 1 and element 2\n");
				scanf("%d %d",&v1,&v2);
				unionn(v1,v2,A);
				break;
			case 5:
				printf("Enter the first element of the set you want to display\n");
				scanf("%d", &value);
				display(value,A);
				break;
			case 6:
				exit(1);
			default:
				printf("Invalid choice!\n");
		}
		
	}
	return 0;
}
