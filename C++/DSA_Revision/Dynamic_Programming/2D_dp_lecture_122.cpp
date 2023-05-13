#include<bits/stdc++.h>
using namespace std;


#define ll long long 



class Solution {
  public:
    ll solve(int i,int m,int n,int t,ll ans,vector<vector<ll>>&dp)
    {
        if(i>n)
        {
            if(ans==t)
            {
                return 1;
            }
            return 0;
        }
        if(ans>t)
        {
            return 0;
        }
        if(dp[i][ans]!=-1)
        {
            return dp[i][ans];
        }
        
        ll tot=0;
        for(int k=1;k<=m;k++)
        {
            tot+=solve(i+1,m,n,t,ans+k,dp);
        }
        
        return dp[i][ans]=tot;
    }
    long long noOfWays(int M , int N , int X) {
        vector<vector<ll>>dp(N+1    ,vector<ll>(X+1,-1));
       return solve(1,M,N,X,0,dp);
    }
};