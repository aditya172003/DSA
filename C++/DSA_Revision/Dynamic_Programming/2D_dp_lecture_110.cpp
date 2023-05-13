#include <bits/stdc++.h> 

using namespace std;
// recursion 

// dp using tabulation ,memorization

// using space optimization 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int>curr(maxWeight+1,0);
    
	for(int i =0;i<=maxWeight;i++)
	{
		if(weight[0]<=i)
		{
			curr[i]=value[0];
		}
		
	}

	for(int i =1 ;i<n;i++)
	{
		for(int w=maxWeight;w>=0;w--)
		{   int inc =0;
		
			if(weight[i]<=w)
			{
				inc= value[i]+curr[w-weight[i]];
			}

			curr[w]=max(curr[w],inc);
		}
	}

	return curr[maxWeight];

}


// using tabulation method dp vector


int solve(vector<int> weight, vector<int> value,int index,int w,vector<vector<int>>&dp)

{
         if(index ==0)
		 {
	        if(weight[0]<=w) return value[0];
			return 0;
		 }


         
		 if(dp[index][w]!=-1)
		 {
			 return dp[index][w];
		 }

                             

		 int include=0;

		 if(weight[index]<=w)
		 {
             include = value[index]+solve(weight,value,index-1,w-weight[index],dp);
		 }

		 int exc= solve(weight,value,index-1,w,dp);


		  dp[index][w] = max(include,exc);

		 return dp[index][w];
	
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));

	return solve(weight,value,n-1,maxWeight,dp);
}