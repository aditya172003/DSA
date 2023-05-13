#include<bits/stdc++.h>

using namespace std;

const int M=1e9+7;
class Solution{   
public:
    

    int solve(int n,int i,vector<vector<int>>&dp)
    {
        if(n==0 && i ==0)
        {
            return 1;
        }
        
        if(n==0 && i>0)
        {
            return 0;
        }
        if(dp[i][n]!=-1) return dp[i][n];
        int ans =0;
        if(i ==0)
        {
             ans =(solve(n-1,1,dp)%M+solve(n-1,2,dp)%M+solve(n-1,3,dp)%M)%M;
        }
        if(i==1)ans =(solve(n-1,0,dp)%M+solve(n-1,2,dp)%M+solve(n-1,3,dp)%M)%M;
        if(i==2)ans =(solve(n-1,1,dp)%M+solve(n-1,0,dp)%M+solve(n-1,3,dp)%M)%M;
        if(i==3)ans =(solve(n-1,1,dp)%M+solve(n-1,2,dp)%M+solve(n-1,0,dp)%M)%M;
               
        return dp[i][n]=ans%M;
        
        
    }

    // solved usnig tabulation 
    int solve_TAB(int N)
    
    {   vector<vector<int>>dp(5,vector<int>(N+1,0));
        dp[0][0]=1;
    
        for(int i =1 ;i<=N;i++)
        {
            for(int j=0;j<4;j++)
            {
                dp[j][i]= (dp[j][i]%M+ dp[(1+j)%4][i-1]%M)%M;
                dp[j][i]= (dp[j][i]%M+ dp[(2+j)%4][i-1]%M)%M;
                dp[j][i]= (dp[j][i]%M+ dp[(3+j)%4][i-1]%M)%M;
            }
        }
        
        return dp[0][N];
        
        
    }
    
    
    int countPaths(int N){
       
        return solve_TAB(N);
    }
};