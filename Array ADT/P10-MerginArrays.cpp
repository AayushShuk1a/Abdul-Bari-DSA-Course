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

    void merge();
};

void Array::merge()
{
    cout << endl
         << "Enter 2nd Array :";
    int B[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> B[i];
    }

    int C[10];
    int k = 0;
    int i = 0;
    int j = 0;

    while (i < 5 && j < 5)
    {

        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }

    while (i < 5) // Copying remaing element in A
    {
        C[k++] = A[i++];
    }
    while (j < 5) // copyng remaing element in B
    {
        C[k++] = B[j++];
    }

    for (int i = 0; i < 10; i++)
    {
        cout << C[i] << ",";
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

    arr.display();
    arr.merge();
}