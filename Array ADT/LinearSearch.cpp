#include <iostream>
using namespace std;

class Search
{
private:
    int *A;
    int size;
    int length;

public:
    Search()
    {
        size = 10;
        A = new int[size];
        length = 0;
    }
    Search(int sz)
    {
        size = sz;
        A = new int[size];
        length = 0;
    }
    ~Search()
    {
        delete[] A;
    }
    void storenum(int num, int i)
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

    int LinearSearch(int key);
};

int Search::LinearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Search searc(5);
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
        searc.storenum(a[i], i);
    }

    cout << "Enter the key you want to search";
    int key;
    cin >> key;
    cout << searc.LinearSearch(key) << endl;

    searc.display();
}