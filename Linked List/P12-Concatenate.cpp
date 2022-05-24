#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class ConcatenateLL
{
private:
    Node *first;

public:
    ConcatenateLL(int A[], int n);
    void display();
    void Concatenate(Node *firstArray, Node *secondArray);
    Node *getPointer() { return first; };
};

ConcatenateLL::ConcatenateLL(int A[], int n)
{
    Node *t, *last;
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

void ConcatenateLL::display()
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void ConcatenateLL::Concatenate(Node *firstArray, Node *secondArray)
{
    Node *p = firstArray;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = secondArray;
}

int main()
{
    int A[] = {1, 5, 7, 10, 15, 18, 21};
    ConcatenateLL con(A, sizeof(A) / sizeof(A[0]));
    con.display();
    cout << endl;
    int B[] = {23, 11, 4, 22, 554, 22, 45, 7, 422};
    ConcatenateLL con2(B, sizeof(B) / sizeof(B[0]));
    con2.display();

    Node *first = con.getPointer();
    Node *second = con2.getPointer();

    con.Concatenate(first, second);
    cout << endl
         << "Result " << endl;

    con.display();
}