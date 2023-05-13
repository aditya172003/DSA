
#include<bits/stdc++.h>

using namespace std;

/*
You are given a matrix grid of n x  m size consisting of values 0 and 1.
 A value of 1 means that you can enter that cell and 0 implies that entry to that cell is not allowed.

You start at the upper-left corner of the grid (1, 1) and you have to reach 
the bottom-right corner (n, m) such that you can only move in the right or down direction from every cell.

Your task is to calculate the total number of ways of reaching the target modulo (109+7).
Note: The first (1, 1) and last cell (n, m) of the grid can also be 0




Input:
n = 3, m = 3
grid[][] = {{1, 1, 1};
            {1, 0, 1};
            {1, 1, 1}}
Output:
2
Explanation:
1 1 1
1 0 1
1 1 1
This is one possible path.
1 1 1
1 0 1
1 1 1
This is another possible path.




*/



const long long int M = 1e9+7;
class Solution {
  public:
  
    bool can(vector<vector<int>>&visited,vector<vector<int>> &grid,int i , int j,int n,int m )
    {
         if(i>=n || j>=m || i<0 || j<0)
        {
            return false;
        }
        
        
        
        if(grid[i][j] && !visited[i][j]) 
            return true;
        
        
        return false;
    }
    int solve(int i , int j , int n,int m,vector<vector<int>>&visited,vector<vector<int>> &grid,vector<vector<int>>&dp)
    {
        if(i==n-1 && j==m-1)
        {
            return 1;
            
        }
        
        if(i>=n || j>=m || i<0 || j<0)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int ans =0;
        visited[i][j]=1;
        if(can(visited,grid,i+1,j,n,m))
        { 
            
            ans=((ans%M)+solve(i+1,j,n,m,visited,grid,dp)%M)%M;
            
        }
        
       
        
         if(can(visited,grid,i,j+1,n,m))
        {
             ans=((ans%M)+solve(i,j+1,n,m,visited,grid,dp)%M)%M;
        }
        
        
      
        
        visited[i][j]=0;
        return dp[i][j]= ans%M;
    }
    
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>>visited(n+1,vector<int>(m+1,0));
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if(grid[0][0]==0)
        {
            return 0;
        }
        return solve(0,0,n,m,visited,grid,dp)%M;
    }
};