#include <iostream>
using namespace std;

class LowTri
{
private:
    int *A;
    int n;

public:
    LowTri(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }

    ~LowTri()
    {
        delete[] A;
    }

    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

void LowTri::set(int i, int j, int x)
{
    if (i >= j)
    {
        int index = ((n * (n - 1)) / 2) + (j - 1);
        A[index] = x;
    }
}

int LowTri::get(int i, int j)
{
    if (i >= j)
    {
        return A[((n * (n - 1)) / 2) + (j - 1)];
    }
    else
    {
        return 0;
    }
}

void LowTri::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                cout << A[((n * (n - 1)) / 2) + (j - 1)] << " ";
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
    LowTri mat(4);
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