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
    Circular() { head = NULL; };
    Circular(int A[], int n);
    void display();
    void insert(int index, int data);
    void Delete();
    bool checkloop();
    int length();
};

int Circular::length()
{
    Node *p = head;
    int c = 1;
    if (p)
    {

        do
        {
            c++;
            p = p->next;

        } while (p != head);
    }
    return c;
}

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

    if (p && q && p == q)
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
    Node *p = head, *t;
    t = new Node;
    t->data = data;

    if (index > length() || index < 0)
    {
        cout << "Enter the value at " << length() << " not at " << index << endl;
        return;
    }

    if (index == 1)
    {
        t->next = head;
        if (p == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {

            do
            {
                p = p->next;

            } while (p->next != head);
            p->next = t;
        }
    }
    else
    {
        for (int i = 2; i < index; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    // int A[] = {};
    Circular circ;

    // cout << circ.length() << endl;
    circ.insert(1, 32);
    circ.insert(2, 13);
    circ.insert(3, 45);

    circ.insert(4, 77);
    circ.insert(5, 97);
    circ.insert(6, 88);
    circ.insert(7, 100);

    cout << circ.checkloop() << endl;

    circ.display();
}
