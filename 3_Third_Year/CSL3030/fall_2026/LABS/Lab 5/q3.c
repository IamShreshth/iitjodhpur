#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define CAPACITY 10
#define PRODUCERS 3
#define CONSUMERS 2
#define SIMULATION_TIME 30

int queue[CAPACITY];

int front = 0;
int rear = 0;
int count = 0;

int running = 1;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;


/* Add a job to the queue */
int enqueue_job(int job)
{
    pthread_mutex_lock(&mutex);

    /* Wait if queue is full */
    while (count == CAPACITY && running)
    {
        pthread_cond_wait(&not_full, &mutex);
    }

    /* Stop if simulation is over */
    if (!running)
    {
        pthread_mutex_unlock(&mutex);
        return 0;
    }

    queue[rear] = job;
    rear = (rear + 1) % CAPACITY;
    count++;

    printf("Added Job %d | Queue = %d/%d\n",
           job, count, CAPACITY);

    /* Tell consumers that queue is not empty */
    pthread_cond_signal(&not_empty);

    pthread_mutex_unlock(&mutex);

    return 1;
}


/* Remove a job from the queue */
int dequeue_job(int *job)
{
    pthread_mutex_lock(&mutex);

    /* Wait if queue is empty */
    while (count == 0 && running)
    {
        pthread_cond_wait(&not_empty, &mutex);
    }

    /* No jobs left and simulation is over */
    if (count == 0 && !running)
    {
        pthread_mutex_unlock(&mutex);
        return 0;
    }

    *job = queue[front];

    front = (front + 1) % CAPACITY;
    count--;

    /* Tell producers that space is available */
    pthread_cond_signal(&not_full);

    pthread_mutex_unlock(&mutex);

    return 1;
}


/* Producer thread */
void* producer(void *arg)
{
    int id = *(int *)arg;
    int job = 1;

    while (1)
    {
        int job_id = id * 10000 + job;

        if (!enqueue_job(job_id))
            break;

        job++;

        /* Produce every 0.15 seconds */
        usleep(150000);
    }

    printf("Producer %d stopped.\n", id);

    return NULL;
}


/* Consumer thread */
void* consumer(void *arg)
{
    int id = *(int *)arg;
    int job;

    while (dequeue_job(&job))
    {
        printf("Printer %d printed Job %d\n",
               id, job);

        /* Printing takes 0.25 seconds */
        usleep(250000);
    }

    printf("Printer %d stopped.\n", id);

    return NULL;
}


/* Monitor thread */
void* monitor_queue(void *arg)
{
    while (1)
    {
        sleep(2);

        pthread_mutex_lock(&mutex);

        if (!running)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }

        printf("Monitor: Queue = %d/%d jobs\n",
               count, CAPACITY);

        pthread_mutex_unlock(&mutex);
    }

    printf("Monitor stopped.\n");

    return NULL;
}


int main()
{
    pthread_t producer_threads[PRODUCERS];
    pthread_t consumer_threads[CONSUMERS];
    pthread_t monitor_thread;

    int producer_ids[PRODUCERS];
    int consumer_ids[CONSUMERS];

    printf("Starting Print Queue Simulation\n");
    printf("Queue Capacity = %d\n", CAPACITY);
    printf("Producers = %d\n", PRODUCERS);
    printf("Consumers = %d\n", CONSUMERS);
    printf("Simulation Time = %d seconds\n", SIMULATION_TIME);
    printf("-----------------------------------\n");

    /* Create producer threads */
    for (int i = 0; i < PRODUCERS; i++)
    {
        producer_ids[i] = i + 1;

        pthread_create(&producer_threads[i],
                       NULL,
                       producer,
                       &producer_ids[i]);

        printf("Producer %d created\n", producer_ids[i]);
    }

    /* Create consumer threads */
    for (int i = 0; i < CONSUMERS; i++)
    {
        consumer_ids[i] = i + 1;

        pthread_create(&consumer_threads[i],
                       NULL,
                       consumer,
                       &consumer_ids[i]);

        printf("Consumer %d created\n", consumer_ids[i]);
    }

    /* Create monitor thread */
    pthread_create(&monitor_thread,
                   NULL,
                   monitor_queue,
                   NULL);

    printf("-----------------------------------\n");
    printf("Simulation started...\n");

    /* Run simulation for 30 seconds */
    sleep(SIMULATION_TIME);

    /* Stop the simulation */
    pthread_mutex_lock(&mutex);

    running = 0;

    /* Wake up waiting producers and consumers */
    pthread_cond_broadcast(&not_full);
    pthread_cond_broadcast(&not_empty);

    pthread_mutex_unlock(&mutex);

    printf("-----------------------------------\n");
    printf("Stopping simulation...\n");

    /* Wait for producers */
    for (int i = 0; i < PRODUCERS; i++)
    {
        pthread_join(producer_threads[i], NULL);
    }

    /* Wait for consumers */
    for (int i = 0; i < CONSUMERS; i++)
    {
        pthread_join(consumer_threads[i], NULL);
    }

    /* Wait for monitor */
    pthread_join(monitor_thread, NULL);

    printf("-----------------------------------\n");
    printf("Simulation finished.\n");

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);

    return 0;
}