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
};

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
    if (top == size - 1)
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
    if (top == -1)
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

    stck.Display();
}