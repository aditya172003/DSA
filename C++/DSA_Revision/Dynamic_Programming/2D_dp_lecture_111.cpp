#include <bits/stdc++.h> 

using namespace std;
// target sum

int solve(vector<int>&num,int t, vector<int>&dp )
{
    if(t<0)
    {
        return 0;
    }
    if(t==0)
    {
        return 1;
    }
    
     
    if(dp[t]!=-1)
    {
        return dp[t];
    }

    int ans  = 0;
    for(int j =0 ;j<num.size(); j ++)
    {
           ans = ans+solve(num,t-num[j],dp);
    }
    dp[t]=ans;
    return dp[t];


    
}

int findWays(vector<int> &num, int tar)
{
   vector<int>dp(tar+1,-1);

   return  solve(num,tar,dp);
}