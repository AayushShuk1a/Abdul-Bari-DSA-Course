#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

bool PranthesisMatching(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {

            s.push(str[i]);
        }
        else if (str[i] == '}' || str[i] == ']' || str[i] == ')')
        {
            if (s.empty())
            {
                return false;
            }
            else
            {

                if (str[i] - s.top() == 1 || str[i] - s.top() == 2) // ASCII diff between () is 1 and diff b/w {} and
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }

    if (s.empty())
        return true;
    else
        return false;
}

int main()
{
    cout << "Enter String : ";
    string str;
    getline(cin, str);
    if (PranthesisMatching(str))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }
}
