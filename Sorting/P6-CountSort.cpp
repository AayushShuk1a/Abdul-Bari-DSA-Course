#include <iostream>
using namespace std;

int FindMax(int A[], int n)
{

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

void CountSort(int A[], int n)
{
    int max = FindMax(A, n);
    int *B = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        B[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        B[A[i]]++;
    }

    int i = 0;
    int j = 0;
    while (i < max + 1)
    {
        if (B[i] != 0)
        {
            A[j++] = i;
            B[i]--;
        }
        else
        {
            i++;
        }
    }
}

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    int A[] = {10, 9, 7, 5, 3, 15, 18, 22, 13, 2, 4};
    CountSort(A, sizeof(A) / sizeof(A[0]));
    print(A, sizeof(A) / sizeof(A[0]));
}
