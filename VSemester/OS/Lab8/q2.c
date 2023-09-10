#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *thread_nonneg(void *arr)
{
	int *temp = (int*)arr;
	int n = temp[0];
	int *sum = (int*)malloc(sizeof(int));
	*sum = 0;

	for(int i=1; i<=n; i++)
		if(temp[i] >= 0)
			*sum += temp[i];
	return (void*)sum;
}

int main()
{
	int n;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int *arr = (int*)calloc(n+1, sizeof(int));
	int *res;

	arr[0] = n;

	printf("Enter the elements:\n");
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);

	pthread_t thread;
	pthread_create(&thread, 0, &thread_nonneg, (void*)arr);
	pthread_join(thread, (void**)&res);

	printf("Sum of Non-Negative Numbers is %d\n", *res);

	return 0;
}