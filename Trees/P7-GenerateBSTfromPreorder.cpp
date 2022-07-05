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

class Tree
{
private:
    Node *root;

public:
    Tree() { root = NULL; }
    void generateFromPreoder(int A[], int n);
    void preorder();
};

void Tree::generateFromPreoder(int A[], int n)
{
    Node *p, *t;
    stack<Node *> st;
    int i = 0;
    root = new Node;
    root->data = A[i++];
    root->Lchild = root->Rchild = NULL;
    p = root;
    while (i < n)
    {
        if (A[i] < p->data)
        {
            t = new Node;
            t->data = A[i++];
            t->Lchild = t->Rchild = NULL;
            p->Lchild = t;
            st.emplace(p);
            p = t;
        }
        else
        {
            if (A[i] > p->data && A[i] < st.empty() ? 32767 : st.top()->data)
            {
                t = new Node;
                t->data = A[i++];
                t->Lchild = t->Rchild = NULL;
                p->Rchild = t;
                st.emplace(p);
                p = t;
            }
            else
            {
                p = st.top();
                st.pop();
            }
        }
    }
}

void Tree::preorder()
{
    Node *p = root;
    stack<Node *> st;
    while (p != NULL || !st.empty())
    {
        if (p)
        {
            cout << p->data << " ";
            st.emplace(p);
            p = p->Lchild;
        }
        else
        {
            p = st.top();
            st.pop();
            p = p->Rchild;
        }
    }
}

int main()
{
    Tree t;
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre) / sizeof(pre[0]);
    t.generateFromPreoder(pre, n);
    t.preorder();
}