

#include<bits/stdc++.h>

using namespace std;


// same concept as DFS_1.cpp question but return type and all depends on the condition of the problem

class Solution {
public:
    pair<int,bool> dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited)
    {
        int r = grid.size();
        int c =grid[0].size();
        if(i<0||i>=r ||j<0||j>=c)return {0,false};
        
        if(grid[i][j]==0||visited[i][j])return {0,true};
        
        if(i==0 || j==0 ||i==r-1 ||j==c-1) return {0,false};
        

        

        visited[i][j]=1;

        pair<int,int> ans1,ans2,ans3,ans4;
        ans1=dfs(i+1,j,grid,visited);
        ans2=dfs(i-1,j,grid,visited);
        ans3=dfs(i,j+1,grid,visited);
        ans4=dfs(i,j-1,grid,visited);
       
        pair<int ,bool>ans;
        ans.first = 0;
        ans.second=ans1.second&&ans2.second&&ans3.second&&ans4.second;
        if(ans.second)
        {
            ans.first =1+ans1.first+ans2.first+ans3.first+ans4.first;
        }

        return ans;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c =grid[0].size();
        int ans=0;
        vector<vector<int>>visited(r,vector<int>(c,0));

        for(int i =0;i<r;i++)
        {
            for(int j =0;j<c;j++)
            {
                if(grid[i][j]&&!visited[i][j])
                {
                    ans+=dfs(i,j,grid,visited).first;
                }
            }
        }

        return ans;
    }
};




/*

    You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
*/




















