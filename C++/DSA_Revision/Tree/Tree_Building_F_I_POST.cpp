
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

    TreeNode* solve(vector<int>&ino,vector<int>&post,int i ,int l, int r)
    {
         if(i<0)return NULL;

        if(l>r)return NULL;


        int root = post[i];

        int part =l;
        while(part<=r && ino[part]!=root)
        {
            part++;
        }

        TreeNode*p= new TreeNode(root);

      
                
                    p->left = solve(ino ,post,i-(r-part)-1,l,part-1);

                    p->right = solve(ino,post,i-1,part+1,r);
              

        return p;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder,postorder,inorder.size()-1,0,inorder.size()-1);
    }
};


/*
Given two integer arrays inorder and postorder where   inorder
is the inorder traversal of a binary tree and postorder is the
postorder  traversal  of the same  tree, construct  and return 
the binary tree.
*/