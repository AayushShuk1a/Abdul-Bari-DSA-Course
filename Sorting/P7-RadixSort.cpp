#include <iostream>
using namespace std;

int getMax(int A[], int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    return max;
}

void CountSort(int A[], int n, int pass)
{
    int count[10] = {0};
    int output[n];

    for (int i = 0; i < n; i++)
    {
        count[(A[i] / pass) % 10]++;
    }

    for (int i = 1; i < n; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(A[i] / pass) % 10] - 1] = A[i];
        count[(A[i] / pass) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        A[i] = output[i];
    }
}

void RadixSort(int A[], int n)
{
    int max = getMax(A, n);

    for (int i = 1; max / i > 0; i *= 10)
    {
        CountSort(A, n, i);
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
    int A[] = {1033, 93, 97, 54, 33, 155, 138, 221, 1324, 22, 4};

    RadixSort(A, sizeof(A) / sizeof(A[0]));
    print(A, sizeof(A) / sizeof(A[0]));
}