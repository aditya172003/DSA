#include<bits/stdc++.h>


using namespace std;


/*

Given a binary tree, connect the nodes that are at the same level.
 The structure of the tree Node contains an addition nextRight pointer for this purpose.

Initially, all the nextRight pointers point to garbage values. 
Your function should set these pointers to point next right for each node.

       10                          10 ------> NULL
      / \                       /      \
     3   5       =>            3 ------> 5 --------> NULL
    / \   \                   /  \        \
   4   1   2                 4 --> 1 -----> 2 -------> NULL

*/

// logic of level order traversal in bst using queue BFS  in graph 

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};



class Solution{
    public:
    void connect(Node *root)
    {
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
           int s = q.size();
           
           Node*p,*qq = NULL;
          
           while(s>0)
           {
             qq=p;
             p=q.front();
             q.pop();
             
             if(p && p->left)
             {
                 q.push(p->left);
                 
             }
             
             if(p && p->right)
             {
                 q.push(p->right);
             }
             if(qq)
             {
                 qq->nextRight = p;
             }
             
             s--;
             
           }
           
           if(q.size()>0)
           {
               q.push(NULL);
           }
         
           
           
            
          
            
        }
        
        
       // Code Here
    }    
};
