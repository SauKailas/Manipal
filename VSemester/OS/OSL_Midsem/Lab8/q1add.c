#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#define SIZE 3

int m1[SIZE][SIZE];
int m2[SIZE][SIZE];
int res[SIZE][SIZE];

typedef struct{
	int row;
	int col;
}MatrixIndex;

void Multiply(void *param)
{
	MatrixIndex *index = (MatrixIndex*)param;
	int row = index->row;
	int col = index->col;

	for(int i=0; i<SIZE; i++)
		res[row][col] += m1[row][i] * m2[i][col];
}

int main()
{
	pthread_t threads[SIZE][SIZE];

	printf("Enter the elements of matrix 1: ");
	for(int i=0; i<SIZE; i++)
		for(int j=0; j<SIZE; j++)
			scanf("%d", &m1[i][j]);

	printf("Enter the elements of matrix 2: ");
	for(int i=0; i<SIZE; i++)
		for(int j=0; j<SIZE; j++)
			scanf("%d", &m2[i][j]);

	for(int i=0; i<SIZE; i++)
		for(int j=0; j<SIZE; j++)
		{
			MatrixIndex *index = malloc(sizeof(MatrixIndex));
			index->row = i;
			index->col = j;
			pthread_create(&threads[i][j], 0, Multiply, (void*)index);
		}

	for(int i=0; i<SIZE; i++)
		for(int j=0; j<SIZE; j++)
			pthread_join(threads[i][j], 0);

	printf("\n\nResultant Matrix:\n");
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}

	return 0;
}	