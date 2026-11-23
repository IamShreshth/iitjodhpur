#include <iostream>
#include <vector>
#include <pthread.h>
using namespace std;

int N, M, P;
vector<vector<int>> A, B, C;

void take_input(int row, int col, vector<vector<int>>& arr);
void* calc_row(void* arg);

int main()
{
    cin >> N >> M >> P;

    A.resize(N, vector<int>(M));
    B.resize(M, vector<int>(P));
    C.resize(N, vector<int>(P, 0));

    take_input(N, M, A);
    take_input(M, P, B);

    pthread_t threads[N];
    int rows[N];

    for(int i = 0; i < N; i++)
    {
        rows[i] = i;
        pthread_create(&threads[i], NULL, calc_row, &rows[i]);
    }

    for(int i = 0; i < N; i++)
        pthread_join(threads[i], NULL);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < P; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}

void take_input(int row, int col, vector<vector<int>>& arr)
{
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> arr[i][j];
}

void* calc_row(void* arg)
{
    int i = *(int*)arg;

    for(int j = 0; j < P; j++)
        for(int k = 0; k < M; k++)
            C[i][j] += A[i][k] * B[k][j];

    return NULL;
}
