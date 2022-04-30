#include <iostream>
using namespace std;

int main()
{
    string str, n;

    cout << "Enter String : ";
    getline(cin, str);

    n = str;

    int l = str.length();

    cout << n << endl;
    // Approach 1

    // for (int i = 0, j = l - 1; i < j; i++, j--)
    // {
    //     swap(n[i], n[j]);
    // }

    // Approach 2

    for (int i = 0, j = l - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            cout << "Not Pallindrome" << endl;
            exit(0);
        }
    }

    cout << "String is Pallindrome";

    // if (str == n)
    // {
    //     cout << "String is Pallindrome";
    // }
    // else
    // {
    //     cout << "Not Pallindrome";
    // }
}