#include<bits/stdc++.h>
using namespace std;


int solve(int i ,int j ,int l,int m, vector<vector<int>> &grid,vector<vector<vector<int>>>&dp)
{
    int  r= grid.size();
    int  c= grid[0].size();

    if(i>=r || i<0 || j>=c|| j<0)
    {
        return -1e8;
    }

    if(l>=r || l<0 || m>=c|| m<0)
    {
        return -1e8;
    }

    if(dp[i][j][m]!=-1)
    {
        return dp[i][j][m];
    }

    if(i==(r-1))
    {
        if(j==m)
        {
            return dp[i][j][m]= grid[i][j];

        }
        else
        {
            return dp[i][j][m]=grid[i][j]+grid[l][m];
        }
    }



    int maxi=0;

    for(int j1 = -1;j1<=1;j1++)
    {
        for(int j2=-1;j2<=1;j2++)
        {
            if(j==m)
            {
                maxi=max(maxi,grid[i][j]+solve(i+1,j+j1,l+1,m+j2,grid,dp));
            }
            else
            {
                maxi=max(maxi,grid[i][j]+grid[l][m]+solve(i+1,j+j1,l+1,m+j2,grid,dp));
            }
        }
    }

    return dp[i][j][m]=maxi;

}




int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>>dp(r+1,vector<vector<int>>(c+1,vector<int>(c+1,-1)));
    return solve(0,0,0,c-1,grid,dp);
}