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
    Node *LRRotation(Node *p);
    Node *RLRotation(Node *p);
    void PreOrder(Node *p);
    Node *GetRoot() { return root; }
};

void AVLRotations::PreOrder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        PreOrder(p->Lchild);
        PreOrder(p->Rchild);
    }
}

int AVLRotations::BalanceFactor(Node *p)
{
    int hl, hr;
    hl = p && p->Lchild ? p->Lchild->height : 0;
    hr = p && p->Rchild ? p->Rchild->height : 0;

    return hl - hr;
}

Node *AVLRotations::LRRotation(Node *p)
{
    Node *pl = p->Lchild;
    Node *plr = pl->Rchild;

    // Rotation
    pl->Rchild = plr->Lchild;
    plr->Lchild = pl;
    p->Lchild = plr->Rchild;
    plr->Rchild = p;

    // Update Height
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);
    pl->height = NodeHeight(pl);

    // Check if the value entered is root
    if (p == root)
    {
        root = plr;
    }

    return plr;
}

Node *AVLRotations::RLRotation(Node *p)
{
    Node *pr = p->Rchild;
    Node *prl = pr->Lchild;

    pr->Lchild = prl->Rchild;
    prl->Rchild = pr;

    p->Rchild = prl->Lchild;
    prl->Lchild = p;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (p == root)
    {
        root = prl;
    }

    return prl;
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

    if (p == root)
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
        if (root == NULL)
        {
            root = t;
        }
        return t;
    }

    if (key < p->data)
    {
        p->Lchild = Insert(p->Lchild, key);
    }
    else if (key > p->data)
    {
        p->Rchild = Insert(p->Rchild, key);
    }

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->Lchild) == 1)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->Rchild) == -1)
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->Lchild) == -1)
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->Rchild) == 1)
    {
        return RLRotation(p);
    }

    return p;
}

int main()
{
    AVLRotations AV;

    AV.Insert(AV.GetRoot(), 10);
    AV.Insert(AV.GetRoot(), 20);
    AV.Insert(AV.GetRoot(), 30);
    AV.Insert(AV.GetRoot(), 25);
    AV.Insert(AV.GetRoot(), 28);
    AV.Insert(AV.GetRoot(), 27);
    AV.Insert(AV.GetRoot(), 5);
    AV.Insert(AV.GetRoot(), 15);
    AV.Insert(AV.GetRoot(), 19);

    AV.PreOrder(AV.GetRoot());
}