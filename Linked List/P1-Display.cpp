#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);

    Node *getPointer()
    {
        return first;
    }
    void display();
    void RecursiveDisplay(Node *p);
};

void LinkedList::RecursiveDisplay(Node *p)
{

    if (p->next == NULL)
        return;

    cout << p->data << " ";
    RecursiveDisplay(p->next);
}

LinkedList::LinkedList(int A[], int n)
{
    first = new Node;
    Node *t, *last;
    int i = 0;
    // creating first Node
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i <= n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void LinkedList::display()
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
    int A[] = {5, 10, 15, 25, 28, 30};

    LinkedList ill(A, 6);
    ill.display();
    cout << endl;
    Node *t = ill.getPointer();
    ill.RecursiveDisplay(t);
}