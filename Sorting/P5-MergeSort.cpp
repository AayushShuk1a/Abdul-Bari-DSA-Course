#include <iostream>
using namespace std;

void Merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1;
    int k = l;
    int B[100];

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else if (A[j] < A[i])
        {
            B[k++] = A[j++];
        }
    }

    for (; i <= mid; i++)
        B[k++] = A[i];

    for (; j <= h; j++)
        B[k++] = A[j];

    for (int i = l; i <= h; i++)
    {
        A[i] = B[i];
    }
}

void MergeSort(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
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
    MergeSort(A, 0, sizeof(A) / sizeof(A[0]) - 1);
    print(A, sizeof(A) / sizeof(A[0]));
}