#include <iostream>
using namespace std;

void fun1(int n)
{

    if (n > 0)
    {
        fun1(n - 1);
        cout << n << " ";
    }
}

void fun2(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        fun2(n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    // cin >> n;
    cout << "First Calling Then Printing : ";
    fun1(n);
    cout << "\n"
         << "First Printing Then Calling : ";
    fun2(n);
}