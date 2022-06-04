#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedListStack
{
private:
    Node *top;

public:
    LinkedListStack() { top = NULL; }
    void push(int val);
    void pop();
    void Display();
    bool isFull();
    bool isEmpty();
    int StackTop();
};

bool LinkedListStack::isFull()
{
    Node *t = new Node;
    if (t == NULL)
        return true;
    else
        return false;
}

bool LinkedListStack::isEmpty()
{
    Node *p = top;
    if (p == NULL)
        return true;
    else
        return false;
}

void LinkedListStack::pop()
{
    Node *p = top;
    if (isEmpty())
    {
        cout << "Stack UnderFlowed" << endl;
    }
    else
    {
        top = p->next;
        delete p;
    }
}

void LinkedListStack::push(int val)
{
    Node *t = new Node;
    if (isFull())
    {
        cout << "Stack Overflowed" << endl;
    }
    else
    {
        t->data = val;
        t->next = top;
        top = t;
    }
}

void LinkedListStack::Display()
{
    Node *p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int LinkedListStack::StackTop()
{
    int x = -1;
    if (top)
        x = top->data;

    return x;
}

int main()
{
    LinkedListStack LLS;
    LLS.push(10);
    LLS.push(20);
    LLS.push(30);
    LLS.push(40);
    LLS.push(50);
    LLS.push(60);
    LLS.pop();
    LLS.Display();

    cout << endl
         << LLS.StackTop();
}