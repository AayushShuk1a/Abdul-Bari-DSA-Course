#include <iostream>
using namespace std;

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int count = 0;
    for (int i = l + 1; i <= h; i++)
    {
        if (A[i] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = l + count;
    swap(A[l], A[pivotIndex]);

    int i = l;
    int j = h;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(A[i++], A[j--]);
        }
    }

    return pivotIndex;
}

void QuickSort(int A[], int l, int h)
{

    if (l >= h)
    {
        return;
    }
    int pivot = partition(A, l, h);
    QuickSort(A, l, pivot - 1);
    QuickSort(A, pivot + 1, h);
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
    QuickSort(A, 0, sizeof(A) / sizeof(A[0]) - 1);
    print(A, sizeof(A) / sizeof(A[0]));
}
