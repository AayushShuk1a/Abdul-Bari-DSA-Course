#include <iostream>

using namespace std;

void PrimAlgo(int A[8][8], int n)
{
    int u, v;

    int near[8];
    int track[2][8 - 2] = {0};
    int min = INT_MAX;

    // Loop to find the smallest value in upper half triangle
    for (int i = 1; i < 8; i++)
    {
        near[i] = INT_MAX;
        for (int j = i; j < 8; j++)
        {
            if (A[i][j] < min)
            {
                min = A[i][j];
                u = i;
                v = j;
            }
        }
    }

    // Assigning the first value

    near[u] = near[v] = 0;
    track[0][0] = u;
    track[1][0] = v;

    // Assigning the value which are closer to u or v
    for (int i = 1; i < 8; i++)
    {
        if (near[i] != 0)
        {
            if (A[i][u] < A[i][v])
            {
                near[i] = u;
            }
            else
            {
                near[i] = v;
            }
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        int k;
        min = INT_MAX;

        for (int j = 1; j < 8; j++)
        {
            if (near[j] != 0 && A[j][near[j]] < min)
            {
                k = j;
                min = A[j][near[j]];
            }
        }

        track[0][i] = k;
        track[1][i] = near[k];
        near[k] = 0;

        for (int i = 1; i < 8; i++)
        {
            if (near[i] != 0 && A[i][k] < A[i][near[i]])
            {
                near[i] = k;
            }
        }
    }

    for (int i = 0; i < 8 - 2; i++)
    {
        cout << "(" << track[0][i] << "," << track[1][i] << ")" << endl;
    }
}

int main()
{

    int I = INT_MAX;
    int cost[8][8]{
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 5, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I},
    };

    int n = sizeof(cost[0]) / sizeof(cost[0][0]) - 1;

    PrimAlgo(cost, n);
}