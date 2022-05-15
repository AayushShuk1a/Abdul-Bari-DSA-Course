#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class SumLL
{
private:
    Node *first;

public:
    SumLL(int A[], int n);
    int sum();
    int sumRecursively(Node *p);
    Node *getPointer()
    {
        return first;
    }
};

SumLL::SumLL(int A[], int n)
{
    first = new Node;
    Node *t, *last;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i <= n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int SumLL::sum()
{
    int sum = 0;
    Node *p = first;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int SumLL::sumRecursively(Node *p)
{
    if (p == NULL)
        return 0;

    return sumRecursively(p->next) + p->data;
}

int main()
{
    int A[] = {10, 15, 20, 25, 30, 35};
    int length = sizeof(A) / sizeof(A[0]);
    SumLL sum(A, length);
    int totalsum = sum.sum();
    cout << totalsum;
    Node *t = sum.getPointer();
    cout << endl
         << "Recursively :";
    cout << sum.sumRecursively(t);
}