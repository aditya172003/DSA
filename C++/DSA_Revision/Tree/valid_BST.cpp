#include<bits/stdc++.h>

using namespace std;



// SEE THE CONDITION IN THE IF STATEMENT AT 1;
// REASON BEHIND THE USNG LONG IS NODE CONTAINING INT_MAX VALUE WILL ALSO A VALID STRING BUT 
// ANS GIVING WRONG THATS WHY ,,............

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

    bool solve(TreeNode*p,long min,long max)
    {
        if(p==NULL)return true;

        bool l = solve(p->left ,min,p->val);
        bool r = solve(p->right,p->val,max);

        bool ans=false;
        long d = p->val;
        if(d>min && d<max)ans=true; // ...............STATEMENT 1;

        return l&r&ans;

    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};