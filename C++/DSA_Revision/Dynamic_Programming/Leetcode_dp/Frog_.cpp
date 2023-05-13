#include <bits/stdc++.h> 

using namespace std;






    long long solve(int i ,vector<int>&h,vector<int>&dp)
    {
        if(i==0)
        {
           return 0;
        }
        if(dp[i]!=-1)return dp[i];


        long long  an1,an2=INT_MAX;
        an1 = solve(i-1,h,dp)+abs(h[i]-h[i-1]);
        if(i>1)
        {
            an2 = solve(i-2,h,dp)+abs(h[i]-h[i-2]);
        }
        

        return dp[i]=min(an2,an1);


    }
int frogJump(int n, vector<int> &heights)
{   
    vector<int>dp(n,-1);
    return solve(n-1,heights,dp);
}