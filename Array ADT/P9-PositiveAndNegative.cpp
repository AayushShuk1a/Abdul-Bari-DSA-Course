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

       void Sorting();
};

void Array::Sorting()
{

    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        while (A[i] < 0)
        {
            i++;
        }

        while (A[j] >= 0)
        {
            j--;
        }

        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    cout << endl
         << "After Sorting :";
    display();
}

int main()
{
    Array arr(7);

    int n;

    for (int i = 0; i < 7; i++)
    {
        cin >> n;
        arr.fillArray(n, i);
    }

    arr.display();

    arr.Sorting();
}