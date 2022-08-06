#include <iostream>
using namespace std;
#include <queue>

void BFS(int A[][6], int start, int n)
{
    int i = start;
    queue<int> q;
    int visited[6] = {0};
    cout << i << " ";
    visited[i] = 1;
    q.emplace(i);
    while (!q.empty())
    {
        i = q.front();
        q.pop();
        for (int j = 1; j < n; j++)
        {
            if (visited[j] == 0 && A[i][j] == 1)
            {

                cout << j << " ";
                visited[i] = 1;
                q.emplace(j);
            }
        }
    }
}

int main()
{
    int A[6][6] = {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 1, 1}, {0, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0}};

    BFS(A, 2, 6);
}