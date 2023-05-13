#include<bits/stdc++.h>
using namespace std;
/*
There is a row of N walls in Geeksland. The king of Geeksland ordered Alexa to color all the walls 
on the occasion of New Year. Alexa can color each wall with one of the K colors. The cost associated 
with coloring each wall with a particular color is represented by a 2D costs array of size N * K. For
example, costs[0][0] is the cost of coloring wall 0 with color 0; costs[1][2] is the cost of coloring
wall 1 with color 2, and so on... Find the minimum cost to color all the walls such that no two adjacent 4
walls have the same color.


Input: 
N = 4, K = 3
costs[][] = {{1, 5, 7},
             {5, 8, 4},
             {3, 2, 9},
             {1, 2, 4}}

Output:
8
Explanation:
Paint wall 0 with color 0. Cost = 1
Paint wall 1 with color 2. Cost = 4
Paint wall 2 with color 1. Cost = 2
Paint wall 3 with color 0. Cost = 1
Total Cost = 1 + 4 + 2 + 1 = 8
===============================---------------------------------====================================-----------
Input:
N = 5, K = 1
costs[][] = {{5},
             {4},
             {9},
             {2},
             {1}}
Output:
-1
Explanation:

*/

int solve(int i ,int j ,vector<vector<int>> &costs,int n,int m)
{
        if(i>=n)
        {
            return  INT_MAX;
        }
        int ans =costs[i][j];
        for(int k = 0 ;k<m;k++)
        {
            if(k!=j)
            {
                ans = costs[i][j]+min(ans,solve(i+1,k,costs,n,m));
            }
            
        }
        return ans;
}
int minCost(vector<vector<int>> &costs)
{
        vector<int>curr(costs[0].size(),0);
        
        
        int n = costs.size();
        int m = costs[0].size();
        
        for(int  i = 0 ; i<m;i++)
        {
            curr[i] = costs[0][i];
        }
        
        
        for(int i =1;i < n;i++ )
        {
            vector<int>prev(costs[0].size(),0);
            int min1 = INT_MAX,min2 =INT_MAX;
            int i1 =-1;
            
            for(int j =0;j<m;j++)
            {
                if(curr[j]<min1)
                {
                    min1=curr[j];
                    i1=j;
                }
       
                
            }
            
            for(int j =0;j<m;j++)
            {
                if(curr[j]<min2 && j!=i1)
                {
                    min2=curr[j];
                    
                }
       
                
            }
            
            for(int j = 0 ; j <m;j++)
            {
                if(j!=i1)
                {
                     prev[j]=costs[i][j]+min1;
                }
                else
                {
                    prev[j]=costs[i][j]+min2;
                }
            }
                
                
         
            
            curr = prev;
        }
        
         int ans1 = *min_element(curr.begin(),curr.end());
        
        if(ans1>0)
        {
            return ans1;
        }
    return -1;
        
        
}
