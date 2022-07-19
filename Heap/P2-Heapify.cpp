#include <iostream>
using namespace std;

class Heap
{
    int size;

public:
    Heap(int size) { this->size = size; };
    void heapify(int A[], int n);
    void print(int A[]);
    void Delete(int A[], int n);
};

void Heap::Delete(int A[], int n)
{

    A[1] = A[n - 1];
    size--;
    int i = 1;
    int leftChild = 2 * i;

    int largest = leftChild;

    while (largest < n - 1)
    {
        int righChild = 2 * i + 1;
        // compare the left and right child of current i
        if (A[largest] < A[righChild])
        {
            largest = righChild;
        }

        // compare parent and largest child and swap
        if (A[i] < A[largest])
        {
            swap(A[i], A[largest]);
            i = largest;
            largest = 2 * i;
        }
        else
        {
            break;
        }
    }
}

void Heap::heapify(int A[], int n)
{

    for (int i = n / 2; i > 0; i--)
    {
        int leftChild = 2 * i;
        int largest = leftChild;
        int rightChild = 2 * i + 1;

        while (largest < n)
        {
            // compare left and right child of current i and point largest

            if (A[leftChild] < A[rightChild])
            {
                largest = rightChild;
            }

            // compare and swap parent and the largest children
            if (A[i] < A[largest])
            {
                swap(A[i], A[largest]);
                i = largest;     // new Parent
                largest = 2 * i; // new left child
            }
            else
            {
                break;
            }
        }
    }
}

void Heap::print(int A[])
{
    for (int i = 1; i < size; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{

    int arr[] = {-1, 70, 68, 60, 55, 56, 90, 49};
    Heap h(sizeof(arr) / sizeof(arr[0]));
    h.heapify(arr, sizeof(arr) / sizeof(arr[0]));
    h.print(arr);
    h.Delete(arr, sizeof(arr) / sizeof(arr[0]));
    cout << endl
         << "After Delete " << endl;

    h.print(arr);
}