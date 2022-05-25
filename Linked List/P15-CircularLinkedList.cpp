#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Circular
{
private:
    Node *head;

public:
    Circular(int A[], int n);
    void display();
    void insert(int index, int data);
    void Delete();
    bool checkloop();
};

Circular::Circular(int A[], int n)
{
    Node *last, *t;
    head = new Node;
    head->data = A[0];

    if (n == 1)
    {
        head->next = head;
    }
    else
    {
        head->next = NULL;
        last = head;

        for (int i = 1; i < n; i++)
        {
            t = new Node;
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }

        last->next = head;
    }
}

bool Circular::checkloop()
{
    Node *p, *q;
    p = q = head;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);

    if (p == q)
    {
        return true;
    }

    return false;
}

void Circular::display()
{
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
}

void Circular::insert(int index, int data)
{
    Node *p, *t;
}

int main()
{
    int A[] = {5, 2, 555, 21, 34, 21, 44, 53};
    Circular circ(A, sizeof(A) / sizeof(A[0]));

    cout << circ.checkloop();

    circ.display();
}
