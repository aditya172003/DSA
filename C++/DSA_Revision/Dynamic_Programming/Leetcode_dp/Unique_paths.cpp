#include<bits/stdc++.h>
using namespace std;


//https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0







bool isSafe(int i ,int j,int m,int n)

{
	if(i>=0 && i<m && j>=0 && j<n)
	{
		return true;
	}
	return false ;
}




	int paths(int i ,int j ,int m,int n,vector<vector<int>>&dp)
	{
		if(i==m-1 && j == n-1)
		{
			return 1;
		}

		//if(i>=m || j>=m || i<0 || j <0)return 0;
		if(dp[i][j]!=-1)return dp[i][j];

		int ans=0;

		if(isSafe(i+1,j,m,n))
		{
			ans+=paths(i+1,j,m,n,dp);
		}

		if(isSafe(i,j+1,m,n))
		{
			ans+=paths(i,j+1,m,n,dp);
		}


		return dp[i][j]=ans;

	}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>>dp(m,vector<int>(n,-1));

	return paths(0,0,m,n,dp);
}



/// in java Language  dp problem solution

/*

import java.util.* ;
import java.io.*; 
public class Solution {

	public static boolean isSafe(int i ,int j,int m,int n )
	{
		if(i>=0 && j>=0 && i<m &&j<n)
		{
			return true;
		}
		return false;
	}

	public static int solve(int i ,int j, int m,int n ,int arr[][])

	{
		if(i==m-1 && j ==n-1)return 1;

		if(arr[i][j]!=-1)return arr[i][j];


		int ans=0;
		if(isSafe(i+1, j, m, n))
		{
			ans=ans+solve(i+1,j,m,n,arr);
		}
		if(isSafe(i, j+1, m, n))
		{
			ans=ans+solve(i,j+1,m,n,arr);
		}

		arr[i][j]=ans;

		return ans;


	}


	public static int uniquePaths(int m, int n) {
		// Write your code here.
		int arr[][];
		arr  = new int[m][n];

		for(int i =0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				arr[i][j]=-1;
			}
		}

		return solve(0,0,m,n,arr);
	}
}

*/