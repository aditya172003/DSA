// stairs climbing 

#include<bits/stdc++.h>

using namespace std;


// recursive way 

int solve(int nstair,int i)
{
    if(i==nstair)
    {
        return 1;

    }
    if(i>nstair)
    {
        return 0;
    }

    return solve(nstair,i+1)+solve(nstair,i+2);
}

// cost problem
// min cost problem  using dp top down approach memorization

int solve(vector<int>&cost,int n,vector<int>&dp)
{
    if(n==0)
    {
        return cost[0];
    }
    if(n==1)
    {
        return cost[1];
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    int ans = cost[n]+min(solve(cost,n-1,dp),solve(cost , n-2,dp));
    dp[n]=ans;
    return ans;
}


// bottom up approach tabulation method 
int solve_tabulation(vector<int>cost)
{   int n = cost.size();
    vector<int>dp(n,0);

    dp[0]=cost[0];
    dp[1]=cost[1];

    for(int i =2 ;i<n;i++)
    {
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);

    }

    return dp[n];
}



// accepted answer 

class Solution {
public:

    int solve(vector<int>&cost,int n,vector<int>&dp)
   {
    if(n==0)
    {
        return cost[0];
    }
    if(n==1)
    {
        return cost[1];
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    int ans = cost[n]+min(solve(cost,n-1,dp),solve(cost , n-2,dp));
    dp[n]=ans;
    return ans;
    }


    
    int minCostClimbingStairs(vector<int>& cost) {
         int n = cost.size();
         vector<int>dp(n+1,-1);


         return min(solve(cost,n-1,dp),solve(cost,n-2,dp));

    }
};





int main()
{
     int n;
   vector<int>dp(n+1,-1);

}

