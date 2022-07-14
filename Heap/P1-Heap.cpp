#include <iostream>
#include <vector>
using namespace std;

class Heap
{

private:
    int arr[100];

    int size;

public:
    Heap()
    {

        size = 0;
    }
    void insert(int val);
    void print();
    void Delete();
};

void Heap::Delete()
{
    if (size == 0)
        return;

    arr[1] = arr[size];
    size--;
    int i = 1;
    while (i < size)
    {
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;

        if (leftIndex < size && arr[i] < arr[leftIndex])
        {
            swap(arr[i], arr[leftIndex]);
            i = leftIndex;
        }
        else if (rightIndex < size && arr[i] < arr[rightIndex])
        {
            swap(arr[i], arr[rightIndex]);
            i = rightIndex;
        }
        else
        {
            return;
        }
    }
}

void Heap::print()
{
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
}

void Heap::insert(int key)
{
    size++;
    arr[size] = key;
    int i = size;

    while (i > 1)
    {
        int parent = i / 2;
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);
            i = parent;
        }
        else
        {
            return;
        }
    }
}

int main()
{
    Heap h;
    h.insert(20);
    h.insert(25);
    h.insert(30);
    h.insert(32);
    h.insert(15);
    h.insert(19);
    h.insert(28);

    h.print();

    cout << endl
         << "After delete" << endl;

    h.Delete();
    h.Delete();
    h.print();
}