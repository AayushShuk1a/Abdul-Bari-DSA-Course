#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CountLL
{
private:
    Node *first;

public:
    CountLL(int A[], int n);

    int count();
};

CountLL::CountLL(int A[], int n)
{
    first = new Node;
    Node *t, *last;
    first->data = A[0];
    first->next = NULL;
    last = first;
    int i = 0;
    for (i = 1; i <= n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int CountLL::count()
{
    Node *p;
    p = first;
    int c = 0;
    while (p->next != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int main()
{
    int A[] = {5, 10, 15, 2, 3, 42, 4};
    CountLL CL(A, 7);

    cout << CL.count();
}
