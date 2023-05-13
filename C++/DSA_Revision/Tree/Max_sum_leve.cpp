

#include<bits/stdc++.h>
using namespace std;


// BASIC TERMANOLOGY OF THE TREE
class Node
{
    public:
    int data;
    Node*left;
    Node*right;
    public:
    Node()
    {
        left  =NULL;
        right =NULL;
    }
    Node(int t)
    {
        data  = t;
        left  =NULL;
        right =NULL;
    }

    friend class Tree;

};

Node*root;



 int maxLevelSum(Node* root) {
        
        Node*p=root;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        vector<int>ans;
        int a= 0;
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
                a+=p->data;
                
                if(p->left ) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        
        return *max_element(ans.begin(),ans.end());
        // Your code here
    }


/*
Given a Binary Tree having positive and negative nodes. Find the maximum sum of a level in the given Binary Tree.

Input :               
             4
          /    \
         2     -5
        / \    / \
      -1   3  -2  6

Output: 6

Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 2'th level is 6
Hence maximum sum is 6

*/