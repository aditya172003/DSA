
#include<bits/stdc++.h>
using namespace std ;


//  https://leetcode.com/contest/biweekly-contest-105/problems/extra-characters-in-a-string/


class Solution {
public:
    int minExtraChar(string s, vector<string>& d) {
        vector<int>dp(s.length()+1,s.length());
        dp[0]=0;
      
        
        for(int i =0;i<s.length();i++)
        {
            for(auto t :d)
            {
                if(s.substr(i,t.size())==t)
                {
                    dp[i+t.size()]= min(dp[i],dp[i+t.size()]);
                }
        
            }
            dp[i+1]= min(dp[i]+1,dp[i+1]);
            
        }
        
        return dp.back();
        
//         for(auto i :dp)cout<<i<<" ";
//         cout<<endl;
        
//         return dp[s.length()];
    }
};




