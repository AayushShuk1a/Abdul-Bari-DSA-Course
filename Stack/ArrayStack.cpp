#include <iostream>
using namespace std;

class ArrayStack
{
private:
    int size;
    int top;
    int *A;

public:
    ArrayStack(int size);
    ~ArrayStack();
    void Display();
    void push(int value);
    int pop();
    bool isEmpty();
    bool isfull();
    int peek(int pos);
    int StackTop();
};

int ArrayStack::StackTop()
{
    if (top == -1)
        return -1;
    else
        return A[top];
}

int ArrayStack::peek(int pos)
{
    int x = -1;
    if (top - pos + 1 < 0 || top - pos + 1 > size - 1)
    {
        cout << "Invalid Index";
    }
    else
    {
        x = A[top - pos + 1]; // Formuala to find position in stack
    }
    return x;
}

bool ArrayStack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ArrayStack::isfull()
{
    if (top == size - 1)
        return true;
    else
        return false;
}

ArrayStack::~ArrayStack()
{
    delete[] A;
}

ArrayStack::ArrayStack(int size)
{
    this->size = size;
    top = -1;
    A = new int[size];
}

void ArrayStack::Display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << A[i] << " " << flush;
    }
}

void ArrayStack::push(int value)
{
    if (isfull())
    {
        cout << "Stack Overflowed" << endl;
    }
    else
    {
        top++;
        A[top] = value;
    }
}

int ArrayStack::pop()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "Stack Underdflowed" << endl;
    }
    else
    {
        x = A[top];
        top--;
    }

    return x;
}

int main()
{
    cout << "Enter Size of the Stack : ";
    int n;
    cin >> n;
    ArrayStack stck(n);

    stck.push(10);
    stck.push(20);
    stck.push(30);
    stck.push(40);
    stck.push(50);
    stck.pop();
    cout << "Peek Value is " << stck.peek(2) << endl;

    stck.Display();
}