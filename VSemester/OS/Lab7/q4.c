#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex, barb, atmost5;
int queue[5];
int front = 0, rear = 0;
int waiting = 0, done = 0;
int i = 0;

void *customer()
{
    while(1)
    {
        sem_wait(&atmost5);
        sem_wait(&mutex);
        queue[(rear++)%5] = i;
        printf("Customer %d Waiting!\n", i);
        i++;
        waiting++;
        sleep(2);
        sem_post(&mutex);
    }
}

void *barber()
{
    int item;

    while(1)
    {
        sem_wait(&barb);
        sem_wait(&mutex);
        item = queue[(front++)%5];
        sem_post(&mutex);
        printf("Barber cutting %d!\n", item);
        sleep(3);
        printf("Barber done cutting %d!\n", item);
        sem_wait(&mutex);
        done++;
        sem_post(&mutex);
        if(waiting - done < 5)
            sem_post(&atmost5);
        sleep(2);
    }
}

int main()
{
    sem_init(&barber, 0, 1);
    sem_init(&mutex, 0, 1);
    sem_init(&atmost5, 0, 5);

    pthread_t c, b;
    pthread_create(&c, 0, &customer, NULL);
    pthread_create(&b, 0, &barber, NULL);
    pthread_join(c, 0);
    pthread_join(b, 0);

    return 0;
}