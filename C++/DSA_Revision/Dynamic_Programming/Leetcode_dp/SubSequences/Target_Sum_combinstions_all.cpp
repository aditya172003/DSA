#include<bits/stdc++.h>

using namespace std;



    // nice problem as here we have -ve indices so cant use vector we can use map of pair and int as it is 2D

    // subsequence zero problem is occured so returned 2;

    // no constrain on take and sub
    // conpulsary we have to take all 
    


int solve(int i,int t,int tar,vector<int>&arr,    
map<pair<int,int>,int>&dp)
{

  if (i == 0) {
   
    if(t== 0 && arr[0]==0)return 2;
    if (t - arr[0] == 0)return 1;
    if(t+arr[0]==0)return 1;

       return 0;
       

    }
    pair<int,int>p={i,t};
    if(dp.find(p)!=dp.end())return dp[{i,t}];

    int take=0;
    int sub =0;
 

            // if(t+arr[i]<=1000)
            // {
            //      take = solve(i-1,t+arr[i],tar,arr,dp);
            // }
           
            take = solve(i-1,t+arr[i],tar,arr,dp);
    

    
            // if(t-arr[i]>=-1000)
            // {
            //         sub = solve(i-1,t-arr[i],tar,arr,dp);
            // }   
             
         
              sub = solve(i-1,t-arr[i],tar,arr,dp);

    

        
   // pair<int,int>p={i,t};
    dp[p] = take + sub;

    return dp[p];
    // return  take + sub;
}



int targetSum(int n, int target, vector<int>& arr) {
    
 map<pair<int,int>,int>dp;

    return solve(n-1,target,target,arr,dp);
}

//https://www.codingninjas.com/codestudio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0