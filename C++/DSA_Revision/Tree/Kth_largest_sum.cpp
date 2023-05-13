#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/submissions/911020337/


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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        TreeNode* p=root;
        queue<TreeNode*>q;
        q.push(p);
        q.push(NULL);
        vector<long long >ans;
        long long a=0;

        while(!q.empty())
        {
            p=q.front();
            q.pop();
            if(p==NULL)
            {
                ans.push_back(a);
                a=0;
                if(!q.empty())
                {
                    q.push(NULL);
                    
                }
            }
            else
            {
                a+=p->val;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }

        }

        sort(ans.begin(),ans.end());

        if(ans.size()<k)
        {
            return -1;
        }
        else
        {
            return ans[ ans.size()-k];
        }
        
    }
};

