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

    void Missing(int l, int h);
};

void Array::Missing(int l, int h)
{
    int low = l;
    int high = h;
    int hasharray[100] = {0};
    for (int i = 0; i < length; i++)
    {

        hasharray[A[i]]++;
    }

    cout << endl
         << "The missing elements are : ";

    for (int i = l; i <= h; i++)
    {
        if (hasharray[i] == 0)
        {
            cout << i << ",";
        }
    }
}

int main()
{
    Array arr(5);
    int n;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        arr.fillArray(n, i);
    }

    cout << "Enter Low and High respectively : ";
    int l, h;
    cin >> l >> h;

    arr.display();

    arr.Missing(l, h);
}