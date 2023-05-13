


#include <bits/stdc++.h> 


using namespace std;



    int f(int i,int j,string s1,string s2,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)return 0;


        if(dp[i][j]!=-1)return dp[i][j];


        if(s1[i]==s2[j])
        {
            return dp[i][j]= 1+f(i-1,j-1,s1,s2,dp);
        }

        return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));

    }


int minInsertion(string &str)
{
    // Write your code here.

    string s = str;
    reverse(s.begin(),s.end());

    int n  = s.length();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return n-f(n-1,n-1,str,s,dp);
}

//https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1