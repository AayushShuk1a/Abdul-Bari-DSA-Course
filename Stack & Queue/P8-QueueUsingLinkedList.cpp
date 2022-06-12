#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class QueueLL
{
private:
    Node *front;
    Node *rear;

public:
    QueueLL()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void QueueLL::enqueue(int x)
{
    Node *t = new Node;
    if (t == NULL)
    {
        cout << "Queue is Full";
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int QueueLL::dequeue()
{
    int x = -1;
    if (front == NULL)
    {
        cout << "Queue is Empty";
    }
    else
    {
        Node *p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

void QueueLL::display()
{
    Node *p = front;
    while (p != NULL)
    {
        cout << p->data;
        p = p->next;
        if (p != NULL)
        {
            cout << " <- " << flush;
        }
    }
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    QueueLL q;

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        q.enqueue(A[i]);
    }

    q.display();
    return 0;

    // for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    // {
    //     q.dequeue();
    // }
    // q.dequeue();
}