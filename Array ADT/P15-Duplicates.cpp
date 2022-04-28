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
    void unsortedDuplicates();
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

void Array::unsortedDuplicates()
{
    int c;
    for (int i = 0; i < length; i++)
    {
        c = 1;
        if (A[i] != -1)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (A[i] == A[j])
                {
                    c++;
                    A[j] = -1;
                }
            }
            if (c > 1)
            {
                cout << endl
                     << A[i] << " occurs " << c << " Times.";
            }
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

    cout << endl
         << "1.Sorted" << endl;
    cout << "2.Unsorted" << endl;
    int ch;
    cin >> ch;

    switch (ch)
    {
    case 1:
        arr.Duplicates();
        break;

    case 2:
        arr.unsortedDuplicates();
        break;

    default:
        cout << "Enter Valid Choice";
        break;
    }
}