#include<bits/stdc++.h>
using namespace std ;


// littlebit treakey just remember the what is mean dp[i][j] tells

//https://leetcode.com/problems/distinct-subsequences/description/?envType=study-plan-v2&envId=dynamic-programming



class Solution {
public:

    int f(int i ,string ans,string s,string t,map<pair<int,string>,int>&dp)
    {
        if(ans==t)return 1;
      
        if(i>=s.length())
        {
            
            return (ans==t)?1:0;
        }
        pair<int,string> p = {i,ans};

      //  if(dp.find(p)!=dp.end())return dp[p];

        int exc = f(i+1,ans,s,t,dp);
       ans=ans+s[i];
        int inc = f(i+1,ans,s,t,dp);

        return dp[p]=exc+inc;
    }

    int numDistinct(string s, string t) {
       int n = s.length();
       int m = t.length();
       vector<vector<unsigned int>>dp(n+1,vector<unsigned int>(m+1,0));

        for(int i =0;i<n;i++)dp[i][0]=1;

        for(int i =1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }


        return dp[n][m];

    }
};