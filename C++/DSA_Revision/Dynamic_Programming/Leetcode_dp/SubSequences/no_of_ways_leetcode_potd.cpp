#include<bits/stdc++.h>

using namespace std;



// this is the hard question of the day on subsequence type dp problem 

// used memorization technique 

// it is 3D DP QUESTION  most nice question i solved on subsequence problems 

//https://leetcode.com/problems/profitable-schemes/description/





class Solution {
public:
    const long long int M = 1e9+7;
    int solve(int i,int p,int mp,int g,int mg, vector<int>& group, vector<int>& profit,
    vector<vector<vector<int>>>&dp,int &d)
    {
        if(i==group.size())
        {
            
            if(p>=mp && g<=mg)
            {
                
                return 1;
            }

            return 0;
        }

       
        if(dp[i][p][g]!=-1)return dp[i][p][g];

        int inc =0;
        int exc =0;


        if(g+group[i]<=mg)
        {
            inc = solve(i+1,p+profit[i],mp,g+group[i],mg,group,profit,dp,d);
        }

        exc = solve(i+1,p,mp,g,mg,group,profit,dp,d);

       
         

        return dp[i][p][g]=((inc)%M+(exc)%M)%M;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int sp=0;
        for(auto i :profit)
        {
            sp+=i;
        }

        vector<vector<vector<int>>>dp(group.size()+1,vector<vector<int>>(sp+1,vector<int>(n+1,-1)));
        int d=0;
        return solve(0,0,minProfit,0,n,group,profit,dp,d);
    }

};