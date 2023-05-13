#include<bits/stdc++.h>
using namespace std;


// lecture number 12




int solve(int i ,int j,vector<vector<int>>&grid )
{
	if( j>=grid[i].size() || i>=grid.size() )
	{
		return 1e9;
	}
	if(i==grid.size()-1)
	{
		return grid[i][j];
	}

	int up  = grid[i][j]+solve(i+1,j,grid);
	int down= grid[i][j]+solve(i+1,j+1,grid);


	return min(up,down);

}
int minimumPathSum(vector<vector<int>>& triangle, int n){

	return solve(0,0,triangle);
}




int minimumPathSumTabulation(vector<vector<int>>& triangle, int n){
	// Write your code here.

	//return solve(0,0,triangle);


	vector<vector<int>>dp(n);
	vector<int>p;
	p.push_back(triangle[0][0]);
	dp[0]=p;

	for(int i =1;i<n;i++)
	{
		vector<int>p1(triangle[i].size(),0);

		for(int j=0;j<triangle[i].size();j++)
		{
			int up    =triangle[i][j];
            //        |-----------missing area 
			if(i>0&& j<dp[i-1].size())up+=dp[i-1][j];
			else up+=1e9;

			int dig = triangle[i][j];

			if(i>0 && j>0)dig+=dp[i-1][j-1];
			else dig +=1e9;


			p1[j]=(min(up,dig));

		}
		dp[i]=p1;
	}

	return *min_element(dp[n-1].begin(),dp[n-1].end());
}



// tabulation is same as the min path sum qustion 
// think about the existance of j in previous dp 
// there where your were missing the question 


