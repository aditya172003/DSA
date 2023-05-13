#include<bits/stdc++.h>
using namespace std;






class Solution {
  public:
  
    void dfs(int i ,int j,vector<vector<int>>&g,vector<vector<int>>&v)
    {
       
        v[i][j]=1;
        
        int x[4]= {-1,0,1,0};
        int y[4]={0,-1,0,1};
        
        for(int k=0;k<4;k++)
        {
            int nx = i+x[k];
            int ny = j+y[k];
            
            if(!(nx<0 || nx>=g.size() || ny<0 || ny>=g[0].size())&&!v[nx][ny] && g[nx][ny])
            {
                dfs(nx,ny,g,v);
            }
        }
        
    
        
        
    }
  
  
  
    int numberOfEnclaves(vector<vector<int>> &g) {
        // Code here
        vector<vector<int>>v(g.size(),vector<int>(g[0].size(),0));
        for(int i =0;i<g.size();i++)
        {
            if(!v[i][0]&&g[i][0]!=0)
            {
                dfs(i,0,g,v);
            }
            
            if(!v[i][g[0].size()-1] && g[i][g[0].size()-1]!=0)
            {
                dfs(i,g[0].size()-1,g,v);
            }
        }
        
        
        for(int j=0;j<g[0].size();j++)
        {
            if(!v[0][j] && g[0][j]!=0)
            {
                dfs(0,j,g,v);
            }
            
            if(!v[g.size()-1][j] && g[g.size()-1][j]!=0)
            {
                dfs(g.size()-1,j,g,v);
            }
        }
        
            
            int ans=0;
            
            for(int i =1;i<g.size()-1;i++)
            {
                for(int j=1;j<g[0].size()-1;j++)
                {
                    if(!v[i][j] && g[i][j]==1)
                    {
                        ans++;
                    }
                }
                
            }
            
            return ans;
        
    }
};
