#include<stdio.h>

void Matrix_Multiplication(int m1[][10], int m2[][10], int res[][10], int n){

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			res[i][j]=0;
			for(int k=0;  k<n; k++)
				res[i][j]=res[i][j]+m1[i][k]*m2[k][i];
		}
}

int main()
{
	int m1[10][10], m2[10][10], res[10][10], n;

	printf("Enter the value of n:\t");
	scanf("%d", &n);

	printf("Enter the elements of first matrix:\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &m1[i][j]);

	printf("Enter the elements of second matrix:\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &m2[i][j]);

		Matrix_Multiplication(m1, m2, res, n);

	printf("The product matrix is:\n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}

	return 0;
}