#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *even_code(void *param)
{
	int *arr = (int*)param;
	int n = arr[0];
	int sum = 0;

	for(int i=1; i<=n; i++)
		if(arr[i] % 2 == 0)
			sum += arr[i];
	return (void*)sum;
}

void *odd_code(void *param)
{
	int *arr = (int*)param;
	int n = arr[0];
	int sum = 0;

	for(int i=1; i<=n; i++)
		if(arr[i] % 2 == 1)
			sum += arr[i];
	return (void*)sum;
}

int main()
{
	int n;
	int arr[20];
	void *even_sum, *odd_sum;
	int *temp;

	printf("Enter the number of elements: ");
	scanf("%d", &n);
	arr[0] = n;

	printf("Enter the elements: ");
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);

	pthread_t even_thread;
	pthread_t odd_thread;
	pthread_create(&even_thread, 0, &even_code, (void*)arr);
	pthread_create(&odd_thread, 0, &odd_code, (void*)arr);
	pthread_join(even_thread, &even_sum);
	pthread_join(odd_thread, &odd_sum);

	temp = (int*)even_sum;
	printf("Sum of Even Numbers: %d\n", temp);

	temp = (int*)odd_sum;
	printf("Sum of Odd Numbers: %d\n", temp);

	return 0;
}