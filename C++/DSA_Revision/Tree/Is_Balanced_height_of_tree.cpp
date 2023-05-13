



 
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
 
 
 





    // balanced height of the tree

    pair<int,bool>  bal_h(Node*p)

    {
        if(p==NULL){
            return {0,true};

        }

        pair<int,bool>p1,p2,ans;

        p1= bal_h(p->left);
        p2 = bal_h(p->right);

        ans.first = (p1.first>p2.first)?p1.first+1 : p2.first+1;

        if((abs(p1.first-p2.first)>1))
        {
            ans.second= false;
            return ans;
        }

        ans.second = p1.second&p2.second;
        return ans;

    }

    bool isBalanced_Height()
    {
        pair<int,bool>pr = bal_h(root);
        return pr.second;
    }