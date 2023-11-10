#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex, wrt;
int count = 0;

void *Reader()
{
    sem_wait(&wrt);
    sem_wait(&mutex);
    printf("Reader in Critical Section!\n");
    count++;
    sleep(2);
    sem_post(&mutex);
    sem_post(&wrt);
}

void *Writer()
{
    sem_wait(&mutex);
    sem_wait(&wrt);
    printf("Writer in Critical Section!\n");
    count--;
    sleep(2);
    sem_post(&wrt);
    sem_post(&mutex);
}

int main()
{
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    pthread_t r, w;
    pthread_create(&r, 0, &Reader, NULL);
    pthread_create(&w, 0, &Writer, NULL);
    pthread_join(r, 0);
    pthread_join(w, 0);

    return 0;
}