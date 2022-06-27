#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    Node *Lchild;
    int data;
    Node *Rchild;
};

class Iterative
{
private:
    Node *root;

public:
    Iterative() { root = NULL; }
    void createTree();
    void PreOrder(Node *p);
    void IPreOrder();
    void InOrder();
    Node *getRoot() { return root; }
};

void Iterative::InOrder()
{
    stack<Node *> stk;
    Node *p = root;

    while (p != NULL || !stk.empty())
    {
        if (p != NULL)
        {
            stk.emplace(p);
            p = p->Lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            cout << p->data << " ";
            p = p->Rchild;
        }
    }
}

void Iterative::IPreOrder()
{
    stack<Node *> stk;
    Node *p = root;

    while (p != NULL || !stk.empty())
    {
        if (p != NULL)
        {
            cout << p->data << " ";
            stk.emplace(p);
            p = p->Lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            p = p->Rchild;
        }
    }
}

void Iterative::PreOrder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        PreOrder(p->Lchild);
        PreOrder(p->Rchild);
    }
}

void Iterative::createTree()
{
    Node *t, *p;
    queue<Node *> q;
    int x;
    cout << "Enter Root value : ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->Lchild = NULL;
    root->Rchild = NULL;
    q.emplace(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter Left Child for " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->Lchild = t->Rchild = NULL;
            p->Lchild = t;
            q.emplace(t);
        }

        cout << "Enter Right Child for " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->Lchild = NULL;
            t->Rchild = NULL;
            p->Rchild = t;
            q.emplace(t);
        }
    }
}

int main()
{
    Iterative it;
    it.createTree();
    Node *p = it.getRoot();
    it.PreOrder(p);
    cout << endl;
    it.IPreOrder();
    cout << endl;
    it.InOrder();
}