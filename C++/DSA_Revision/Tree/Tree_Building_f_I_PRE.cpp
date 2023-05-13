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

    TreeNode*solve(int i ,vector<int>&pre,vector<int>&ino,int n,int l,int r)
    {
        if(i>=n)return NULL;

        if(l>r)return NULL;


        int root = pre[i];

        int part =l;
        while(part<=r && ino[part]!=root)
        {
            part++;
        }

        TreeNode*p= new TreeNode(root);
      
                    p->left = solve(i+1,pre,ino,n,l,part-1);
 
                
                    p->right = solve(i+(part-l+1),pre,ino,n,part+1,r);
          

        return p;
    }




    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(0,preorder,inorder,preorder.size(),0,preorder.size());
    } 



}; 

/*

 Given two integer arrays preorder and inorder where preorder
 is the preorder traversal of a binary tree and inorder is the 
 inorder traversal of the same tree, construct and return the binary tree.

*/