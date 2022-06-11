#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue()
    {
        size = 10;
        front = rear = -1;
        Q = new int[size];
    }
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
    bool isFull();
    bool isEmpty();
    ~Queue()
    {
        delete[] Q;
    }
};

bool Queue::isFull()
{
    if (rear == size - 1)
        return true;

    return false;
}

bool Queue::isEmpty()
{
    if (front == rear)
        return true;

    return false;
}

void Queue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue is Full";
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "Queue is Empty";
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
    {

        cout << Q[i] << flush;
        if (i < rear)
        {
            cout << " <- " << flush;
        }
    }
}

int main()
{

    Queue q(10);

    // Enqueue
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);
    q.enqueue(35);
    q.enqueue(40);

    // Display
    q.display();
}