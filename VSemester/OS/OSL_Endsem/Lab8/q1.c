#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *thread_code(void *param)
{
	int n = (int*)param;
	int arr[n];

	arr[0] = 0;
	arr[1] = 1;

	for(int i=2; i<n; i++)
		arr[i] = arr[i-1] + arr[i-2];

	int *res = (int*)calloc(n, sizeof(int));
	memcpy(res, arr, n*sizeof(int));
	return res;
}

int main()
{
	int n;
	void *arr;
	int *temp;

	printf("Enter the number of terms: ");
	scanf("%d", &n);

	pthread_t thread;
	pthread_create(&thread, 0, &thread_code, (void*)n);
	pthread_join(thread, &arr);

	temp = (int*)arr;

	for(int i=0; i<n; i++)
		printf("%d ", temp[i]);
	printf("\n");

	return 0;
}