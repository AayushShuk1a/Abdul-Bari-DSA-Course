#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int isOperand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')')
    {
        return 0;
    }

    return 1;
}

int OutStack(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '^')
        return 6;
    else if (ch == '(')
        return 7;
    else if (ch == ')')
        return 0;
    else
        return -1;
}

int InStack(char ch)
{
    if (ch == '+' || ch == '-')
        return 2;
    else if (ch == '*' || ch == '/')
        return 4;
    else if (ch == '^')
        return 5;
    else if (ch == '(')
        return 0;
    else
        return -1;
}

string InfixtoPostfix(string str)
{

    string postfix = "";
    stack<char> stk;

    for (int i = 0; i < str.length(); i++)
    {

        if (isOperand(str[i]))
        {
            postfix.push_back(str[i]);
        }
        else
        {
            if (stk.empty() || OutStack(str[i]) > InStack(stk.top()))
            {
                stk.push(str[i]);
            }
            else if (OutStack(str[i]) == InStack(stk.top()))
            {
                stk.pop();
            }
            else
            {
                postfix.push_back(stk.top());
                stk.pop();
            }
        }
    }

    while (!stk.empty() && stk.top() != '(')
    {

        postfix.push_back(stk.top());
        stk.pop();
    }

    return postfix;
}

int main()
{
    string str = "((a+b)*c)-d^e^f";

    cout << InfixtoPostfix(str);
}