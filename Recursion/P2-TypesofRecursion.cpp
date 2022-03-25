#include <iostream>
using namespace std;

void TailRecursion(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        TailRecursion(n - 1); // Recursion At the End Nothing to do when returning
    }
}

void HeadRecursion(int n)
{
    if (n > 0)
    {
        HeadRecursion(n - 1); // Recursion at the Starting Nothing to do when calling
        cout << n << ' ';
    }
}

void TreeRecursion(int n)
{
    if (n > 0)
    {
        TreeRecursion(n - 1);
        cout << n << ' '; // Calling itself more thn one time.
        TreeRecursion(n - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    cout << "**Tail Recursion**" << endl;
    TailRecursion(n);

    cout << endl
         << "**Head Recursion**" << endl;
    HeadRecursion(n);

    cout << endl
         << "**Tree Recursion**" << endl;
    TreeRecursion(n);
}