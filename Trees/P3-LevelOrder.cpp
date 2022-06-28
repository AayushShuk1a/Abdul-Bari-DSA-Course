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
    Tree() { root = NULL; };
    void createTree();
    void LevelOrder();
};

void Tree::createTree()
{
    Node *t, *p;
    int x;
    queue<Node *> q;
    root = new Node;
    cout << "Enter Value of Root : ";
    cin >> x;
    root->data = x;
    root->Lchild = NULL;
    root->Rchild = NULL;
    q.emplace(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter Left Node for " << p->data << " ";
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

void Tree::LevelOrder()
{
    Node *p = root;
    queue<Node *> q;
    q.emplace(p);
    cout << root->data;

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p->Lchild != NULL)
        {
            cout << p->Lchild->data << " ";
            q.emplace(p->Lchild);
        }

        if (p->Rchild != NULL)
        {
            cout << p->Rchild->data << " ";
            q.emplace(p->Rchild);
        }
    }
}

int main()
{
    Tree t;
    t.createTree();
    t.LevelOrder();
}