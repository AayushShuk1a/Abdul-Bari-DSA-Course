#include <iostream>
using namespace std;

class element
{
public:
    int rowno;
    int colno;
    int elem;
};

class Matrix
{
private:
    int row;
    int col;
    int num; // number of non-zero elements
    element *ele;

public:
    Matrix(int r, int c, int n)
    {
        row = r;
        col = c;
        num = n;
        ele = new element[num];
    }

    friend istream &operator>>(istream &is, Matrix &mat); // Operator Overloading creating cin function

    friend ostream &operator<<(ostream &os, Matrix &mat); // Operator overloading creating cout function

    Matrix operator+(Matrix &mat); // Operator Overloading
};

istream &operator>>(istream &is, Matrix &mat)
{
    for (int i = 0; i < mat.num; i++)
    {
        cin >> mat.ele[i].rowno >> mat.ele[i].colno >> mat.ele[i].elem;
    }
    return is;
}

ostream &operator<<(ostream &os, Matrix &mat)
{
    cout << endl;
    int k = 0;
    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            if (mat.ele[k].rowno == i && mat.ele[k].colno == j)
            {
                cout << mat.ele[k++].elem << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }

        cout << endl;
    }
    cout << endl
         << endl;
    return os;
}

Matrix Matrix::operator+(Matrix &mat)
{
    int i = 0, j = 0, k = 0;
    if (row != mat.row || col != mat.col)
    {
        return Matrix(0, 0, 0);
    }
    Matrix *mat3 = new Matrix(4, 4, num + mat.num);
    while (i < num && j < mat.num)
    {
        if (ele[i].rowno < mat.ele[j].rowno)
        {

            mat3->ele[k++] = ele[i++];
        }
        else if (ele[i].rowno > mat.ele[j].rowno)
        {

            mat3->ele[k++] = mat.ele[j++];
        }
        else
        {
            if (ele[i].colno < mat.ele[j].colno)
            {
                mat3->ele[k++] = ele[i++];
            }
            else if (ele[i].colno > mat.ele[j].colno)
            {

                mat3->ele[k++] = mat.ele[j++];
            }
            else
            {
                mat3->ele[k] = ele[i];
                mat3->ele[k++].elem = ele[i++].elem + mat.ele[j++].elem;
            }
        }
    }

    for (; i < num; i++)
        mat3->ele[k++] = ele[i];

    for (; j < mat.num; j++)
        mat3->ele[k++] = mat.ele[j];

    mat3->num = k;
    return *mat3;
}

int main()
{
    Matrix mat1(4, 4, 6);
    Matrix mat2(4, 4, 6);
    cout << "Matrix 1 : ";
    cin >> mat1;
    cout << "Matrix 2 : ";
    cin >> mat2;
    Matrix mat = mat1 + mat2;

    cout << "Matrix 1";
    cout << mat1;
    cout << "Matrix 2";
    cout << mat2;
    cout << "Sum Matrix";

    cout << mat;
}