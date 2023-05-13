#include<bits/stdc++.h>
using namespace std;


/*
Given an undirected graph with V vertices(numbered from 1 to V) and E edges. Find the number of 
good components in the graph.
A component of the graph is good if and only if the component is a fully connected component.
Note: A fully connected component is a subgraph of a given graph such that there's an edge 
between every pair of vertices 
in a component, the given graph can be a disconnected graph. Consider the adjacency list from index 1.


1---2---7  

6 

   3
 /   \
4-----5


Output: 2
Explanation: We can see that there are 3 components
in the graph. For 1-2-7 there is no edge between
1 to 7, so it is not a fully connected component.
Rest 2 are individually fully connected component.

*/


// logic is that find total edges and vertices using DFS and 
//  if(edg == (ver *(vec-1))) is good else bad




class Solution {
  public:
  void dfs(int V, vector<vector<int>>& adj,int i,int &edg,int &ver,vector<int>&visited)
  {
      if(i>V)
      {
          return;
      }
      edg +=adj[i].size();
      visited[i]=1;
      ver++;
      for(auto j : adj[i])
      {
          if(!visited[j])
          {   
              dfs(V,adj,j,edg,ver,visited);
          }
          
      }
  }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        vector<int>visited(V+1,0);
        int ans=0;
        for(int i = 1 ;i<=V;i++ )
        {
            int edg=0;
            int ver=0;
            if(!visited[i])
                dfs(V,adj,i,edg,ver,visited);
                
            if(ver!=0 && edg == (ver *(ver-1)))
                ans++;
        }
        
        return ans;
        
    }
};
