#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

int isPrime(int n)
{
	int count = 0;

	for(int i=1; i<=n; i++)
		if(n % i == 0)
			count++;

	if(count == 2)
		return 1;
	return 0;
}

void *thread_code(void *param)
{
	int *limits = (int*)param;

	printf("Primes between %d and %d: ", limits[0], limits[1]);
	for(int i=limits[0]; i<=limits[1]; i++)
		if(isPrime(i))
			printf("%d ", i);
	printf("\n");
}

int main()
{
	int limits[2];

	printf("Enter the start: ");
	scanf("%d", &limits[0]);

	printf("Enter the end: ");
	scanf("%d", &limits[1]);

	pthread_t thread;
	pthread_create(&thread, 0, &thread_code, (void*)limits);
	pthread_join(thread, 0);

	return 0;
}