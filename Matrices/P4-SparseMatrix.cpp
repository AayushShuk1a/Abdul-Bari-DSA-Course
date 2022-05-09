#include <iostream>
using namespace std;

class element
{
public:
    int rowno;
    int columnno;
    int elem;
};

class Array
{
private:
    int row;
    int column;
    int n; // number of non-zero elements
    element *ele;

public:
    Array(int r, int c, int n)
    {
        row = r;
        column = c;
        this->n = n;
        ele = new element[this->n];
    }

    void read()
    {

        for (int i = 0; i < n; i++)
        {
            cin >> ele[i].rowno >> ele[i].columnno >> ele[i].elem; // reading non zero elements and storing in ele
        }
    }

    void display()
    {
        int k = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (ele[k].rowno == i && ele[k].columnno == j)
                {
                    cout << ele[k++].elem << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }

            cout << endl;
        }
    }
};

int main()
{
    Array arr(5, 5, 6);

    arr.read();

    arr.display();
}