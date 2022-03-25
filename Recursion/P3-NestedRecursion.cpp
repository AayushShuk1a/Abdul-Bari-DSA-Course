#include <iostream>
using namespace std;

int NestedRecursion(int n)
{
    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        return NestedRecursion(NestedRecursion(n + 11));
    }
}

int main()
{
    int n;
    cin >> n;
    int r = NestedRecursion(n);
    cout << r;
}
