#include <iostream>
using namespace std;

void heapify(int A[], int n, int i)
{
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    if (leftChild <= n && A[leftChild] > (rightChild < n ? A[rightChild] : -1) && A[leftChild] > A[i])
    {
        largest = leftChild;
    }
    else if (rightChild <= n && A[rightChild] > A[i])
    {
        largest = rightChild;
    }

    if (largest != i)
    {
        swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

void print(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

void heapSort(int A[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(A[size], A[1]);
        size--;
        heapify(A, size, 1);
    }
}

int main()
{
    int arr[] = {-1, 70, 68, 78, 73, 56, 90, 49};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = (size - 1) / 2; i > 0; i--)
    {
        heapify(arr, size - 1, i);
    }

    print(arr, size);

    cout << endl
         << "After Heapsort" << endl;

    heapSort(arr, size - 1);
    print(arr, size);
}