#include <iostream>
using namespace std;

class Insert
{
private:
    int *A;
    int size;
    int length;

public:
    Insert()
    {
        size = 10;
        length = 0;
        A = new int(size);
    }
    Insert(int sz)
    {
        size = sz;
        A = new int(size);
        length = 0;
    }

    void InsertValue(int index, int value);
    void Display();
};

void Insert::InsertValue(int index, int value)
{

    if (index >= 0 && index <= length)
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = value;
        length++;
    }
}

void Insert::Display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << ",";
    }
}

int main()
{
    Insert ins(10);

    ins.InsertValue(0, 5);
    ins.InsertValue(1, 4);
    ins.InsertValue(2, 3);
    ins.InsertValue(3, 2);
    ins.InsertValue(4, 1);

    ins.Display();
}