#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class SortedArray
{
private:
    Node *first;

public:
    SortedArray(int A[], int n);
    void display();
    void insert(int key);
};

SortedArray::SortedArray(int A[], int n)
{
    Node *t, *last;
    first = new Node();
    first->data = A[0];
    first->next = NULL;
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

void SortedArray::display()
{
    Node *p = first;
    while (p->next != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void SortedArray::insert(int key)
{
    Node *p, *q;
    Node *t;
    p = first;
    t = new Node;
    t->data = key;
    t->next = NULL;

    if (first == NULL) // Checking if the list is empty
        first = t;
    while (p->next && p->data < key) // Looping in the list
    {
        q = p;
        p = p->next;
    }

    if (p == first) // if the value is smallest
    {
        t->next = first;
        first = t;
    }
    else
    {

        t->next = q->next;
        q->next = t;
    }
}

int main()
{
    int A[] = {2, 5, 6, 10, 15, 18, 19};
    SortedArray Sa(A, sizeof(A) / sizeof(A[0]));

    Sa.display();

    Sa.insert(1);

    cout << endl
         << "After Insert " << endl;

    Sa.display();
}