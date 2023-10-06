#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#define SIZE 3

int matrix[SIZE][SIZE];
int rowsum[SIZE];
int colsum[SIZE];

typedef struct{
	int row;
	int col;
}MatrixIndex;

void RowSum(void *param)
{
	MatrixIndex *index = (MatrixIndex*)param;
	int row = index->row;
	int col = index->col;

	rowsum[row] = 0;
	for(int i=0; i<SIZE; i++)
		rowsum[row] += matrix[row][i];
}

void ColSum(void *param)
{
	MatrixIndex *index = (MatrixIndex*)param;
	int row = index->row;
	int col = index->col;

	colsum[col] = 0;
	for(int i=0; i<SIZE; i++)
		colsum[col] += matrix[i][col];
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

	printf("\n\nRow Sum: \n");
	for(int i=0; i<SIZE; i++)
		printf("Row %d: %d\n", i, rowsum[i]);

	printf("\n\n Column Sum: \n");
	for(int i=0; i<SIZE; i++)
		printf("Column %d: %d\n", i, colsum[i]);

	return 0;
}