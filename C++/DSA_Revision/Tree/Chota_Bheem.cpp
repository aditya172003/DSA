#include<bits/stdc++.h>

using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};


// nice question with different logic 






class Solution{

    public:
    
  
        
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        
        if(root==NULL)return 0;
      Node*hm=NULL;
       unordered_map<Node*,Node*>parent;
        
        unordered_map<Node*,int>visited;
        queue<Node*>q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty())
        {
            Node*p=q.front();
            q.pop();
            
            if(p->data==home)hm=p;
            visited[p]=0;
            if(p->left)
            {
                parent[p->left]=p;
                q.push(p->left);
            }
            
            if(p->right)
            {
                parent[p->right]=p;
                q.push(p->right);
            }
        }
        
        q.push(hm);
        int ans=0;
        int l=0;
        while(!q.empty()&& l<=k)
        {
          int s = q.size();
          while(s )
          {
             Node*p=q.front();
             q.pop();
             ans+=p->data;
             visited[p]=1;
             
             if(!visited[parent[p]]&&parent[p])
             {
                 q.push(parent[p]);
             }
             if(!visited[p->left]&&p->left)
             {
                 q.push(p->left);
             }
             if(!visited[p->right]&&p->right)
             {
                 q.push(p->right);
             }
              
            s--;
          }
          l++;
            
        }
        
        return ans;
    }
};

//https://practice.geeksforgeeks.org/problems/9b61b8efbb030aed799055f776629dbf1287fbae/1