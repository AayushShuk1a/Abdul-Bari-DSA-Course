#include <iostream>
using namespace std;

int main()
{
    string str, str2;
    cout << "Enter String : ";
    getline(cin, str);

    int l = str.length();

    for (int i = 0, j = l - 1; i < j; i++, j--)
    {

        swap(str[i], str[j]);
    }

    cout << "Reverse is : " << str;
}