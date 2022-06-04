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
};

void LinkedListStack::push(int val)
{
    Node *t = new Node;
    if (t == NULL)
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

int main()
{
    LinkedListStack LLS;
    LLS.push(10);
    LLS.push(19);
    LLS.push(22);
    LLS.push(5);
    LLS.push(100);
    LLS.Display();
}