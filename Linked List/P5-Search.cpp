#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class SearchLL
{
private:
    Node *first;

public:
    SearchLL(int A[], int n);
    int Search(int key);
    int RecursiveSearch(Node *p, int key);
    Node *getPointer()
    {
        return first;
    }
    int improveSearch(int key);
    void Display();
};

void SearchLL::Display()
{
    Node *p = first;
    while (p->next != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int SearchLL::improveSearch(int key)
{
    Node *p = first;
    Node *q;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
        }
        q = p;
        p = p->next;
    }
    return 0;
}

SearchLL::SearchLL(int A[], int n)
{
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    Node *t, *last;
    last = first;
    for (int i = 1; i <= n; i++)
    {

        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int SearchLL::Search(int key)
{
    Node *p = first;
    while (p->next != NULL)
    {
        // check and return
        if (p->data == key)
        {
            return p->data;
        }
        p = p->next;
    }
    return 0;
}

int SearchLL::RecursiveSearch(Node *p, int key)
{
    if (p->next == NULL)
        return 0;
    else if (p->data == key)
    {
        return p->data;
    }

    return RecursiveSearch(p->next, key);
}

int main()
{
    int A[] = {20, 30, 12, 32, 22, 45, 42, 12};
    SearchLL search(A, sizeof(A) / sizeof(A[0]));

    cout << "Normal Search : " << search.Search(20) << endl;

    Node *p = search.getPointer();
    cout << "Recursive Search : " << search.RecursiveSearch(p, 45) << endl;

    cout << endl
         << "Before Improve Search : ";
    search.Display();

    cout
        << endl
        << "After Improve Search : ";

    search.improveSearch(45);
    search.Display();
}