#include <iostream>
using namespace std;

void permutate(string str, int k)
{
    static int A[10] = {0};
    static string res(str.length(), ' '); // assign the string first with empty spaces
                                          //  if you want to use index
    if (k == str.length())
    {
        cout << res << ",";
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (A[i] == 0)
            {
                res[k] = str[i];
                A[i] = 1;
                permutate(str, k + 1);
                A[i] = 0;
            }
        }
    }
}

int main()
{
    string str;
    getline(cin, str);
    permutate(str, 0);
}
