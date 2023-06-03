#include<bits/stdc++.h>
using namespace std ;



//https://leetcode.com/problems/edit-distance/description/?envType=study-plan-v2&envId=dynamic-programming


// the base case is much important 
/*
    as this is hard level dp question but follows basic rule 

    1 ] think about base case 
    2 ] explore all the possibilities 
    3 ] store the requ ans and return it 

    follow this memorization approach to solve any dp question 
    still you got tle then think about tabulation
*/


class Solution {
public:

    int f(int i ,int j,string w1, string w2,vector<vector<int>>&dp )
    {
        if(i>=w1.length() || j>= w2.length())
        {
            int ans =0;
            while(i<w1.length())
            {
                ans++;
                i++;
            }
            while(j<w2.length())
            {
                ans++;
                j++;
            }
            return ans;

        }
        if(dp[i][j]!=-1)return dp[i][j];



        if(w1[i]==w2[j])
        {
            return dp[i][j]=  0+f(i+1,j+1,w1,w2,dp);
        }
        else
        {

                int ans =INT_MAX;
                int a =f(i+1,j+1,w1,w2,dp);
                int b =f(i+1,j,w1,w2,dp);
                int c =f(i,j+1,w1,w2,dp);

              ans = 1+min(a,min(b,c));

                
            return dp[i][j]=ans;
        }
    }

    int minDistance(string w1, string w2) {
        int n = w1.length();
        int m =w2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return f(0,0,w1,w2,dp);

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