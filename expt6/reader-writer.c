#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX 100

sem_t mutex, wrt;
int readcount = 0;
int data = 1;

void *reader(void *arg)
{
    sem_wait(&mutex);
    readcount++;

    if (readcount == 1)
    {
        sem_wait(&wrt);
    }

    sem_post(&mutex);

    printf("Reader reads: %d\n", data);
    sleep(1);

    sem_wait(&mutex);
    readcount--;

    if (readcount == 0)
    {
        sem_post(&wrt);
    }

    sem_post(&mutex);
    return NULL;
}

void *writer(void *arg)
{
    sem_wait(&wrt);

    data++;
    printf("Writer writes: %d\n", data);

    sem_post(&wrt);
    return NULL;
}

int main()
{
    int nr, nw;
    pthread_t readers[MAX], writers[MAX];

    printf("Enter number of readers: ");
    scanf("%d", &nr);

    printf("Enter number of writers: ");
    scanf("%d", &nw);

    if (nr < 0 || nr > MAX || nw < 0 || nw > MAX)
    {
        printf("Enter numbers between 0 and %d.\n", MAX);
        return 1;
    }

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (int i = 0; i < nr; i++)
    {
        pthread_create(&readers[i], NULL, reader, NULL);
    }

    for (int i = 0; i < nw; i++)
    {
        pthread_create(&writers[i], NULL, writer, NULL);
    }

    for (int i = 0; i < nr; i++)
    {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < nw; i++)
    {
        pthread_join(writers[i], NULL);
    }   

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}