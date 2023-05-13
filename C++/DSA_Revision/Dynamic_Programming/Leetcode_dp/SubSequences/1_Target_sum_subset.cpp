#include<bits/stdc++.h>

using namespace std;


    bool solve(int  i , int t,vector<int>&arr, vector<vector<int>>&dp)
    {
        if(t==0)return true;
        if(t<0)return false;
        if(i==0)return (arr[0]==t);

        if (dp[i][t] != -1)return dp[i][t];
         

        bool inc= false,exc;
        if(t-arr[i]>=0)
        {
           inc =  solve(i-1,t-arr[i],arr,dp);

        }
           exc = solve(i-1,t,arr,dp);


           dp[i][t]=(inc||exc);

           return dp[i][t];
    }

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
   vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solve(n-1,k,arr,dp);
}



/*

Here the important thing is that while taking the dp its target size must be k+1
because we are adding dp[i][t] where  t ==k but we have taken dp size exactly k 
so it has last index k-1 and not k 
so take dp size as k+1;

*/











//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos







// same problem with index start with 0;







#include<map>
bool solve(int i ,int s,int t,int n,vector<int>&arr,vector<vector<int>>&dp)
{
	

	if(i>=n)
	{
		return false;
	}

	
	if(dp[i][s]!=-1)return dp[i][s];
   
		
	if(s==t)return dp[i][s]= true;
	

	bool inc =false;

	if(s+arr[i]<=t)
	{
		inc= solve(i+1,s+arr[i],t,n,arr,dp);
	}
	bool exc = solve(i+1,s,t,n,arr,dp);
	dp[i][s]=inc|exc;
	return  dp[i][s];
}

bool canPartition(vector<int> &arr, int n)
{
	int s=0;
	for(int i=0;i<n;i++)
	{
		s+=arr[i];
	}
	int k =(s/2) +1;
	if(s%2)return false;
	vector<vector<int>>dp(n,vector<int>(k,-1));
	return solve(0,0,s/2,n,arr,dp);

}




// tabulation concept 


   
bool subsetSumToK(int n, int k, vector<int> &arr) {

    // Write your code here.
    

   vector<vector<int>>dp(n,vector<int>(k+1,0));
   for(int i=0;i<n;i++)
   {
       dp[i][0]=true;
   }

  if(arr[0]<=k)
  {
       dp[0][arr[0]]=true;
  }

   for(int i =1;i<n;i++)
   {
       for(int j=1;j<=k;j++)
       {
           bool take ,notake;

           notake = dp[i-1][j];
           if (arr[i]<=j) {
             take = dp[i - 1][j - arr[i]];
           }

           dp[i][j] = take|notake;
       }

   }

   return dp[n-1][k];

}