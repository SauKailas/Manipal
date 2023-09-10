#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *thread_func(void *n)
{
	int size = *((int *)n);
	int arr[size];
	arr[0] = 0;
	arr[1] = 1;

	for(int i=2; i<size; i++)
		arr[i] = arr[i-1] + arr[i-2];

	int *res = (int*)calloc(size, sizeof(int));
    memcpy(res, arr, sizeof(int) * size);

	return res;
}

int main()
{
	int n;
	void *arr;

	printf("Enter the number of terms: ");
	scanf("%d", &n);

	pthread_t thread;
	pthread_create(&thread, 0, &thread_func, (void *)&n);
	printf("Thread Created!\n");

	pthread_join(thread, &arr);

	int *arr2 = arr;

	for(int i=0; i<n; i++)
		printf("%d ", (int)arr2[i]);
	printf("\n");

	return 0;
}