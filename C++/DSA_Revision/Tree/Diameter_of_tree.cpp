 
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
 
 
 
 
 pair<int,int>Di(Node*p)
    {
        if(p==NULL)
        {
            return {0,0};
        }

         pair<int,int>p1,p2;

         p1 = Di(p->left);
         p2 = Di(p->right);

         pair<int,int>ans;
        
        ans.first  =(p1.first>p2.first )? p1.first+1:p2.first+1;

        ans.second =max((p1.first+p2.first+1),max(p1.second,p2.second));

        return ans;
    }


    int Diameter()
    {
        pair<int,int >ans = Di(root);
        return ans.second;
    }

///--=-=-=-=---=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-====-=-=-=-=-=-=-=-=-=-=-=-=-=-=-




int height(struct Node*p)
{
    if(p==NULL)
    {
        return 0;
    }
    
    int x=height(p->left);
    int y=height(p->right);
    
    if(x>y)
    {
        return x+1;
    }
    else
    {
        return y+1;
    }
}

int left_height(struct Node*p)
{
    if(p==NULL)
    {
        return 0;
    }
    
    int x=height(p->left)+  height(p->right)+1;

    int z=left_height(p->left);
    
    
    
    return (x>z)?x:z;
}

int right_height(struct Node*p)
{
    if(p==NULL)
    {
        return 0;
    }
    
    int x=height(p->left)+  height(p->right)+1;

    int z=right_height(p->right);
    
    
    
    return (x>z)?x:z;
}
