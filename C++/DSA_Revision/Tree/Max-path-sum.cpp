
#include<bits/stdc++.h>
using namespace std;



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 




class Solution {
public:
  pair<int,int> mxp(TreeNode*root)
    {   
         if(root==NULL)
        {
            return {0,INT_MIN};


        }

        pair<int,int>l,r,p;
        
        l = mxp(root->left);

        r = mxp(root->right);

        int lmax = l.second;

        int rmax = r.second;

        int current = l.first+r.first +root->val;

        p.first  = max(max(l.first,r.first)+root->val,root->val);

        int an2  = max(root->val,current);

        p.second = max(max(lmax,rmax),max(p.first,an2)); 
        

        
        return p;

    }

    int maxPathSum(TreeNode* root) {
       
        pair<int,int>p= mxp(root);

        return max(p.first,p.second);


    }
};



/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the 
sequence has an edge connecting them. A node can only appear in the sequence at    most 
once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.



Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
*/