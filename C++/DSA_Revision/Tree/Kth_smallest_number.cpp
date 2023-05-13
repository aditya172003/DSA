
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

    void solve(int &ans,TreeNode*p,int &k)
    {
        if(p==NULL)
        {
            return;
        }


        solve(ans,p->left,k);
        k--;
        if(k==0 && ans==-1)
        {
            ans=p->val;
            return;
        }
        solve(ans,p->right,k);

    }



    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int z =k;
        solve(ans,root,z);
        return ans;
    }
};
