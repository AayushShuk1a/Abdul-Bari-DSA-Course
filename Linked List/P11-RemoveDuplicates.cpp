#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class DuplicatesLL
{
private:
    Node *first;

public:
    DuplicatesLL(int A[], int n);
    void Display();
    void RemoveDuplicates();
};

DuplicatesLL::DuplicatesLL(int A[], int n)
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

void DuplicatesLL::Display()
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void DuplicatesLL::RemoveDuplicates()
{
    Node *p = first;
    Node *q = p->next;
    while (q != NULL)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}

int main()
{
    int A[] = {1, 5, 5, 5, 15, 18, 18};
    DuplicatesLL dup(A, sizeof(A) / sizeof(A[0]));

    dup.Display();
    cout << endl
         << "After Removing Duplicates " << endl;

    dup.RemoveDuplicates();
    dup.Display();
}