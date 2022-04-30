#include <iostream>
using namespace std;

int main()
{
    char ch[100];
    cout << "Enter word : ";
    gets(ch);

    cout
        << endl
        << "1.Count Vowels" << endl;
    cout << "2.Count Consonants" << endl;
    cout << "3.Count Number of Words" << endl;
    int choice;
    cin >> choice;
    int count = 0;

    switch (choice)
    {
    case 1:
        for (int i = 0; ch[i] != '\0'; i++)
        {
            if (ch[i] == 'A' || ch[i] == 'E' || ch[i] == 'I' || ch[i] == 'O' || ch[i] == 'U' || ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')
            {
                count++;
            }
        }
        break;

    case 2:
        for (int i = 0; ch[i] != '\0'; i++)
        {
            if ((ch[i] >= 65 && ch[i] <= 90) || (ch[i] >= 97 && ch[i] <= 122))
            {
                count++;
            }
        }
        break;

    case 3:
        for (int i = 0; ch[i] != '\0'; i++)
        {
            if (ch[i] == ' ' && ch[i - 1] != ' ')
            {
                count++;
            }
        }
        count++;
        break;

    default:
        cout << "Enter Valid Choice";
        break;
    }

    cout << count;
}