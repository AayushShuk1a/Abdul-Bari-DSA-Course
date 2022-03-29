#include <iostream>
using namespace std;

int a[10];
int fibonacci(int n)
{
    if (n <= 1)
    {
        a[n] = n;
        return n;
    }
    else
    {
        if (a[n - 2] == -1)
        {
            a[n - 2] = fibonacci(n - 2);
        }
        if (a[n - 1] == -1)
        {
            a[n - 1] = fibonacci(n - 1);
        }

        return a[n - 2] + a[n - 1];
    }
}

int main()
{

    for (int i = 0; i < 10; i++)
    {
        a[i] = -1;
    }
    int n;
    cin >> n;
    cout << fibonacci(n);
}
