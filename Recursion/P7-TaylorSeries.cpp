#include <iostream>
using namespace std;
double e(int x, int n)
{
    static double p = 1, f = 1;

    double sum;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        sum = e(x, n - 1);
        p = p * x;
        f = f * n;
        return sum + (p / f);
    }
}

int main()
{
    int x, n;
    cin >> x >> n;
    double sum = e(x, n);
    cout << sum;
}