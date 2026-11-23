#include <iostream>
#include <vector>
#include <pthread.h>
using namespace std;

int N, M, P;
vector<vector<int>> A, B, C;

int next_row = 0;
pthread_mutex_t lock;

void take_input(int r, int c, vector<vector<int>>& arr)
{
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> arr[i][j];
}

void* work(void* arg)
{
    while(true)
    {
        pthread_mutex_lock(&lock);

        if(next_row >= N)
        {
            pthread_mutex_unlock(&lock);
            break;
        }

        int row = next_row++;
        pthread_mutex_unlock(&lock);

        for(int j = 0; j < P; j++)
        {
            for(int k = 0; k < M; k++)
            {
                C[row][j] += A[row][k] * B[k][j];
            }
        }
    }

    return NULL;
}

int main()
{
    cin >> N >> M >> P;

    A.resize(N, vector<int>(M));
    B.resize(M, vector<int>(P));
    C.resize(N, vector<int>(P, 0));

    take_input(N, M, A);
    take_input(M, P, B);

    pthread_mutex_init(&lock, NULL);

    int num_threads = min(N, 4);
    pthread_t threads[num_threads];

    for(int i = 0; i < num_threads; i++)
        pthread_create(&threads[i], NULL, work, NULL);

    for(int i = 0; i < num_threads; i++)
        pthread_join(threads[i], NULL);

    pthread_mutex_destroy(&lock);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < P; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
