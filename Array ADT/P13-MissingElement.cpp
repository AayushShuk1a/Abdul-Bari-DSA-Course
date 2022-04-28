#include <iostream>
using namespace std;

class Missing
{
private:
    int *A;
    int size;
    int length;

public:
    Missing(int sz)
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

    void missingElement();
};

void Missing::missingElement()
{
    int diff = A[0] - 0;

    cout << endl
         << "The missing elements are : ";

    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != diff)
        {
            while (diff < A[i] - i)
            {
                cout << diff + i << ",";
                diff++;
            }
        }
    }
}

int main()
{
    Missing arr(5);
    int n;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        arr.fillArray(n, i);
    }

    arr.display();

    arr.missingElement();
}