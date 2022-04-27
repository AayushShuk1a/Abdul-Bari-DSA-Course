#include <iostream>
using namespace std;

class operations
{
private:
    int *A;
    int size;
    int length;

public:
    operations(int sz)
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

    void intersection(int b[]);
};

void operations::intersection(int b[])
{
    int i = 0, j = 0, k = 0;

    int c[10];
    while (i < 7 && j < 7)
    {
        if (A[i] < b[j])
        {
            i++;
        }
        else if (b[j] < A[i])
        {
            j++;
        }
        else if (A[i] == b[j])
        {
            c[k++] = A[i++];
            j++;
        }
    }

    cout << endl
         << "The Intersection between two arrays is : ";
    for (int i = 0; i < k; i++)
    {
        cout << c[i] << ",";
    }
}

int main()
{
    operations arr(7);
    int n;
    for (int i = 0; i < 7; i++)
    {
        cin >> n;
        arr.fillArray(n, i);
    }

    arr.display();

    cout << endl
         << "Enter another array : ";
    int c[7];

    for (int i = 0; i < 7; i++)
    {
        cin >> c[i];
    }

    arr.intersection(c);
}