#include<bits/stdc++.h>
using namespace std ;



    vector<int>a;
    
    
    void dfs(int node ,vector<int>&visited,vector<int> adj[])
    {
        visited[node]=1;
        a.push_back(node);
        for(auto k: adj[node])
        {
            if(!visited[k])
            {
                dfs(k,visited,adj);
                
            }
        }
        
    } 




     // this dfs s for matrix traversal 
     
    void DFS(int i,int j ,vector<vector<int>>&visited,vector<vector<char>>&adj)
    {
        visited[i][j]=1;
        int n = adj.size();
        int x[8] = {1,0,-1,0,1,1,-1,-1};
        int y[8] = {0,1,0,-1,1,-1,-1,1};
        
        for(int k=0;k<8;k++)
        {
            int nx  = x[k]+i;
            int ny  = y[k]+j;
            
            
            if(nx>=0 && ny>=0 && nx<n && ny<adj[0].size() && !visited[nx][ny] && adj[nx][ny]=='1')
            {
                DFS(nx,ny,visited,adj);
            }
        }
    } 