#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class ReverseLL
{
private:
    Node *first;

public:
    ReverseLL(int A[], int n);
    void display();
    void RevUsingArray(int n);                // Reversing Linked List using Array
    void RevUsingPointer();                   // Best Method using 3 pointer which slides(is called Slider Pointer)
    void RevUsingRecursion(Node *p, Node *q); // Reverse Using Recursion
    Node *getPointer()
    {
        return first;
    }
};

void ReverseLL::RevUsingRecursion(Node *p, Node *q)
{
    if (p)
    {
        RevUsingRecursion(p->next, p);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void ReverseLL::RevUsingPointer()
{
    Node *p, *q, *r;
    p = first;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

ReverseLL::ReverseLL(int A[], int n)
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

void ReverseLL::display()
{
    Node *p = first;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void ReverseLL::RevUsingArray(int n)
{
    int *Arr = new int[n];
    Node *p = first;
    for (int i = 0; i < n; i++)
    {
        Arr[i] = p->data;

        p = p->next;
    }
    p = first;
    for (int i = n - 1; i >= 0; i--)
    {
        p->data = Arr[i];
        p = p->next;
    }
}

int main()
{
    int A[] = {5, 10, 15, 20, 25, 30, 35};
    int B[] = {23, 43, 12, 65, 754, 32, 112, 54};
    ReverseLL rev(A, sizeof(A) / sizeof(A[0]));
    ReverseLL rev2(B, sizeof(B) / sizeof(B[0]));

    rev2.display();
    rev2.RevUsingArray(sizeof(B) / sizeof(B[0]));
    cout << endl
         << "after Reverse using Array " << endl;
    rev2.display();

    cout << endl
         << "Now Using Pointers " << endl;
    rev.display();
    cout << endl
         << "after Reverse" << endl;
    rev.RevUsingPointer();
    rev.display();

    // cout << endl
    //      << "after Reverse again" << endl;     //Using Recursion
    // Node *t = rev.getPointer();

    // rev.RevUsingRecursion(t, NULL);
    // rev.display();
}