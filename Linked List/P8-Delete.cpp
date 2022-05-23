#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Delete
{
private:
    Node *first;

public:
    Delete(int A[], int n);
    void display();
    void deleteNode(int index);
};

Delete::Delete(int A[], int n)
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

void Delete::display()
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void Delete::deleteNode(int index)
{
    Node *p = first;
    Node *q;
    if (index == 1)
    {
        first = p->next;
        delete p;
        return;
    }
    else
    {
        for (int i = 2; i <= index; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        delete p;
    }
}

int main()
{
    int A[] = {5, 10, 23, 31, 42, 21, 54, 24};
    Delete del(A, sizeof(A) / sizeof(A[0]));

    del.display();
    cout << endl
         << "After Delete " << endl;
    // del.deleteNode(0);
    del.deleteNode(8);

    del.display();
}