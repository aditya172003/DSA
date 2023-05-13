













 
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
 
    pair<int,bool>isSum(Node*p)
    {
        if(p==NULL)
        {
            return {0,true};
        }

        pair<int,bool> x = isSum(p->left);
        pair<int,bool> y = isSum(p->right);

        pair<int,bool>ans;
        ans.first = p->data;

        if(p->data == x.first+y.first )
        {
            ans.second=true&&x.second&&y.second;
        }
        else
        {
            ans.second = false;

        }
        return ans;

    }

    bool isSumTree()
    {
        return isSum(root).second;
    }