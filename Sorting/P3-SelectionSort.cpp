#include <iostream>
using namespace std;

void Selection(int A[], int n) // not adaptive and not stable
{
    int k;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        swap(A[i], A[k]);
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
    Selection(A, sizeof(A) / sizeof(A[0]));
    print(A, sizeof(A) / sizeof(A[0]));
}
