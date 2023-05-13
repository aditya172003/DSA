
#include<bits/stdc++.h>

using namespace std;



// here passing refernece to the pointer is most important 




 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class Solution {
public:

    bool solve(TreeNode*&ans,TreeNode*p,int a,int b)
    {
        if(p==NULL)return false;


        bool l =solve(ans,p->left,a,b);

        bool r=solve(ans,p->right,a,b);

        if(l&r)
        {
            ans=p;
            return false;
        }

        if(p->val == a || p->val==b)
        {
            if(l | r)
            {
                ans  =p;
                return false;
            }

            return true;
        }

        return l|r;
       
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode*ans;

            bool a = solve(ans,root,p->val,q->val);

            return ans;
    }
};








/*



Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p
and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant
of itself).”



*/