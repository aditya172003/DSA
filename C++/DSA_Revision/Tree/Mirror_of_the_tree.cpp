#include<bits/stdc++.h>
using namespace std;


// BASIC TERMANOLOGY OF THE TREE
class Node
{
    public:
    int data;
    Node*left;
    Node*right;
    public:
    Node()
    {
        left  =NULL;
        right =NULL;
    }
    Node(int t)
    {
        data  = t;
        left  =NULL;
        right =NULL;
    }

    friend class Tree;

};

Node*root;
    Node*Swap(Node*p)
    {
        if(p==NULL)
        {
            return NULL;
        }
        Node*temp = p->left;
        p->left = Swap(p->right);
        p->right= Swap(temp);
        return p;
    }


    void Mirror()
    {
        root= Swap(root);
    }