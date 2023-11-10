#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex, full, empty, atmost10;
int buffer[10];
int front = 0, rear = 0;
int produced = 0, consumed = 0;

void *producer()
{
	while(1)
	{
		sem_wait(&atmost10);
		sem_wait(&empty);
		sem_wait(&mutex);
		printf("Produced: %d\n", produced);
		buffer[(rear++)%10] = produced;
		produced++;
		sleep(1);
		sem_post(&mutex);
		sem_post(&full);
	}
}

void *consumer()
{
	int item;

	while(1)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		item = buffer[(front++)%10];
		printf("Consumed: %d\n", item);
		consumed++;
		sem_post(&mutex);
		sem_post(&empty);
		if(produced - consumed <= 10)
			sem_post(&atmost10);
		sleep(1);
	}
}

int main()
{
	sem_init(&mutex, 0, 1);
	sem_init(&atmost10, 0, 10);
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, 1);

	pthread_t t1, t2;
	pthread_create(&t1, 0, &producer, NULL);
	pthread_create(&t2, 0, &consumer, NULL);
	pthread_join(t1, 0);
	pthread_join(t2, 0);

	return 0;
}