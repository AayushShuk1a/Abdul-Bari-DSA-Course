#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    int coeff;
    int pow;
    Node *next;
};

class Polynomial
{
private:
    Node *first;

public:
    Polynomial();
    void Display();
    long sum(int x);
};

long Polynomial::sum(int x)
{
    long val = 0;
    Node *p = first;
    while (p != NULL)
    {
        val += p->coeff * pow(x, p->pow);
        p = p->next;
    }

    return val;
}

Polynomial::Polynomial()
{
    first = NULL;
    Node *t, *last;
    int num;
    cout << "Enter Number of elements ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        t = new Node;
        cin >> t->coeff >> t->pow;
        t->next = NULL;
        if (first == NULL)
        {
            first = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void Polynomial::Display()
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->coeff << "x" << p->pow << " "
             << "+"
             << " ";
        p = p->next;
    }
}

int main()
{
    Polynomial poly;

    poly.Display();

    cout << endl
         << "Enter Value of X";
    int x;
    cin >> x;

    cout << endl
         << poly.sum(x);
}