#include<bits/stdc++.h>
using namespace std;


// unique binary search trees 

// catalan number 


class Solution {
public:

    int solve(vector<int>&dp,int n)
    {   
        if(n<=1)
        {
            return 1;

        }

        
        if(dp[n]!=-1)return dp[n];

        int ans=0;
        for(int j =1;j<=n;j++)
        {
            ans+=solve(dp,j-1)*solve(dp,n-j);
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);

        return solve(dp,n);
    }
};