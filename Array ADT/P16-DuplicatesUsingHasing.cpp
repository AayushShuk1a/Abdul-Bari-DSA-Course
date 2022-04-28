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
        A = new int(size);
        length = 0;
    }

    void fillArray(int value, int index)
    {
        A[index] = value;
        length++;
    }

    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << ",";
        }
    }

    void Duplicates(int l, int h);
};

void Array::Duplicates(int l, int h)
{
    int B[h + 1] = {0};
    for (int i = 0; i < length; i++)
    {
        B[A[i]]++;
    }

    cout << endl;

    for (int i = l; i <= h; i++)
    {
        if (B[i] > 1)
        {
            cout << i << " occurs " << B[i] << " Times." << endl;
        }
    }
}

int main()
{
    Array arr(10);
    int n;
    for (int i = 0; i < 10; i++)
    {
        cin >> n;
        arr.fillArray(n, i);
    }

    arr.display();

    int l, h;
    cout << endl
         << "Enter low and high respectively : ";
    cin >> l >> h;
    arr.Duplicates(l, h);
}