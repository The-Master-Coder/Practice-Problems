#include<stdio.h>
#include<stdlib.h>

#define white 0
#define gray 1
#define black 2
	
int main()
{
	int arr[100][100];
	int color[100] = {white};
	int i, j, v;
	scanf("%d", &v);
	
	for(i = 0; i < v; i++) {
		for(j = 0; j < v; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	for(i = 0; i < v; i++) {
		for(j = 0; j < v; j++) {
			if (arr[i][j] == 1 && color[j] == white) {
				printf("%d %d\n",i + 1,j + 1);
			}
		}
		color[i] = gray;
	}
	return 0;
}
