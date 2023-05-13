
#include <bits/stdc++.h> 

using namespace std;



int solve(int i ,vector<int>&nums,vector<int>&dp)
{
    if(i>=nums.size())
    {
        return 0;
    }

    if(dp[i]!=-1)return dp[i];


    int inc = nums[i]+solve(i+2,nums,dp);
    int exc =solve(i+1,nums,dp);

    return dp[i]=max(inc,exc);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here
    int n =nums.size();
    vector<int>dp(n+1,-1);

    return solve(0,nums,dp);
}



// using tabulation


int tab(vector<int>nums)
{
    vector<int>dp(nums.size()+1,0);
    dp[0]=nums[0];
    dp[1]=max(dp[0],nums[1]);

    for(int i =2;i<nums.size();i++)
    {
        dp[i]= max(dp[i-1],nums[i]+dp[i-2]);
    }
    return dp[nums.size()-1];
}

// space optimization

int spaceOpt(vector<int>nums)
{
    vector<int>dp(nums.size()+1,0);
   int a =nums[0];
   int b =max(nums[1],a);
    int ans=max(a,b);
    for(int i =2;i<nums.size();i++)
    {
        ans = max(b,nums[i]+a);
        a=b;
        b=ans;
    }
    return ans;
}