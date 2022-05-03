#include <iostream>
using namespace std;

class Matrix
{
private:
    int n;
    int *A;

public:
    Matrix(int n)
    {
        this->n = n;
        A = new int[n];
    }

    void set(int i, int j, int x)
    {
        if (i == j)
        {
            A[i - 1] = x;
        }
    }

    int get(int i, int j);
    void display();
};

int Matrix::get(int i, int j)
{
    if (i == j)
    {

        return A[i - 1];
    }
    else
    {
        return 0;
    }
}

void Matrix::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << A[i - 1] << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    Matrix m(3);
    m.set(0, 0, 5);
    m.set(1, 1, 4);
    m.set(2, 2, 8);
    m.display();

    cout << m.get(2, 2);
}