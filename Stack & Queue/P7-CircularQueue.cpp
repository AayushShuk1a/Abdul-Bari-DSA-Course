#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int size;
    int rear;
    int front;
    int *Q;

public:
    CircularQueue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new int[size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void CircularQueue::enqueue(int x)
{
    if ((rear + 1) % size == front)
    {
        cout << "Queue is Full";
    }
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

int CircularQueue::dequeue()
{
    int x = -1;
    if (rear == front)
    {
        cout << "Queue is Empty";
    }
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

void CircularQueue::display()
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
    CircularQueue q(10);

    // Enqueue
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);
    q.enqueue(35);
    q.enqueue(40);

    // Display
    q.display();
}