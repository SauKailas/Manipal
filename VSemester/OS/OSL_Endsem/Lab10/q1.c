#include<stdio.h>

int getNum(int arr[], int n)
{
	int num = 0;

	for(int i=0; i<n; i++)
	{
		num *= 10;
		num += arr[i];
	}
	return num;
}

int main()
{
	int n, m, flag;

	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("Enter the number or resource types: ");
	scanf("%d", &m);

	int max[n][m], allocation[n][m], need[n][m];
	int available[m];

	printf("Enter the maximum matrix:\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &max[i][j]);

	printf("Enter the allocation matrix:\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &allocation[i][j]);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			need[i][j] = max[i][j] - allocation[i][j];

	printf("Enter the available array:\n");
	for(int i=0; i<m; i++)
		scanf("%d", &available[i]);

	int work[m];
	for(int i=0; i<m; i++)
		work[i] = available[i];

	int finish[n];
	for(int i=0; i<n; i++)
		finish[i] = 0;


	STEP2:

	for(int i=0; i<n; i++)
	{
		if(finish[i] == 0)
		{
			flag = 0;

			if(getNum(need[i], m) <= getNum(work, m))
				flag = 1;

			if(flag == 1)
			{
				STEP3:

				for(int j=0; j<m; j++)
					work[j] += allocation[i][j];
				finish[i] = 1;
				goto STEP2;
			}
		}
	}

	STEP4:

	flag = -1;

	for(int i=0; i<n; i++)
		if(finish[i] != 1)
		{
			flag = i;
			break;
		}

	if(flag == -1)
		printf("System in SAFE state!\n");
	else
		printf("System in DEADLOCKED state by process %d!\n", flag);

	return 0;

}