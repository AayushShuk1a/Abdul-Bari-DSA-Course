#include <iostream>
using namespace std;

int main()
{
    char ch[100];
    cout << "Enter String : ";
    gets(ch);

    bool valid;
    for (int i = 0; ch[i] != '\0'; i++)
    {

        if ((ch[i] >= 65 && ch[i] <= 90) || (ch[i] >= 97 && ch[i] <= 122) || (ch[i] >= 48 && ch[i] <= 57) || (ch[i] == 32))
        {
            valid = true;
        }
        else
        {

            valid = false;
            break;
        }
    }

    if (valid == true)
    {
        cout << "String is Valid";
    }
    else
    {
        cout << "String is Invalid";
    }
}