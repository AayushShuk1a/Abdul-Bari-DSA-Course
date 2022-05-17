#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class InsertLL
{
private:
    Node *first;

public:
    InsertLL(int A[], int n);
    void Display();
    void Insert(int index, int value);
};

void InsertLL::Insert(int index, int value)
{
    Node *p = first;
    Node *t;
    t = new Node;

    if (index == 0)
    {
        t->data = value;
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        t->data = value;
        t->next = p->next;
        p->next = t;
    }
}

InsertLL::InsertLL(int A[], int n)
{
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    Node *t, *last;
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

void InsertLL::Display()
{
    Node *p = first;
    while (p->next != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    int A[] = {20, 30, 12, 32, 22, 45, 42, 12};
    InsertLL insert(A, sizeof(A) / sizeof(A[0]));

    cout << "Before Inserting : ";
    insert.Display();

    insert.Insert(1, 79);

    cout << endl
         << "After Inserting : ";
    insert.Display();
}
