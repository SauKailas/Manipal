#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void* thread_code(void *arr)
{
	int *temp = (int*)arr;
	int n = temp[0];
	int sum = 0;

	for(int i=1; i<=n; i++)
		if(temp[i] >= 0)
			sum += temp[i];

	return (void*)sum;
}

int main()
{
	int n;
	int arr[20];
	void *sum;
	int *temp;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	arr[0] = n;
	printf("Enter the elements: ");
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);

	pthread_t thread;
	pthread_create(&thread, 0, &thread_code, (void*)arr);
	pthread_join(thread, &sum);

	temp = (int*)sum;

	printf("Sum of nonnegative numbers is: %d\n", temp);

	return 0;
}