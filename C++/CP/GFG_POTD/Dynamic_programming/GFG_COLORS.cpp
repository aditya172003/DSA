#include<bits/stdc++.h>

using namespace std;

/*
 There is a row of N walls in Geeksland. The king of Geeksland ordered Alexa to color all the walls
 on the occasion of New Year. Alexa can color each wall with either pink, black, or yellow. The cost
 associated with coloring each wall with a particular color is represented by a 2D array colors of 
 size N*3 ,where colors[i][0], colors[i][1], and colors[i][2] is the cost of painting ith wall with
 colors pink, black, and yellow respectively.

*/


class Solution{   
public:
    
    int minCost(vector<vector<int>> &colors, int n) {
       
        vector<vector<int>>ans(n,vector<int>(3,0));
        
        for(int i =0;i<3;i++)
        {
            ans[0][i]=colors[0][i];
        }
        
        
        for(int i =1;i<n;i++)
        {
            ans[i][0]=min(ans[i-1][1],ans[i-1][2])+colors[i][0];
            ans[i][1]=min(ans[i-1][0],ans[i-1][2])+colors[i][1];
            ans[i][2]=min(ans[i-1][0],ans[i-1][1])+colors[i][2];
        }
        
        
           int fans = min(ans[n-1][0],min(ans[n-1][1],ans[n-1][2]));
           
           
           return fans;
        
    }


};
