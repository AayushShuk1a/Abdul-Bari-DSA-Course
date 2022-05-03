#include <iostream>
using namespace std;

void permute(string str, int l, int h)
{
    if (l == h)
    {
        cout << str << " ";
    }
    else
    {
        for (int i = l; i < h; i++)
        {
            swap(str[l], str[i]);
            permute(str, l + 1, h);
            swap(str[l], str[i]);
        }
    }
}

int main()
{
    string str;
    cout << "Enter String :";
    getline(cin, str);

    permute(str, 0, str.length());
}