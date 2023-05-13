
#include<bits/stdc++.h>

using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



class Solution{
public:

    pair<int,Node*> pos(int t,Node*p)
    {
        if(p==NULL)
        {
            return {0,NULL};
        }
        if(p->data == t)
        {
            return {0,p};
            
        }
        
        
        
        pair<int,Node*>l,r;
        
        
        if(p->data <t)
        {
            r=pos(t,p->right);
            r.first +=1;
            return r;
        }
        else
        {
            l=pos(t,p->left);
            
            l.first -=1;
            return l;
        }
    
    }
    
    int sum(Node*p,int d,int act)
    {
        if(p==NULL)
        {
            return 0;
        }
        
        
        int l = sum(p->left,d-1,act);
        int r = sum(p->right,d+1,act);
        
        
        if(act ==d)
        {
            return (l+r+p->data);
        }
        return (l+r);
    }
    
    
    
    long long int verticallyDownBST(Node *root,int target){
       pair<int,Node*>p = pos(target,root);
       
       if(p.second==NULL)return -1;
       
       int ans = sum(p.second,p.first,p.first);
       
       ans-=p.second->data;
       
       return ans;
    }
};








/*
Given a Binary Search Tree with unique node values and a target value. 
You have to find the node whose data is equal to target and return the 
sum of all descendant (of target) node's data which are vertically below
the target node. Initially, you are at the root node.
Note: If target node is not present in bst then return -1.
*/