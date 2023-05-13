#include<bits/stdc++.h>

using namespace std;

class Node
{  
    public: 
    int data;
    Node*left;
    Node*right,*root;


};


// I missed Where ,That the subTree Must be Binary Search tree



class Solution {
public:
    bool isBst(Node*p,int min,int max)
    {
        if(p==NULL) return true;
        
        bool l,r;
        l = isBst(p->left ,min,p->data);
        r = isBst(p->right,p->data,max);
        
        bool ans=true;
        
        if(p->data <=min || p->data>=max)
        {
            ans=false;
        }
        
        return l&r&ans;
    }
    pair<int,int>solve(Node*p,int target,vector<int>&fans)
    {
        if(p==NULL)
        {
            return {0,0};
        }
        
        
        pair<int,int>l,r,ans;
        
        l =solve(p->left,target,fans);
        r = solve(p->right,target,fans);
        
        if(l.second+r.second+p->data ==target && isBst(p,INT_MIN,INT_MAX))
        {
            int size = l.first+r.first+1;
            fans.push_back(size);
            
            return {0,0};
        }
        else
        {
            return {r.first+l.first+1,l.second+r.second+p->data};
        }
        
        
    }
    int minSubtreeSumBST(int target, Node *root) {
            vector<int>ans;
            
            solve(root,target,ans);
            
            if(ans.size()==0)
            {
                return -1;
            }
            
            return *min_element(ans.begin(),ans.end());
    }
};


/*
    Given a binary tree and a target, find the length of minimum sub-tree with 
    the given sum equal to target which is also a binary search tree.


    Input:
           13
         /    \
       5       23
      / \      / \
     N   17   N   N
         /
        16
Target: 38
Output: 3
Explanation: 5,17,16 is the smallest subtree
with length 3.



    Input:
             7
           /   \
          N    23
             /   \
            10    23
           /  \   / \
          N   17 N   N
Target: 73
Output: -1
Explanation: No subtree is bst for the given target.
*/


//https://practice.geeksforgeeks.org/problems/d064cc0468a5c2bb7817ecd7c1bc59ce25e23613/1