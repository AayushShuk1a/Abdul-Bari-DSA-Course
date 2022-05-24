#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CheckLoopLL
{
private:
    Node *first;

public:
    CheckLoopLL(int A[], int n);
    bool checkloop();
    Node *getPointer() { return first; }
};

CheckLoopLL::CheckLoopLL(int A[], int n)
{
    Node *last, *t;
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

bool CheckLoopLL::checkloop()
{
    Node *p, *q;
    p = q = first;

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

int main()
{
    int A[] = {1, 5, 7, 10};
    CheckLoopLL CL(A, sizeof(A) / sizeof(A[0]));
    Node *first = CL.getPointer();

    Node *t1 = first->next;
    Node *t2 = first->next->next->next;
    t2->next = t1;

    int value = CL.checkloop();

    value == 0 ? cout << "Not Loop" : cout << "Is Loop";
}