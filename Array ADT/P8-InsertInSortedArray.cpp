#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array(int sz)
    {
        size = sz;
        A = new int[size];
        length = 0;
    }

    void fillArray(int num, int i)
    {
        A[i] = num;
        length++;
    }
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << ",";
        }
    }
    int isSorted();
    void insert(int n);
};

int Array::isSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            return 0;
        }
    }

    return 1;
}

void Array::insert(int n)
{

    int i = length - 1;

    int res = isSorted();

    if (size > length && res == 1)
    {
        while (A[i] > n)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = n;
        length++;

        cout << endl
             << "After Insert :";
        display();
    }
    else
    {
        cout << endl
             << "Array is not sorted";
    }
}

int main()
{
    Array arr(7);
    int n;

    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        arr.fillArray(n, i);
    }

    arr.display();

    arr.insert(20);
}