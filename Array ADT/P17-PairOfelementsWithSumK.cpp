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

    void Pair(int value);
};

void Array::Pair(int value)
{

    cout << endl
         << "The Pairs are : " << endl;
    for (int i = 0; i < length; i++)
    {

        for (int j = i + 1; j < length; j++)
        {

            if (A[i] + A[j] == value)
            {
                cout << A[i] << " + " << A[j] << " = " << value << endl;
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
         << "Enter the value : ";
    int value;
    cin >> value;
    arr.Pair(value);
}