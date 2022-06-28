#include <iostream>
#include <queue>
#include <stack>
#include <cstdint>
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
    void IPostOrder();
    Node *getRoot() { return root; }
};

void Iterative::IPostOrder()
{
    Node *p = root;
    stack<intptr_t> st;
    intptr_t temp;
    while (p != NULL || !st.empty())
    {
        if (p != NULL)
        {
            st.emplace((intptr_t)p);
            p = p->Lchild;
        }
        else
        {
            temp = st.top();
            st.pop();
            if (temp > 0)
            {
                st.emplace(-temp);
                p = ((Node *)temp)->Rchild;
            }
            else
            {
                cout << ((Node *)(-1 * temp))->data << " ";
                p = NULL;
            }
        }
    }
}

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
    cout << endl;
    it.IPostOrder();
}