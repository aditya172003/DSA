#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited)
    {
        int r = grid.size();
        int c = grid[0].size();

        if(i>=r || i<0 ||j>=c||j<0)return false;

        if(grid[i][j]==1||visited[i][j])return true;

        


        visited[i][j]=1;

        bool u,d,l,r1;

        u  = dfs(i,j+1,grid,visited);
       

        d  = dfs(i,j-1,grid,visited);

        l  = dfs(i-1,j,grid,visited);

        r1  = dfs(i+1,j,grid,visited);


        return r1&l&d&u;

        
    }

    int closedIsland(vector<vector<int>>& grid) {

         int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>>visited(r,vector<int>(c,0));


        int ans=0;
        for(int i =0;i<r-1;i++)
        {
            for(int j=0;j<c-1;j++)
            {
                if(visited[i][j]==0&&grid[i][j]==0)
                {
                    ans+=dfs(i,j,grid,visited);
                }
            }
        }

        return ans;
    }
};

/*
Given a 2D grid consists of 0s (land) and 1s (water). 
 An island is a maximal 4-directionally connected group 
 of 0s and a closed island is an island totally (all left, 
 top, right, bottom) surrounded by 1s.

Return the number of closed islands.


Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

topics related 

Array
Depth-First Search
Breadth-First Search
Union Find
Matrix


*/