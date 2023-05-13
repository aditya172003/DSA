#include<bits/stdc++.h>

using namespace std;






//https://leetcode.com/problems/house-robber-iii/submissions/921504018/

//  Definition for a binary tree node.
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

    int d(TreeNode*root,map<TreeNode*,int>&mp)
    {   if(root==NULL)return 0;


        if(mp.find(root)!=mp.end())
        {
            return mp[root];
        }
        // int exc =0;
        // if(root->left)
        // {
        //     exc+=d(root->left,false,mp);
        // }

        // if(root->right)
        // {
        //     exc+=d(root->right,false,mp);
        // }
        // int inc=INT_MIN;
        // if(!take)
        // { 
        //     inc=root->val;
        //     inc+=d(root->left,true,mp)+d(root->right,true,mp);
        // }

         
        //exclude 
        int exc = d(root->left,mp)+d(root->right,mp);


        int inc=root->val;

        if(root->left)
        {
            inc+=d(root->left->left,mp)+d(root->left->right,mp);

        }
        if(root->right)
        {
            inc+=d(root->right->left,mp)+d(root->right->right,mp);
        }


        return mp[root] = max(inc,exc);
    }
    int rob(TreeNode* root) {
        if(root==NULL)return 0;
        map<TreeNode*,int>mp1;
        
        // exclude 
        // int exc = rob(root->left)+rob(root->right);


        // int inc=root->val;

        // if(root->left)
        // {
        //     inc+=rob(root->left->left)+rob(root->left->right);

        // }
        // if(root->right)
        // {
        //     inc+=rob(root->right->left)+rob(root->right->right);
        // }

        
        return d(root,mp1);

        // return max(inc,exc);

    }
};