#include<bits/stdc++.h>
using namespace std ;

//https://leetcode.com/problems/shortest-path-in-binary-matrix/submissions/961878124/

class Solution {
public:

    int f(int i ,int j,vector<vector<int>>& g,vector<vector<int>>&visited)
    {
         int n = g.size();
            int m = g[0].size();
            if(i==n-1 && j==m-1)
            {
                if(g[i][j]==0)return 1;
                return 1e9;
            }
           
            visited[i][j]= 1;

            int x[8] = {1,0,-1,0,1,1,-1,-1};
            int y[8] = {0,1,0,-1,1,-1,1,-1};

            int ans =1e9;
           
            for(int k = 0;k<8;k++)
            {
                int nx = i+x[k];
                int ny = j+y[k];

            if(nx>=0 && nx<n && ny >=0 && ny<m && !visited[nx][ny] && g[nx][ny]==0)
            {
                ans =min(ans,1+f(nx,ny,g,visited)); 
            }

            }
            visited[i][j]=0;
           return ans;


    }

    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        if(g[0][0]==1 || g[n-1][m-1]==1)return -1;

        g[0][0]=1;
        
        vector<vector<int>>visited(n,vector<int>(m,0));

        queue<pair<int,int>>q;
        q.push({0,0});
        int t=0;
        while(!q.empty())
        {
            int k = q.size();
           
            t++;

            while(k--)
            {
                auto i =q.front();
                q.pop();

                if(i.first==n-1 && i.second ==m-1)return t;
               
                int x[8] = {1,0,-1,0,1,1,-1,-1};
                int y[8] = {0,1,0,-1,1,-1,1,-1};

            
           
            for(int k = 0;k<8;k++)
            {
                int nx = i.first+x[k];
                int ny = i.second+y[k];

        if(nx>=0 && nx<n && ny >=0 && ny<m && !visited[nx][ny] && g[nx][ny]==0)
            {
                 //visited[i.first][i.second]=1;

                 g[nx][ny]=1;
                 q.push({nx,ny});
            }

            }

            }

        }
        
        return -1;

    }
};