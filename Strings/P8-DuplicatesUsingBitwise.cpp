#include <iostream>
using namespace std;

int main()
{
    string str;
    cout << "Enter String : ";
    getline(cin, str);

    long int H = 0;
    int x = 0;

    cout << "The Duplicates are : " << endl;

    for (int i = 0; i < str.length(); i++)
    {
        x = 1;
        x = x << (str[i] - 97);

        if ((x & H) > 0)
        {
            cout << str[i] << endl;
        }
        else
        {
            H = H | x;
        }
    }
    return 0;
}