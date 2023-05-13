#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int isSum(int sum,int t,int n,int i,int *arr,vector<vector<int>>&dp)
    {
        if(i>=n)
        {
            if(sum==t)
            {
                return  1;
            }
            return 0;
        }
        if(sum>t)
        {
            return 0;
        }
        
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        
        
        int inc = isSum(sum+arr[i],t,n,i+1,arr,dp);
        int exc = isSum(sum,t,n,i+1,arr,dp);
        
        return dp[i][sum]=inc|exc;
    }
    int equalPartition(int N, int arr[])
    {
        int t=0;
        for(int i =0;i<N;i++)
        {
            t+=arr[i];
        }
        if(t%2==0)
        {
            t=t/2;
             vector<vector<int>>dp(N+1,vector<int>(t+1,-1));
             return isSum(0,t,N,0,arr,dp);
        }
       else
       {
           return 0;
       }
    }
};

