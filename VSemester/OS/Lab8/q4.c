#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *thread_sum_even(void *arr)
{
	int *temp = (int*)arr;
	int n = temp[0];
	int *sum = (int*)malloc(sizeof(int));
	*sum = 0;

	for(int i=1; i<=n; i++)
		if(temp[i] % 2 == 0)
			*sum += temp[i];
	return (void*)sum;
}

void *thread_sum_odd(void *arr)
{
	int *temp = (int*)arr;
	int n = temp[0];
	int *sum = (int*)malloc(sizeof(int));
	*sum = 0;

	for(int i=1; i<=n; i++)
		if(temp[i] % 2 == 1)
			*sum += temp[i];
	return (void*)sum;
}

int main()
{
	int n;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int *arr = (int*)calloc(n+1, sizeof(int));
	int *res_even, *res_odd;

	arr[0] = n;

	printf("Enter the elements:\n");
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);

	pthread_t thread_even;
	pthread_t thread_odd;
	pthread_create(&thread_even, 0, &thread_sum_even, (void*)arr);
	pthread_create(&thread_odd, 0, &thread_sum_odd, (void*)arr);
	pthread_join(thread_even, (void**)&res_even);
	pthread_join(thread_odd, (void**)&res_odd);

	printf("Sum of Even Numbers is %d\n", *res_even);
	printf("Sum of Odd Numbers is %d\n", *res_odd);

	return 0;
}