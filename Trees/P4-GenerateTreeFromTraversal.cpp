#include <iostream>
using namespace std;

class Node
{
public:
    Node *Lchild;
    int data;
    Node *Rchild;
    Node(){};
    Node(int data)
    {
        this->data = data;
        Lchild = NULL;
        Rchild = NULL;
    }
};

void Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->Lchild);
        cout << p->data << " ";
        Inorder(p->Rchild);
    }
}

int search(int inorder[], int start, int end, int ele)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == ele)
            return i;
    }
    return -1;
}

Node *generateTreeFromTraversal(int preorder[], int inorder[], int start, int end)
{
    static int preindex = 0;

    if (start > end)
        return NULL;
    int curr = preorder[preindex++];

    Node *newnode = new Node(curr);

    if (start == end)
        return newnode;

    int pos = search(inorder, start, end, newnode->data);
    newnode->Lchild = generateTreeFromTraversal(preorder, inorder, start, pos - 1);
    newnode->Rchild = generateTreeFromTraversal(preorder, inorder, pos + 1, end);

    return newnode;
}

int main()
{

    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    Node *root = generateTreeFromTraversal(preorder, inorder, 0, sizeof(inorder) / sizeof(inorder[0]) - 1);
    Inorder(root);
}