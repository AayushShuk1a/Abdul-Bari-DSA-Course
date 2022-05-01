#include <iostream>
using namespace std;

void NormalMethod(string str, int l)
{
    int count = 1;

    for (int i = 0; i < l; i++)
    {
        if (str[i] != -1)
        {

            for (int j = i + 1; j < l; j++)
            {
                if (str[i] == str[j])
                {
                    count++;
                    str[j] = -1;
                }
            }

            if (count > 1)
            {

                cout << str[i] << " occurs " << count << " times." << endl;
                count = 1;
            }
        }
    }
}

void HashingMethod(string str, int l)
{

    int count[26] = {0};
    for (int i = 0; i < l; i++)
    {

        count[str[i] - 97]++;
    }

    for (int i = 0; i < 26; i++)
    {

        if (count[i] > 1)
        {
            // cout << str[i] + 97;
            cout << (char)(i + 97) << " occurs " << count[i] << " Times." << endl;
        }
    }
}

int main()
{
    string str;
    cout << "Enter String : ";
    getline(cin, str);

    int l = str.length();

    cout << endl
         << "1.Normal Method" << endl;
    cout << "2.Hashing" << endl;
    int ch;
    cin >> ch;

    switch (ch)
    {
    case 1:
        NormalMethod(str, l);
        break;
        {
        case 2:
            HashingMethod(str, l);
            break;

        default:
            cout << "Enter Valid Choice";
            break;
        }
    }
}