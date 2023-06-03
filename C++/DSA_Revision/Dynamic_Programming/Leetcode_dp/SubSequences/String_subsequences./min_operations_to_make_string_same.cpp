#include<bits/stdc++.h>
using namespace std ;





class Solution {
public:

    int f(int i ,int j,string w1, string w2 )
    {
        if(i>=w1.length() || j>= w2.length())
        {
            int a = w1.length();
            int b = w2.length();
            return abs(a-b);
        }


        if(w1[i]==w2[j])
        {
            return f(i+1,j+1,w1,w2);
        }
        else
        {

                int ans =INT_MAX;

                ans = 1+min(ans,min(f(i+1,j,w1,w2),f(i,j+1,w1,w2)));

                ans = 1+min(ans,f(i+1,j+1,w1,w2));
            return ans;
        }
    }

    int minDistance(string w1, string w2) {
        int n = w1.length();
        int m =w2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        return f(0,0,w1,w2);

        for(int i =1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(w1[i-1]==w2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
                    dp[i][j] = min(dp[i][j],min(dp[i+1][j],dp[i][j+1]));
                }
            }
        }


        return max(m,n)-dp[n][m];


    }
};