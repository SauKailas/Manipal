#include<stdio.h>

int opcount=0;

void Matrix_Mult(int mat1[][10], int mat2[][10], int res[][10], int n1, int n2, int m2){

	for(int i=0; i<n1; i++)
		for(int j=0; j<m2; j++)
		{
			res[i][j]=0;
			for(int k=0; k<n2; k++)
			{
				opcount++;
				res[i][j]+=mat1[i][k]*mat2[k][j];
			}
		}
}

int main()
{
	int n1, m1, n2, m2;
	int mat1[10][10], mat2[10][10], res[10][10];

	printf("Enter the dimensions of the first matrix:\n");
	scanf("%d %d", &n1, &m1);

	printf("Enter the dimensions of the second matrix:\n");
	scanf("%d %d", &n2, &m2);

	if(m1!=n2)
	{
		printf("Invalid dimensions!\n");
		exit(0);
	}

	printf("Enter the elements of the first matrix:\n");
	for(int i=0; i<n1; i++)
		for(int j=0; j<m1; j++)
			scanf("%d", &mat1[i][j]);

	printf("Enter the elements of the second matrix:\n");
	for(int i=0; i<n2; i++)
		for(int j=0; j<m2; j++)
			scanf("%d", &mat2[i][j]);

	Matrix_Mult(mat1, mat2, res, n1, n2, m2);

	printf("The resultant matrix is:\n");
	for(int i=0; i<n1; i++)
	{
		for(int j=0; j<n1; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}

	printf("The opcount is %d\n", opcount);

	return 0;
}