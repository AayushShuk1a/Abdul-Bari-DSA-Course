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

    void LeftShift();
    void RightShift();
};

void Array::LeftShift()
{
    int n = A[0];
    for (int i = 0; i < length; i++)
    {
        A[i] = A[i + 1]; // leftShift
    }
    A[length - 1] = n; // left rotate
}

void Array::RightShift()
{
    int n = A[length - 1];
    for (int i = length - 1; i > 0; i--)
    {
        A[i] = A[i - 1]; // RightShift
    }
    A[0] = n; // Rightrotate
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

    arr.LeftShift();
    cout << endl
         << "After Left Shift :" << endl;
    arr.display();

    arr.RightShift();
    cout << endl
         << "After Right Shift :" << endl;
    arr.display();
}