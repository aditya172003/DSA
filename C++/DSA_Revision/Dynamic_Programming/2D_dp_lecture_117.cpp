
#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int solve(vector<int>&obstackle , int currentlen , int currPos,vector<vector<int>>&dp)
    {   
        int n = obstackle.size()-1;

        if(currPos ==n)
        {
            return 0;

        }
        if(dp[currentlen][currPos]!=-1)
        {
            return dp[currentlen][currPos];
        }
        if(obstackle[currPos+1]!=currentlen)
        {
            return dp[currentlen][currPos]= solve(obstackle,currentlen,currPos+1,dp);
        }
        int ans = INT_MAX;
        for(int i =1;i<=3;i++)
        {
            if(i!=currentlen && obstackle[currPos]!=i)
            {
                ans =  min(ans,1+solve(obstackle,i,currPos+1,dp));

                
            }

        }
        
        return dp[currentlen][currPos]=ans;
    

    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>>dp(4,vector<int>(n,-1));

        return solve(obstacles,2,0,dp);
    }
};