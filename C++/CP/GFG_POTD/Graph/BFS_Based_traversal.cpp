#include<bits/stdc++.h>

using namespace std;

class Solution{   
public:
  
    int minIteration(int n, int m, int x, int y){   
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[x][y]=1;
        
        queue<pair<int,int>>q;
        q.push({x,y});
        int c =0;
        while(!q.empty())
        {
             int s = q.size();
            for(int i1 =0;i1<s;i1++)
            {
                 pair<int,int>p =q.front();
           
            q.pop();
            
            int i = p.first;
            int j =p.second;
            
            if(j>1 && dp[i][j-1]==0)
            {
                dp[i][j-1]=1;
                q.push({i,j-1});
             
            }
            
            if(j<m && dp[i][j+1]==0)
            
            {  
                dp[i][j+1]=1;
                q.push({i,j+1});
                
            }
            
            if(i>1 && dp[i-1][j]==0)
            {
                dp[i-1][j]=1;
                q.push({i-1,j});
                 
            }
            
            if(i<n && dp[i+1][j]==0)
            
            {
                dp[i+1][j]=1;
                q.push({i+1,j});
               
                
            }
            }
           
            
            if(!q.empty()) c++;
            
        }
        return c;
    }
};