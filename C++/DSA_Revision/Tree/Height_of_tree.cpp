
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





int height_T(Node*p)
    {
        if(p==NULL) return 0;
        
        int x = height_T(p->left);
        int y = height_T(p->right);

        return (x>y)?x+1: y+1;
    }

    int Height_of_tree()
    {
        return height_T(root);
    }