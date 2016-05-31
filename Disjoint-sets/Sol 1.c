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

void display(int value,struct node *A[])
{
	struct node *temp;
	temp = A[value] -> repr;
	while (temp != NULL) {
		printf("%d ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
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
		printf("3. Union of two sets\n");
		printf("4. Display the set\n");
		printf("5. Exit\n");
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
				printf("Enter element 1 and element 2\n");
				scanf("%d %d",&v1,&v2);
				unionn(v1,v2,A);
				break;
			case 4:
				printf("Enter the first element of the set you want to display\n");
				scanf("%d", &value);
				display(value,A);
				break;
			case 5:
				exit(1);
			default:
				printf("Invalid choice!\n");
		}
		
	}
	return 0;
}
