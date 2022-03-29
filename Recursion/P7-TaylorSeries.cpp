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

double e2(int x, int n)
{
    static double sum4 = 1;
    if (n == 0)
    {
        return sum4;
    }
    else
    {
        sum4 = 1 + x * sum4 / n;
        return e2(x, n - 1);
    }
}

int main()
{
    int x, n;
    cin >> x >> n;
    double sum = e(x, n);

    double sum2 = e2(x, n);
    cout
        << sum << endl
        << sum2;
}