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

    vector<TreeNode*>solve(int start ,int end)
    {       
        if (start>end)
        {
              vector<TreeNode*>ans;
              ans.push_back(NULL);
              return ans;
        }

        if(start==end)
        {
             vector<TreeNode*>ans;
              TreeNode*p=new TreeNode(start);
              ans.push_back(p);
              return ans;

        }
        vector<TreeNode*>ans;
        for(int i =start;i<=end;i++)
        {
        vector<TreeNode*>lpos  =  solve(start,i-1);
        vector<TreeNode*>rpos  =  solve(i+1,end);
        
        for(auto lp : lpos)
        {   
            
            for(auto rp: rpos)
            {
                TreeNode*root = new TreeNode(i);
                root->left = lp;
                root->right = rp;
                ans.push_back(root);
            }

            
        }

        }
      
         return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
       
       return solve(1,n);
    }
};