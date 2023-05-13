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
 

 #define ll long long 
 class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        ll mxw = 1;
        queue<pair<TreeNode*,ll>> q;
        q.push({root,1});

        while (!q.empty()) {
        ll s = q.size();
        pair<TreeNode*,ll> pr1 = q.front();
        pair<TreeNode*,ll> pr2 = q.back();

            mxw = max(mxw,pr2.second-pr1.second+1);

            for(int i =0;i<s;i++)
            {
                pair<TreeNode*,int> p = q.front();
                q.pop();

                int ind = p.second;

                if(p.first->left)
                {
                    q.push({p.first->left,2ll*ind});
                }
                if(p.first->right)
                {
                    q.push({p.first->right,2ll*ind+1});
                }
            }
        }
        
        return mxw;
    }
};
//https://leetcode.com/problems/maximum-width-of-binary-tree/submissions/937096638/

