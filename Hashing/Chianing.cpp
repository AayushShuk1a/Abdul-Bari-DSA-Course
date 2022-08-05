#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class HashTable
{
public:
    Node **HT;
    HashTable();
    void Insert(int key);
    int Search(int key);
};

HashTable::HashTable()
{
    HT = new Node *[10];
    for (int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }
}

void HashTable::Insert(int key)
{
    Node *t = new Node;
    t->data = key;
    t->next = NULL;
    int HIDX = key % 10;
    if (HT[HIDX] == NULL)
    {
        HT[HIDX] = t;
    }
    else
    {
        Node *p = HT[HIDX];
        Node *q = HT[HIDX];

        while (p && p->data < key)
        {
            q = p;
            p = p->next;
        }

        if (q == HT[HIDX])
        {
            t->next = HT[HIDX];
            HT[HIDX] = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int HashTable::Search(int key)
{
    int HIDX = key % 10;
    Node *p = HT[HIDX];
    while (p)
    {
        if (p->data == key)
        {
            return p->data;
        }
        else
        {
            p = p->next;
        }
    }

    return -1;
}

int main()
{
    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    int n = sizeof(A) / sizeof(A[0]);
    HashTable H;
    for (int i = 0; i < n; i++)
    {
        H.Insert(A[i]);
    }
    cout << "Successful Search" << endl;
    int key = 6;
    int value = H.Search(key);
    cout << "Key: " << key << ", Value: " << value << endl;
    cout << "Unsuccessful Search" << endl;
    key = 95;
    value = H.Search(key);
    cout << "Key: " << key << ", Value: " << value << endl;
}