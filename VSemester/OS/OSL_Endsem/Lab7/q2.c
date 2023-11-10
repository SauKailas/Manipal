#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex, wrt;
int readCount = 0;

void *reader()
{
    while(1)
    {
        sem_wait(&mutex);                 // If mutex value is 0 or less, then it will wait until it becomes greater than 0
        readCount++;
        if(readCount == 1)
            sem_wait(&wrt);               // Decreases wrt to 0 so no writer can write
        sem_post(&mutex);                 // Multiple readers can read at a time
        printf("Reader %d is reading...\n", readCount);
        sleep(1);
        sem_wait(&mutex);
        readCount--;                        // Finished reading
        if(readCount == 0)
            sem_post(&wrt);
        sem_post(&mutex);
        sleep(1);
    }
}

void *writer()
{
    while(1)
    {
        sem_wait(&wrt);
        printf("Writer is writing...\n");
        sem_post(&wrt);
        sleep(5);
    }
}

int main()
{
    pthread_t reader1, reader2, writer1;

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    pthread_create(&reader1, 0, &reader, NULL);
    pthread_create(&reader2, 0, &reader, NULL);
    pthread_create(&writer1, 0, &writer, NULL);
    pthread_join(reader1, 0);
    pthread_join(reader2, 0);
    pthread_join(writer1, 0);

    return 0;
}