#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class CDLL
{
private:
    Node *head;

public:
    CDLL(int A[], int n);
    void Display();
    void Insert(int index, int value);
    void Delete(int index);
    bool CheckLoop();
    int length();
};

int CDLL::length()
{
    Node *p = head;
    int len = 0;
    do
    {
        len++;
        p = p->next;

    } while (p != head);
    return len;
}

void CDLL::Delete(int index)
{
    Node *p = head;
    if (index < 0 || index > length())
    {
        cout << endl
             << "Enter Valid Index";
        return;
    }
    else if (index == 0)
    {
        p->next->prev = p->prev;
        p->prev->next = p->next;
        head = p->next;
        delete p;
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        p->next->prev = p->prev;
        p->prev->next = p->next;
        delete p;
    }
}

void CDLL::Insert(int index, int value)
{
    Node *p = head, *t;
    t = new Node;
    t->data = value;

    if (index < 0 || index > length())
    {
        cout << endl
             << "Enter Valid Index";
        return;
    }

    if (index == 0)
    {
        t->next = head;
        t->prev = head->prev;
        head->prev->next = t;
        head->prev = t;
        head = t;
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
    }
}

bool CDLL::CheckLoop()
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

CDLL::CDLL(int A[], int n)
{
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->prev = head;
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }

    last->next = head;
    head->prev = t;
}

void CDLL::Display()
{
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;

    } while (p != head);
}

int main()
{
    int A[] = {5, 19, 23, 11, 34, 92, 22, 33};
    CDLL list(A, sizeof(A) / sizeof(A[0]));

    list.Display();

    list.Insert(8, 99);
    cout << endl
         << "After Insert : ";
    list.Display();

    list.Delete(7);

    cout << endl
         << "After Delete : ";
    list.Display();
    cout << endl
         << list.CheckLoop() << endl;
}
