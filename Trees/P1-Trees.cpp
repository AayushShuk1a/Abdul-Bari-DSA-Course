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
};

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
        cout << "Enter Left Child";
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

        cout << "Enter Right Child";
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
