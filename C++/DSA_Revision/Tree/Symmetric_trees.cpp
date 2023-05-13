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
    bool isSymmetric(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);

        
        while(!q.empty())
        {
            vector<int>ans;
            int n =q.size();
            int j=n-1;
            int i =0;
            while(n--)
            {
                TreeNode*p=q.front();
                q.pop();

                if(p==NULL)
                {
                    ans.push_back(-111);
                }
                else
                {
                    ans.push_back(p->val);
                    q.push(p->left);
                    q.push(p->right);
                }
            }

            while(i<j)
            {
                if(ans[i]!=ans[j])return false;

                i++;
                j--;
            }
            
        }

        return true;


    }
};