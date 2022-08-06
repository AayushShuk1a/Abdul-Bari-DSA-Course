#include <iostream>
using namespace std;
#include <queue>

void BFS(int A[][7], int start, int n)
{
    int i = start;
    queue<int> q;
    int visited[7] = {0};
    cout << i << " ";
    visited[i] = 1;
    q.emplace(i);
    while (!q.empty())
    {
        i = q.front();
        q.pop();
        for (int j = 1; j < n; j++)
        {
            if (A[i][j] == 1 && visited[j] == 0)
            {

                cout << j << " ";
                visited[j] = 1;
                q.emplace(j);
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

    BFS(G, 1, 7);
}