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
    Node *Rinsert(Node *p, int key);
    void RInorder(Node *p);
    Node *GetRoot() { return root; }
    void SetRoot(Node *p) { root = p; }
};

void BST::RInorder(Node *p)
{
    if (p)
    {
        RInorder(p->Lchild);
        cout << p->data << " ";
        RInorder(p->Rchild);
    }
}

Node *BST::Rinsert(Node *p, int key)
{
    Node *t;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->Lchild = NULL;
        t->Rchild = NULL;
        return t;
    }
    if (key < p->data)
    {

        p->Lchild = Rinsert(p->Lchild, key);
    }
    else if (key > p->data)
    {
        p->Rchild = Rinsert(p->Rchild, key);
    }
    return p;
}

Node *BST::search(int value)
{
    Node *p = root;

    while (p != NULL)
    {
        if (p->data == value)
        {
            return p;
        }
        else if (value < p->data)
        {
            p = p->Lchild;
        }
        else if (value > p->data)
        {
            p = p->Rchild;
        }
    }

    return NULL;
}

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
    Node *root = t.Rinsert(t.GetRoot(), 26);
    t.SetRoot(root);
    t.Rinsert(t.GetRoot(), 21);
    t.Rinsert(t.GetRoot(), 11);
    t.Rinsert(t.GetRoot(), 19);
    t.Rinsert(t.GetRoot(), 30);
    t.Rinsert(t.GetRoot(), 15);

    t.RInorder(root);

    Node *search = t.search(12);
    if (search != NULL)
    {
        cout << endl
             << search->data << " Exist at " << search;
    }
    else
    {
        cout << endl
             << "Not found";
    }
}