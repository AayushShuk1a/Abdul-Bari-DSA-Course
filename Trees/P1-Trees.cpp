#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    Node *Lchild;
    int data;
    Node *Rchild;
};

class Tree
{
private:
    Node *root;

public:
    Tree() { root = NULL; }
    void createTree();
    void preOrder(Node *p);
    Node *getRoot() { return root; }
};

void Tree::preOrder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preOrder(p->Lchild);
        preOrder(p->Rchild);
    }
}

void Tree::createTree()
{
    Node *t, *p;
    int x;
    queue<Node *> q;
    cout << "Enter Root Value";
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
        cout << "Enter Left Child for " << p->data;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->Lchild = NULL;
            t->Rchild = NULL;
            p->Lchild = t;
            q.emplace(t);
        }

        cout << "Enter Right Child for " << p->data;
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
    Tree t;
    t.createTree();

    Node *p = t.getRoot();
    t.preOrder(p);
}
