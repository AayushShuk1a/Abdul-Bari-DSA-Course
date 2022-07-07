#include <iostream>
using namespace std;

class Node
{
public:
    Node *Lchild;
    int height;
    int data;
    Node *Rchild;
};

class Tree
{
private:
    Node *root;

public:
    Tree() { root = NULL; }
    Node *CreateTree(Node *p, int A);
    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node *LLRotation(Node *p);
    Node *RLRotation(Node *p);
    Node *LRRotation(Node *p);
    Node *RRRotation(Node *p);
    void preorder(Node *p);
    Node *GetRoot() { return root; }
    Node *Delete(Node *p, int key);
    Node *InOrdPre(Node *p);
    Node *InOrdSuc(Node *p);
};

Node *Tree::InOrdPre(Node *p)
{
    while (p && p->Rchild)
    {
        p = p->Rchild;
    }
    return p;
}

Node *Tree::InOrdSuc(Node *p)
{
    while (p && p->Lchild)
    {
        p = p->Lchild;
    }

    return p;
}

Node *Tree::Delete(Node *p, int key)
{
    Node *temp;
    if (p == NULL)
    {
        return NULL;
    }

    if (p->Lchild == NULL && p->Rchild == NULL)
    {
        if (p == root)
            root = NULL;

        delete p;
        return NULL;
    }

    if (key < p->data)
    {
        p->Lchild = Delete(p->Lchild, key);
    }
    else if (key > p->data)
    {
        p->Rchild = Delete(p->Rchild, key);
    }
    else
    {
        if (NodeHeight(p->Lchild) > NodeHeight(p->Rchild))
        {
            temp = InOrdPre(p->Lchild);
            p->data = temp->data;
            p->Lchild = Delete(p->Lchild, temp->data);
        }
        else
        {
            temp = InOrdSuc(p->Rchild);
            p->data = temp->data;
            p->Rchild = Delete(p->Rchild, temp->data);
        }
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

void Tree::preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->Lchild);
        preorder(p->Rchild);
    }
}

Node *Tree::LRRotation(Node *p)
{
    Node *pl = p->Lchild;
    Node *plr = pl->Rchild;

    // rotation
    p->Lchild = plr->Rchild;
    pl->Rchild = plr->Lchild;

    plr->Rchild = p;
    plr->Lchild = pl;

    // UpdateHeight
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if (p == root)
        root = plr;

    return plr;
}

Node *Tree::RLRotation(Node *p)
{
    Node *pr = p->Rchild;
    Node *prl = pr->Lchild;

    // rotation
    pr->Lchild = prl->Rchild;
    p->Rchild = prl->Lchild;

    prl->Lchild = p;
    prl->Rchild = pr;

    // updateheight
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (p == root)
        root = prl;

    return prl;
}

Node *Tree::RRRotation(Node *p)
{
    Node *pr = p->Rchild;
    Node *prl = pr->Lchild;

    // rotation
    p->Rchild = prl;
    pr->Lchild = p;

    // updateHeight
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (p == root)
    {
        root = pr;
    }

    return pr;
}

Node *Tree::LLRotation(Node *p)
{
    Node *pl = p->Lchild;
    Node *plr = pl->Rchild;

    // rotation
    p->Lchild = plr;
    pl->Rchild = p;

    // updateHeight
    p->height = NodeHeight(p);
    p->height = NodeHeight(pl);

    if (p == root)
    {
        root = pl;
    }

    return pl;
}

int Tree::BalanceFactor(Node *p)
{
    int hl = p && p->Lchild ? p->Lchild->height : 0;
    int hr = p && p->Rchild ? p->Rchild->height : 0;

    return hl - hr;
}

int Tree::NodeHeight(Node *p)
{
    int hl = p && p->Lchild ? p->Lchild->height : 0;
    int hr = p && p->Rchild ? p->Rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

Node *Tree::CreateTree(Node *p, int A)
{

    Node *t;
    if (p == NULL)
    {

        t = new Node;
        t->data = A;
        t->height = 1;
        t->Lchild = NULL;
        t->Rchild = NULL;
        if (root == NULL)
        {
            root = t;
        }
        return t;
    }

    if (A < p->data)
    {
        p->Lchild = CreateTree(p->Lchild, A);
    }
    else if (A > p->data)
    {
        p->Rchild = CreateTree(p->Rchild, A);
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
    Tree t;
    int A[] = {10, 20, 30, 25, 28, 27, 5, 19, 18};
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {

        t.CreateTree(t.GetRoot(), A[i]);
    }
    t.preorder(t.GetRoot());

    cout << endl;
    t.Delete(t.GetRoot(), 30);
    t.Delete(t.GetRoot(), 27);
    cout << "After Delete" << endl;

    t.preorder(t.GetRoot());
}