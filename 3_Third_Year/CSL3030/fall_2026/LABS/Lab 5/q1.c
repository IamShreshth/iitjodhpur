#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define THREADS 10
#define INCREMENTS 500000

long long counter = 0;

pthread_mutex_t mutex;

int use_mutex = 0;
int print_each = 0;

void* increment(void* arg)
{
    int id = *(int*)arg;

    for (int i = 0; i < INCREMENTS; i++)
    {
        if (use_mutex)
            pthread_mutex_lock(&mutex);

        counter++;

        if (print_each)
            printf("Thread %d -> Counter = %lld\n", id, counter);

        if (use_mutex)
            pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main(int argc, char* argv[])
{
    pthread_t threads[THREADS];
    int id[THREADS];

    if (argc != 2)
    {
        printf("Usage: %s without | with | print\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "without") == 0)
    {
        use_mutex = 0;
        print_each = 0;
    }
    else if (strcmp(argv[1], "with") == 0)
    {
        use_mutex = 1;
        print_each = 0;
    }
    else if (strcmp(argv[1], "print") == 0)
    {
        use_mutex = 1;
        print_each = 1;
    }
    else
    {
        printf("Invalid option!\n");
        return 1;
    }

    pthread_mutex_init(&mutex, NULL);

    printf("Creating %d threads...\n", THREADS);
    printf("Each thread increments counter %d times.\n", INCREMENTS);

    if (use_mutex)
        printf("Mutex: ON\n");
    else
        printf("Mutex: OFF\n");

    printf("-----------------------------\n");

    // Create threads
    for (int i = 0; i < THREADS; i++)
    {
        id[i] = i + 1;

        pthread_create(&threads[i], NULL, increment, &id[i]);

        printf("Thread %d created\n", id[i]);
    }

    printf("-----------------------------\n");

    // Wait for all threads
    for (int i = 0; i < THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");
    printf("-----------------------------\n");

    printf("Final Counter = %lld\n", counter);
    printf("Expected Counter = %lld\n",
           (long long)THREADS * INCREMENTS);

    pthread_mutex_destroy(&mutex);

    return 0;
}