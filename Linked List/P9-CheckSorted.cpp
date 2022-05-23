#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Check
{
private:
    Node *first;

public:
    Check(int A[], int n);
    bool isSorted();
};

Check::Check(int A[], int n)
{
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

bool Check::isSorted()
{
    Node *p = first;
    int x = INT_MIN;
    while (p != NULL)
    {
        if (x > p->data)
        {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

int main()
{
    int A[] = {1, 5, 7, 10, 15, 18, 21};
    Check ch(A, sizeof(A) / sizeof(A[0]));
    cout << ch.isSorted();
}