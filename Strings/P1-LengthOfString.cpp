#include <iostream>
using namespace std;

int main()
{
    char ch[100];
    int i;

    cout << "Enter Word : ";

    gets(ch);

    for (i = 0; ch[i] != '\0'; i++)
    {
    }

    cout << endl
         << "The length of the Word is : " << i;
}