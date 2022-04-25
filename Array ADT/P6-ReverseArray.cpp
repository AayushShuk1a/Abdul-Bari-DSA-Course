#include <iostream>
using namespace std;

class Reverse
{
private:
    int *A;
    int size;
    int length;

public:
    Reverse(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }

    void fillArray(int num, int i)
    {
        A[i] = num;
        length++;
    }

    void ReverseArray();
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << ",";
        }
    }
};

void Reverse::ReverseArray() // another method: use a another array to store the the value and then copy to main array
{
    int temp;
    int i, j;

    for (i = 0, j = length - 1; i < length; i++, j--)
    {
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
}

int main()
{
    Reverse rev(5);
    int n;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        rev.fillArray(n, i);
    }

    rev.display();

    rev.ReverseArray();
    cout << endl
         << "After Reverse :" << endl;
    rev.display();
}