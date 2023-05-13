#include<bits/stdc++.h>
using namespace std;












class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool is(int k ,vector<int>adj[],vector<int>&p,vector<int>&v)
    {
         v[k]=1;
       
        bool ans=false;
        for(auto i :adj[k])
        {
            if(v[i] && p[k]!=i)
            {
                return true;
            }
            else
            {
                if(!v[i])
                {   
                    p[i]=k;
                    
                 if(is(i,adj,p,v))
                 {
                     return true;
                 }
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>v(V,0);
        vector<int>p(V,-1);
          
           for(int i=0;i<   V;i++)
           {
               if(!v[i])
               {
                   if(is(i,adj,p,v))
                   {
                       return true;
                   }
                   
               }
           }
        return false;
        
    }
};


