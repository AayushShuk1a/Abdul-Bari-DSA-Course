#include <iostream>
using namespace std;

void Insertion(int A[], int n) // Adaptive and Stable
{
    int x;
    for (int i = 1; i < n; i++)
    {
        x = A[i];
        int j = i - 1;
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
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
    Insertion(A, sizeof(A) / sizeof(A[0]));
    print(A, sizeof(A) / sizeof(A[0]));
}