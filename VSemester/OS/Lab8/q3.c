#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

int isPrime(int n)
{
	int c = 0;
	for(int i=1; i<=n; i++)
		if(n % i == 0)
			c++;
	if(c == 2)
		return 1;
	else
		return 0;
}

void *thread_prime(void *n)
{
	int sum = 0;
	int start = *((int *) n);
	int end = *(((int *)(n + sizeof(int))));

	printf("Prime Numbers are: ");

	for(int i=start; i<=end; i++)
		if(isPrime(i))
			printf("%d ", i);
	printf("\n");
}

int main()
{
	int n[2];

	printf("Enter the starting: ");
	scanf("%d", &n[0]);

	printf("Enter the ending: ");
	scanf("%d", &n[1]);

	printf("Thread created!\n");
	pthread_t thread;
	pthread_create(&thread, 0, &thread_prime, (void*)&n);
	pthread_join(thread, 0);

	return 0;
}