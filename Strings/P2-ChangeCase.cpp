#include <iostream>
using namespace std;

int main()
{
    char ch[100];
    cout << "Enter World : ";
    gets(ch);

    cout
        << endl
        << "1.Lower To UpperCase" << endl;
    cout << "2.UpperCase to LowerCase" << endl;
    cout << "3.Toggle Cases" << endl;
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        for (int i = 0; ch[i] != '\0'; i++)
        {
            if (ch[i] >= 97 && ch[i] <= 122)
            {
                ch[i] = ch[i] - 32;
            }
        }
        break;
    case 2:
        for (int i = 0; ch[i] != '\0'; i++)
        {
            if (ch[i] >= 65 && ch[i] <= 90)
            {
                ch[i] = ch[i] + 32;
            }
        }
    case 3:
        for (int i = 0; ch[i] != '\0'; i++)
        {
            if (ch[i] >= 65 && ch[i] <= 90)
            {
                ch[i] = ch[i] + 32;
            }
            else if (ch[i] >= 97 && ch[i] <= 122)
            {
                ch[i] = ch[i] - 32;
            }
        }

        break;

    default:
        cout << "Enter Valid Choice";
        break;
    }

    cout << ch;
}