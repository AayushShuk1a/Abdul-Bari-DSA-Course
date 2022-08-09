#include <iostream>
using namespace std;

void PrintMCST(int T[3][6], int A[][9])
{
    cout << "\nMinimum Cost Spanning Tree Edges\n"
         << endl;
    for (int i{0}; i < 7 - 1; i++)
    {
        cout << "[" << T[0][i] << "]-----[" << T[1][i] << "]" << endl;
    }
    cout << endl;
}

void Union(int u, int v, int Set[])
{
    if (Set[u] < Set[v])
    {
        Set[u] = Set[u] + Set[v];
        v = u;
    }
    else
    {
        Set[v] = Set[v] + Set[u];
        u = v;
    }
}

int find(int u, int set[])
{
    int x = u;
    int v = 0;
    while (set[x] > 0)
    {
        x = set[x];
    }

    while (u != x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }

    return x;
}

void Kruskal(int A[3][9])
{
    int i = 0;
    int set[8] = {-1};
    int Included[9] = {0};
    int u, v;
    int t[3][6];
    int min = INT_MAX;
    int k;
    while (i < 6)
    {
        min = INT_MAX;

        // loop for finding the minimum cost
        for (int j = 0; j < 9; j++)
        {
            if (Included[j] == 0 && A[2][j] < min)
            {
                min = A[2][j];
                u = A[0][j];
                v = A[1][j];
                k = j;
            }
        }

        if (find(u, set) != find(v, set))
        {
            t[0][i] = u;
            t[1][i] = v;

            Union(find(u, set), find(v, set), set);
            i++;
        }
        Included[k] = 1;
    }

    PrintMCST(t, A);
}

int main()
{
    int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                       {2, 6, 3, 7, 4, 5, 7, 6, 7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};

    Kruskal(edges);

    return 0;
}
