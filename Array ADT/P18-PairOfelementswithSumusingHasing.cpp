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

    void Pair(int value, int l, int h);
};

void Array::Pair(int value, int l, int h)
{
    cout << endl
         << "The Pairs are : " << endl;
    int B[h + 1] = {0};
    for (int i = 0; i < length; i++)
    {
        if (B[value - A[i]] != 0)
        {

            cout << A[i] << " + " << value - A[i] << " = " << value << endl;
        }
        B[A[i]]++;
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
         << "Enter Low and High : ";
    int l, h;
    cin >> l >> h;
    arr.Pair(value, l, h);
}
