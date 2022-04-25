#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array()
    {
        size = 0;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[sz];
    }
    void fillArray(int num, int i);
    int getArray(int index);
    void setArray(int index, int value);
    int maxNum();
    float avgArray();
    void display();
};

void Array::fillArray(int num, int i)
{
    A[i] = num;
    length++;
}

void Array::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << ",";
    }
}

int Array::getArray(int index)
{
    int n = A[index];
    return n;
}

void Array::setArray(int index, int value)
{
    A[index] = value;
}

int Array::maxNum()
{
    int max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

float Array::avgArray()
{
    float avg;
    for (int i = 0; i < length; i++)
    {
        avg = avg + A[i];
    }

    return avg / length;
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

    arr.display();
    cout << endl
         << arr.getArray(3) << endl;

    arr.setArray(3, 99);
    arr.display();

    cout << endl
         << arr.maxNum();

    cout << endl
         << arr.avgArray();
}