#include<bits/stdc++.h>

using namespace std;

    
    int solve(int*a,int n,int i,int prev,vector<vector<int>>&dp )
    {
        if(i>=n)
        {
            
          
            
            return 0;
        }
        
        
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
            int take =0;
        if(prev==-1 || a[i]>a[prev])
        {
            
          take = 1+solve(a,n,i+1,i,dp);
        }
        
        int not_t = solve(a,n,i+1,prev,dp);
        dp[i][prev+1]=max(take,not_t);
        return dp[i][prev+1];
    }
    int longestSubsequence(int n, int a[])
    {
        
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(a,n,0,-1,dp);
        
        
        
    }