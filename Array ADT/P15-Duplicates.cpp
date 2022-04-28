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

    void Duplicates();
};

void Array::Duplicates()
{
    int c;

    for (int i = 0; i < length; i++)
    {

        if (A[i] == A[i + 1])
        {
            c = i + 1;

            while (A[i] == A[c])
            {
                c++;
            }
            cout << endl
                 << A[i] << " occurs " << c - i << " times.";

            i = c - 1;
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

    arr.Duplicates();
}