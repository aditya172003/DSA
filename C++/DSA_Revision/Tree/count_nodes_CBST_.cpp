

#include<bits/stdc++.h>

using namespace std;

/*
    counting nodes in Complete bst in timecomplexity less than O(n)
*/








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
    int countNodes(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL)return 0;

        q.push(root);
        int c=0;

        while(!q.empty())
        {
            TreeNode*p=q.front();
            q.pop();
            c++;
            if(p->left==NULL)
            {
                    return c*2-1;
            }

            if(p->right==NULL)
            {
                return 2*c;
            }

            if(p->left==NULL && p->right==NULL)
            {
                return 2*(c-1)+1;
            }

            q.push(p->left);
            q.push(p->right);
        }

        return c;
        
    }
};