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
 




 bool check(TreeNode*p,TreeNode*q)
 {
        if(p->val <= q->val)return true;
        return false;
 }
class Solution {
public:
    void solve(TreeNode*p,vector<TreeNode*>&ans)
    {
        if(p==NULL)return;

        solve(p->left , ans);
        ans.push_back(p);
        solve(p->right,ans);

        
    }

   

    void recoverTree(TreeNode* root) {
        
        vector<TreeNode*>ans;

        solve(root,ans);

        vector<int>p;
        for(auto i :ans)
        {
            p.push_back(i->val);
        }
        sort(p.begin(),p.end());
        for(int i =0;i<p.size();i++)
        {
          // cout<<ans[i]->val<<" "<<p[i]->val<<endl;
            ans[i]->val = p[i];
          // cout<<ans[i]->val<<" "<<p[i]->val<<endl;
        }

        

    }
};

/*
    You are given the root of a binary search tree (BST), 
    where the values of exactly two nodes of the tree were 
    swapped by mistake. Recover the tree without changing its structure.
    

    HERE EXACTLY TWO ARE MISSING THIS IS IMPORTANT

*/