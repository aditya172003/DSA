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
    TreeNode* insert(vector<int>&nums,int l,int h)
    {
       if(l>h)return NULL;

       int mid  = (l+h)/2;
       TreeNode* p  = new TreeNode(nums[mid]);

       p->left = insert(nums,l,mid-1);
       p->right= insert(nums,mid+1,h);

       return p; 
        

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        

        return insert(nums,0,nums.size()-1);
    }
};


/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
binary search tree.


*/