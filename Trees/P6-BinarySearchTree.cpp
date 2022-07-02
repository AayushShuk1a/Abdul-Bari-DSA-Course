#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    Node *Lchild;
    int data;
    Node *Rchild;
};

class BST
{
private:
    Node *root;

public:
    BST() { root = NULL; }
    void insert(int key);
    Node *search(int value);
    void Inorder();
};

void BST::insert(int key)
{
    Node *p, *r;
    Node *t = root;

    // If the Tree is empty
    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->Lchild = NULL;
        p->Rchild = NULL;
        root = p;
        return;
    }

    // Moving Nodes Till end
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->Lchild;
        else if (key > t->data)
            t = t->Rchild;
        else
            return;
    }

    p = new Node;
    p->data = key;
    p->Lchild = NULL;
    p->Rchild = NULL;
    if (key < r->data)
    {
        r->Lchild = p;
    }
    else
    {
        r->Rchild = p;
    }
}

void BST::Inorder()
{
    Node *p = root;
    stack<Node *> st;
    while (p != NULL || !st.empty())
    {
        if (p)
        {
            st.emplace(p);
            p = p->Lchild;
        }
        else
        {
            p = st.top();
            st.pop();
            cout << p->data << " ";
            p = p->Rchild;
        }
    }
}

int main()
{
    BST t;
    t.insert(20);
    t.insert(9);
    t.insert(11);
    t.insert(64);
    t.insert(12);
    t.insert(15);

    t.Inorder();
}