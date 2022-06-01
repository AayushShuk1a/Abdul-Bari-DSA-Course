#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class ReverseDL
{
private:
    Node *first;

public:
    ReverseDL(int A[], int n);
    void Display();
    void Reverse();
};

ReverseDL::ReverseDL(int A[], int n)
{
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void ReverseDL::Display()
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void ReverseDL::Reverse()
{
    Node *p = first, *temp;
    while (p != NULL)
    {
        if (p && p->next == NULL)
        {

            first = p;
        }
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
    }
}

int main()
{
    int A[] = {1, 5, 7, 10, 15, 18, 21};

    ReverseDL rev(A, sizeof(A) / sizeof(A[0]));

    rev.Display();

    rev.Reverse();
    cout << endl
         << "After Reverse :" << endl;

    rev.Display();
}