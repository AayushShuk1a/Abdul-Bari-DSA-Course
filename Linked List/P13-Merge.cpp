#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class MergeLL
{
private:
    Node *first;

public:
    MergeLL(int A[], int n);
    void display();
    void Merge(Node *firstArray, Node *secondArray);
    Node *getPointer() { return first; }
};

MergeLL::MergeLL(int A[], int n)
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

void MergeLL::display()
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void MergeLL::Merge(Node *firstArray, Node *secondArray)
{
    Node *third, *pos;
    if (firstArray->data < secondArray->data)
    {
        third = firstArray;
        pos = firstArray;
        firstArray = firstArray->next;
        third->next = NULL;
    }
    else
    {
        third = secondArray;
        pos = secondArray;
        secondArray = secondArray->next;
        third->next = NULL;
    }

    while (firstArray != NULL && secondArray != NULL)
    {
        if (firstArray->data < secondArray->data)
        {
            pos->next = firstArray;
            pos = firstArray;

            firstArray = firstArray->next;
            pos->next = NULL;
        }
        else
        {
            pos->next = secondArray;
            pos = secondArray;
            secondArray = secondArray->next;
            pos->next = NULL;
        }
    }

    if (firstArray != NULL)
    {
        pos->next = firstArray;
    }
    else
    {
        pos->next = secondArray;
    }

    first = third;
}

int main()
{
    int A[] = {1, 5, 7, 10, 15, 18, 21};
    MergeLL con(A, sizeof(A) / sizeof(A[0]));
    con.display();
    cout << endl;
    int B[] = {23, 11, 4, 22, 554, 22, 45, 7, 422};
    MergeLL con2(B, sizeof(B) / sizeof(B[0]));
    con2.display();

    Node *first = con.getPointer();
    Node *second = con2.getPointer();

    con.Merge(first, second);
    cout << endl
         << "Result " << endl;
    con.display();
}