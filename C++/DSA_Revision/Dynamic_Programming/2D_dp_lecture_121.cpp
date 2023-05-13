#include<bits/stdc++.h>

using namespace std;

// common mistake of using same dp in both the cases 

// include exclude principal 

class Solution {
public:


    int solve(int i ,int end_index,vector<int>&slice,int n,int flag,vector<vector<int>>&dp)
    {
        if( n==0 || i>end_index)
        {
            return 0;
        }
       
       
        if(dp[i][n]!=-1)
        {
            return dp[i][n];
        }


        int inc  = slice[i]+solve(i+2,end_index,slice,n-1,flag,dp);
    

        int n1    = solve(i+1,end_index,slice,n,flag,dp);
        

        return dp[i][n] =max(inc,n1);



    }

    int maxSizeSlices(vector<int>& slices) {

        
        int k =slices.size();
        vector<vector<int>>dp1(k+1 ,vector<int>(k/3 +1, -1));
        vector<vector<int>>dp(k+1 ,vector<int>(k/3 +1, -1));
        int a1 = solve(0,k-2,slices,k/3,1,dp1);
        int a2 = solve(1,k-1,slices,k/3,0,dp);

        return max(a1,a2);
    }
};