#include <iostream>
using namespace std;

class Node
{
public:
    Node *Lchild;
    int data;
    int height;
    Node *Rchild;
};

class AVLRotations
{
private:
    Node *root;

public:
    AVLRotations() { root = NULL; }
    Node *Insert(Node *p, int key);
    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node *LLRotation(Node *p);
    Node *RRRotation(Node *p);
};

int AVLRotations::BalanceFactor(Node *p)
{
    int hl, hr;
    hl = p && p->Lchild ? p->Lchild->height : 0;
    hl = p && p->Rchild ? p->Rchild->height : 0;

    return hl - hr;
}

Node *AVLRotations::RRRotation(Node *p)
{
    Node *pr = p->Rchild;
    Node *prl = pr->Lchild;

    // Rotation
    pr->Lchild = p;
    p->Rchild = prl;

    // updateheight
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (p == root)
    {
        root = pr;
    }
    return pr;
}

Node *AVLRotations::LLRotation(Node *p)
{
    Node *pl = p->Lchild;
    Node *plr = pl->Rchild;

    // Rotation
    pl->Rchild = p;
    p->Lchild = plr;

    // UpdateHeight
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root = p)
    {
        root = pl;
    }

    return pl;
};

int AVLRotations::NodeHeight(Node *p)
{
    int hl, hr;
    hl = p && p->Lchild ? p->Lchild->height : 0;
    hr = p && p->Rchild ? p->Rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

Node *AVLRotations::Insert(Node *p, int key)
{
    Node *t;

    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->Lchild = t->Rchild = NULL;
        return t;
    }

    if (key < p->data)
    {
        p->Lchild = Insert(p->Lchild, key);
    }
    else
    {
        p->Rchild = Insert(p->Rchild, key);
    }

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->Lchild) == 1)
    {
        return LLRotation(p);
    }
    if (BalanceFactor(p) == 2 && BalanceFactor(p->Rchild) == -1)
    {
        return RRRotation(p);
    }

    return p;
}