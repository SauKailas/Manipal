#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#define SIZE 3

int matrix[SIZE][SIZE];
int rowSum[SIZE];
int colSum[SIZE];

typedef struct{
	int row;
	int col;
}MatrixIndex;

void RowSum(void *param)
{
	MatrixIndex *index = (MatrixIndex*)param;
	int row = index->row;

	rowSum[row] = 0;
	for(int i=0; i<SIZE; i++)
		rowSum[row] += matrix[row][i];
}

void ColSum(void *param)
{
	MatrixIndex *index = (MatrixIndex*)param;
	int col = index->col;

	colSum[col] = 0;
	for(int i=0; i<SIZE; i++)
		colSum[col] += matrix[i][col];
}

int main()
{
	pthread_t threads[SIZE][SIZE];

	printf("Enter the elements of the matrix: ");
	for(int i=0; i<SIZE; i++)
		for(int j=0; j<SIZE; j++)
			scanf("%d", &matrix[i][j]);

	for(int i=0; i<SIZE; i++)
		for(int j=0; j<SIZE; j++)
		{
			MatrixIndex *index = malloc(sizeof(MatrixIndex));
			index->row = i;
			index->col = j;
			pthread_create(&threads[i][j], 0, RowSum, (void*)index);
		}

	for(int i=0; i<SIZE; i++)
		for(int j=0; j<SIZE; j++)
			pthread_join(threads[i][j], 0);

	for(int i=0; i<SIZE; i++)
		for(int j=0; j<SIZE; j++)
		{
			MatrixIndex *index = malloc(sizeof(MatrixIndex));
			index->row = i;
			index->col = j;
			pthread_create(&threads[i][j], 0, ColSum, (void*)index);
		}

	for(int i=0; i<SIZE; i++)
		for(int j=0; j<SIZE; j++)
			pthread_join(threads[i][j], 0);

	printf("\nRow Sums: \n");
	for(int i=0; i<SIZE; i++)
		printf("Row %d: %d\n", i, rowSum[i]);

	printf("\nCol Sum: \n");
	for(int i=0; i<SIZE; i++)
		printf("Col %d: %d\n", i, colSum[i]);

	return 0;
}