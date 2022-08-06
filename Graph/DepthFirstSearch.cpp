#include <iostream>
using namespace std;

void DFS(int A[][7], int start, int n)
{
    static int visited[7] = {0};
    if (visited[start] == 0)
    {
        cout << start << " ";
        visited[start] = 1;

        for (int j = 1; j < n; j++)
        {
            if (visited[j] == 0 && A[start][j] == 1)
            {
                DFS(A, j, n);
            }
        }
    }
}

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    DFS(G, 4, 7);
}