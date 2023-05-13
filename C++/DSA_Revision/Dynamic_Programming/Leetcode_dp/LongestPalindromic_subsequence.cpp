
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int longestPalindromeSubseq(string s) {
        string si = s;
        string sj = s;
        
        reverse(sj.begin(),sj.end());

        int n = s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==sj[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
        
    }
};

/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence  by 
deleting some or no elements without changing the order of the  remaining 
elements.
*/