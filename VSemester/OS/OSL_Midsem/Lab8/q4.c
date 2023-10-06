#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *odd_thread(void *arr)
{
	int *temp = (int*)arr;
	int n = temp[0];
	int sum = 0;

	for(int i=1; i<=n; i++)
		if(temp[i] % 2 == 1)
			sum += temp[i];

	return (void*)sum;
}

void *even_thread(void *arr)
{
	int *temp = (int*)arr;
	int n = temp[0];
	int sum = 0;

	for(int i=1; i<=n; i++)
		if(temp[i] % 2 == 0)
			sum += temp[i];

	return (void*)sum;
}

int main()
{
	int arr[20];
	void *even_sum, *odd_sum;
	int *temp;


	printf("Enter the size of the array: ");
	scanf("%d", &arr[0]);

	printf("Enter the array elements: ");
	for(int i=1; i<=arr[0]; i++)
		scanf("%d", &arr[i]);

	pthread_t thread_even;
	pthread_t thread_odd;
	pthread_create(&thread_even, 0, &even_thread, (void*)arr);
	pthread_create(&thread_odd, 0, &odd_thread, (void*)arr);
	pthread_join(thread_even, &even_sum);
	pthread_join(thread_odd, &odd_sum);

	temp = (int*)even_sum;
	printf("Sum of even numbers is: %d\n", temp);
	temp = (int*)odd_sum;
	printf("Sum of odd numbers is: %d\n", temp);

	return 0;
}