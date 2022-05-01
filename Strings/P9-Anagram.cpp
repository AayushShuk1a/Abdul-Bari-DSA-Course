#include <iostream>
using namespace std;

int main()
{
    string str1, str2;
    cout << "Enter String 1 : ";
    getline(cin, str1);
    cout << "Enter String 2 : ";
    getline(cin, str2);

    int H[26] = {0};
    int i;
    for (i = 0; i < 26; i++)
    {
        H[str1[i] - 97]++;
    }

    for (i = 0; i < 26; i++)
    {
        H[str2[i] - 97]--;
        if (H[i] < 0)
        {
            cout << "Strings are not anagram.";
            exit(0);
        }
    }

    cout << "Strings are anagram.";
}