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
    void sortedpair(int value);
};

void Array::Pair(int value) // Sorted or Unsorted Array time complexity O(n^2)
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

void Array::sortedpair(int value)
{
    cout << endl
         << "The Pairs are : " << endl;

    int i = 0, j = length - 1;
    while (i < j) // Sorted Array with time complexity O(n)
    {
        if (A[i] + A[j] == value)
        {
            cout << A[i] << " + " << A[j] << " = " << value << endl;
            i++;
            j--;
        }
        else if (A[i] + A[j] > value)
        {
            j--;
        }
        else if (A[i] + A[j] < value)
        {
            i++;
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

    cout << endl
         << "1.Unsorted" << endl;
    cout << "2.Sorted" << endl;
    int ch;
    cin >> ch;

    switch (ch)
    {
    case 1:
        arr.Pair(value);
        break;

    case 2:
        arr.sortedpair(value);
        break;

    default:
        cout << "Enter Valid Choice";
        break;
    }
}