#include <iostream>
#include <string>
#include <stack>
using namespace std;

int isOperand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
    {
        return 0;
    }
    return 1;
}

int operation(char ch, int x, int y)
{
    if (ch == '+')
        return x + y;
    if (ch == '*')
        return x * y;
    if (ch == '-')
        return x - y;
    if (ch == '/')
        return x / y;

    return 0;
}

int postfixEvaluate(string str)
{
    stack<int> stk;
    int result;
    for (int i = 0; i < str.length(); i++)
    {
        if (isOperand(str[i]))
        {
            // int typecast would not work because of char so subtract '0'
            stk.push(str[i] - '0');
        }
        else
        {
            int x = stk.top();
            stk.pop();
            int y = stk.top();
            stk.pop();
            result = operation(str[i], x, y);
            stk.push(result);
        }
    }

    result = stk.top();
    stk.pop();

    return result;
}

int main()
{
    string str = "23+45+*";
    cout << postfixEvaluate(str);
}