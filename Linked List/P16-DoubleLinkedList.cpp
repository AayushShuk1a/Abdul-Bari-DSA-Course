#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class DoubleLL
{
private:
    Node *first;

public:
    DoubleLL(int A[], int n);
    void Display();
    void Insert(int index, int data);
    void Delete(int index);
};

void DoubleLL::Delete(int index)
{
    Node *p = first;
    if (index == 0)
    {
        if (p->next)
        {
            first = p->next;
            first->prev = NULL;
            delete p;
        }
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;

        delete p;
    }
}

DoubleLL::DoubleLL(int A[], int n)
{
    first = new Node;
    first->prev = NULL;
    first->next = NULL;
    first->data = A[0];
    Node *t, *last;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->prev = last;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void DoubleLL::Insert(int index, int data)
{
    Node *p = first, *t;
    t = new Node;
    t->data = data;
    if (index == 1)
    {
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 2; i < index; i++)
        {
            p = p->next;
        }

        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

void DoubleLL::Display()
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    int A[] = {1, 5, 7, 10, 15, 18, 21};

    DoubleLL doub(A, sizeof(A) / sizeof(A[0]));
    doub.Display();
    doub.Insert(8, 36);
    doub.Delete(7);

    cout << endl
         << "After Insert and Delete " << endl;

    doub.Display();
}