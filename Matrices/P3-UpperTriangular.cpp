#include <iostream>
using namespace std;

class Matrix
{
private:
    int *A;
    int n;

public:
    Matrix(int size)
    {
        n = size;
        A = new int[(n * (n + 1)) / 2];
    }

    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

void Matrix::set(int i, int j, int x)
{
    if (i <= j)
    {
        int index = ((j * (j - 1)) / 2) + (i - 1); // column major for upper triangular
        A[index] = x;
    }
}

int Matrix::get(int i, int j)
{
    if (i <= j)
    {
        return A[((j * (j - 1)) / 2) + (i - 1)];
    }
    else
    {
        return 0;
    }
}

void Matrix::display()
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                cout << A[i] << " ";
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
    Matrix mat(4);
    int x;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> x;
            mat.set(i, j, x);
        }
    }

    mat.display();
}