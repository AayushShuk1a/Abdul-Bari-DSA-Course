#include <iostream>
using namespace std;

class Delete
{
private:
    int *A;
    int size;
    int length;

public:
    Delete()
    {
        size = 10;
        A = new int[size];
        length = 0;
    }
    Delete(int sz)
    {
        size = sz;
        A = new int[size];
        length = 0;
    }
    ~Delete()
    {
        delete[] A;
    }
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i];
        }
    }
    void storenum(int num, int i)
    {
        A[i] = num;
        length++;
    }

    void Del(int index);
};

void Delete::Del(int index)
{
    if (index >= 0 && index < length)
    {
        for (int i = index; i < length; i++)
        {
            A[index] = A[index + 1];
        }
        length--;
    }
}

int main()
{
    Delete dele(5);
    int index;

    int a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
        dele.storenum(a[i], i);
    }

    cout << "Enter the index you want to delete";
    cin >> index;

    dele.Del(index);
    dele.display();
}