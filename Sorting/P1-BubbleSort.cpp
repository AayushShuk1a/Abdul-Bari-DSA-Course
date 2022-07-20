#include <iostream>
using namespace std;

void Bubble(int A[], int n)
{
    int flag = 0; // To make sorting Adaptive

    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                flag = 1;
            }
        }

        if (flag == 0) // It means the list is already sorted
        {
            break;
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
    Bubble(A, sizeof(A) / sizeof(A[0]));
    print(A, sizeof(A) / sizeof(A[0]));
}