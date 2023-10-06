#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int isPrime(int n)
{
	int c = 0;

	for(int i=1; i<=n; i++)
		if(n % i == 0)
			c++;

	if(c == 2)
		return 1;
	return 0;
}

void thread_code(void *limits)
{
	int *temp = (int*)limits;
	int start = temp[0];
	int end = temp[1];

	printf("Prime Numbers b/w %d and %d: ", start, end);
	for(int i=start; i<=end; i++)
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