#include <iostream>
using namespace std;

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

void ShellShort(int A[], int n)
{
    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            int temp = A[j];
            int i = j - gap;
            while (i >= 0 && A[i] > temp)
            {
                A[i + gap] = A[i];
                i = i - gap;
            }

            A[i + gap] = temp;
        }
    }
}

int main()
{
    int A[] = {1033, 93, 97, 54, 33, 155, 138, 221, 1324, 22, 4};

    ShellShort(A, sizeof(A) / sizeof(A[0]));

    print(A, sizeof(A) / sizeof(A[0]));
}