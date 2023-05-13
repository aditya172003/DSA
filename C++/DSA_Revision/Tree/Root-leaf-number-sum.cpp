

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
    void solve(int counter , vector<int>ans,vector<int>&fans,TreeNode*p)
    {
        if(p==NULL)
        {

            return;
        }
           
        if(p->left==NULL && p->right==NULL)
        {
            ans.push_back(p->val);
             int num=0;

            int n = ans.size();

            int d = pow(10,n-1);

            for(int i =0;i<n;i++)
            {
                num+=ans[i]*d;
                d/=10;
            }

            
            fans.push_back(num);
            return;
            
        }
           
        

        
        ans.push_back(p->val);

        solve(counter+1,ans,fans,p->left);

        solve(counter+1,ans,fans,p->right);

    }
    int sumNumbers(TreeNode* root) {
        vector<int>ans,fans;
        solve(0,ans,fans,root);

        int ff = 0;
        for(auto i:fans)
        {
            ff+=i;
            cout<<i<<" ";
        }
        return ff;
    }
};