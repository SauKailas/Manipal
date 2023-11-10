#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *thread_code(void *param)
{
	int *arr = (int*)param;
	int n = arr[0];
	int sum = 0;

	for(int i=1; i<=n; i++)
		if(arr[i] >= 0)
			sum += arr[i];
	return (void*)sum;
}

int main()
{
	int n;
	int *arr;
	void *ans;
	
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	arr[0] = n;

	printf("Enter the elements: ");
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);

	pthread_t thread;
	pthread_create(&thread, 0, &thread_code, (void*)arr);
	pthread_join(thread, &ans);

	int temp = (int*)ans;
	printf("Sum of Non-Negative Integers: %d\n", temp);

	return 0;
}