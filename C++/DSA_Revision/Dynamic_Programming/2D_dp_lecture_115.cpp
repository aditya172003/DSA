#include<bits/stdc++.h>

using namespace std;
// matrix max square 
class Solution{
public:
    int solve(int n, int m, vector<vector<int>> mat,int i,int j ,int &maxi,vector<vector<int>>&dp)
    {
        if(i>=n || j>=m )
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int left = solve(n,m,mat,i,j+1,maxi,dp);
        int diag = solve(n,m,mat,i+1,j+1,maxi,dp);
        int down = solve(n,m,mat,i+1,j,maxi,dp);
        
        if(mat[i][j]==1)
        {
            dp[i][j] = 1+min(left,min(diag,down));
            maxi = max(maxi,dp[i][j]);
            
            return dp[i][j];
        
        }
        else
        {
            return dp[i][j]=0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi= 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        solve(n,m,mat,0,0,maxi,dp);
        return maxi;
    }
};