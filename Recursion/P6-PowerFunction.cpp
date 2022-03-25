#include <iostream>
using namespace std;

int power(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return power(m * m, n / 2);
    }
    else
    {
        return m * power(m * m, (n - 1) / 2);
    }
}

int main()
{
    int n, m;
    cin >> m >> n;
    int p = power(m, n);
    cout << p;
}