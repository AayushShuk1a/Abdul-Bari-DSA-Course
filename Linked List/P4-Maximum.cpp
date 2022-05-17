#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class MaximumLL
{
private:
    Node *first;

public:
    MaximumLL(int A[], int n);
    int maximum();
    int maximumRecursively(Node *t);
    void display();
    Node *getPointer()
    {
        return first;
    }
};

void MaximumLL::display()
{
    Node *p = first;
    while (p->next != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

MaximumLL::MaximumLL(int A[], int n)
{
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    Node *t, *last;
    last = first;
    int i = 0;
    for (i = 1; i <= n; i++)
    {

        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int MaximumLL::maximum()
{

    int max = INT_MIN;
    Node *p = first;
    while (p->next != NULL)
    {

        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int MaximumLL::maximumRecursively(Node *t)
{
    if (t->next == NULL)
        return INT_MIN;

    // return
    int max = maximumRecursively(t->next);
    // check and return max
    if (max > t->data)
    {
        return max;
    }
    else
    {
        return t->data;
    }
}

int main()
{
    int A[] = {20, 30, 12, 32, 22, 45, 42, 12};
    int length = sizeof(A) / sizeof(A[0]);

    MaximumLL max(A, length);

    max.display();

    cout << endl
         << "Maximum is : " << max.maximum();

    Node *t;
    t = max.getPointer();
    cout << endl
         << "Maximum is : " << max.maximumRecursively(t);
}