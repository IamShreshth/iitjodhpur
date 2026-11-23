#include <stdio.h>
#include <pthread.h>

#define THREADS 2
#define OPERATIONS 25

int balance = 1000;

pthread_mutex_t mutex;
pthread_cond_t condition;

/* Deposit money */
void deposit(int amount, int id)
{
    pthread_mutex_lock(&mutex);

    balance = balance + amount;

    printf("Depositor %d added $%d, Balance = $%d\n",
           id, amount, balance);

    /* Wake up waiting withdrawers */
    pthread_cond_broadcast(&condition);

    pthread_mutex_unlock(&mutex);
}

/* Withdraw money */
void withdraw(int amount, int id)
{
    pthread_mutex_lock(&mutex);

    /* Wait if there is not enough money */
    while (balance < amount)
    {
        printf("Withdrawer %d waiting for $%d\n", id, amount);
        pthread_cond_wait(&condition, &mutex);
    }

    balance = balance - amount;

    printf("Withdrawer %d removed $%d, Balance = $%d\n",
           id, amount, balance);

    pthread_mutex_unlock(&mutex);
}

/* Depositor thread */
void* depositor(void* arg)
{
    int id = *(int*)arg;
    unsigned int seed = 100 + id;

    for (int i = 0; i < OPERATIONS; i++)
    {
        /* Generate amount between $1 and $100 */
        seed = seed * 1103515245 + 12345;
        int amount = (seed % 100) + 1;

        deposit(amount, id);
    }

    return NULL;
}

/* Withdrawer thread */
void* withdrawer(void* arg)
{
    int id = *(int*)arg;
    unsigned int seed = 200 + id;

    for (int i = 0; i < OPERATIONS; i++)
    {
        /* Generate amount between $1 and $20 */
        seed = seed * 1103515245 + 12345;
        int amount = (seed % 20) + 1;

        withdraw(amount, id);
    }

    return NULL;
}

int main()
{
    pthread_t deposit_threads[THREADS];
    pthread_t withdraw_threads[THREADS];

    int deposit_ids[THREADS];
    int withdraw_ids[THREADS];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition, NULL);

    printf("Initial Balance = $%d\n", balance);
    printf("Creating threads...\n");
    printf("-----------------------------\n");

    /* Create depositor and withdrawer threads */
    for (int i = 0; i < THREADS; i++)
    {
        deposit_ids[i] = i + 1;
        withdraw_ids[i] = i + 1;

        pthread_create(&deposit_threads[i],
                       NULL, depositor, &deposit_ids[i]);

        pthread_create(&withdraw_threads[i],
                       NULL, withdrawer, &withdraw_ids[i]);
    }

    /* Wait for all threads to finish */
    for (int i = 0; i < THREADS; i++)
    {
        pthread_join(deposit_threads[i], NULL);
        pthread_join(withdraw_threads[i], NULL);
    }

    printf("-----------------------------\n");
    printf("All threads completed.\n");
    printf("Final Balance = $%d\n", balance);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);

    return 0;
}