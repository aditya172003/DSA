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

    TreeNode*solve(TreeNode*p)
    {
        if(p==NULL)return NULL;

        if(p->left==NULL && p->right==NULL)
        {
            return p;
        }

        TreeNode*q=solve(p->left);
        
        TreeNode*r=solve(p->right);
        
        if(q)
        {
            p->right =q;
            while(q->right)q=q->right;
            q->right = r;
            
            p->left =NULL;
        }


        return p;
      
        
    }
    void flatten(TreeNode* root) {
        root= solve(root);
    }
};



/*
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points
to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/