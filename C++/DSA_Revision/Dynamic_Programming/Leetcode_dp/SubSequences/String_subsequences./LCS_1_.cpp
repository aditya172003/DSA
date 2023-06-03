#include<bits/stdc++.h>

using namespace std;



// memorization
int slv(int i,int j,string s1,string s2,vector<vector<int>>&dp)
{
	if(i<0 || j<0)
	{
		return 0;
	}

	if(dp[i][j]!=-1)return dp[i][j];
	if(s1[i]==s2[j])
	{
		return dp[i][j]= 1+slv(i-1,j-1,s1,s2,dp);
	}

	return dp[i][j] = max(slv(i,j-1,s1,s2,dp),slv(i-1,j,s1,s2,dp));

}


int lcs(string s, string t)
{
	//Write your code here

	int i =s.length();
	int j = t.length();

	vector<vector<int>>dp(i,vector<int>(j,-1));

	return slv(i-1,j-1,s,t,dp);
}




// using tabulation 


int lcsTab(string s, string t)
{
	//Write your code here

	int i =s.length();
	int j = t.length();
	vector<vector<int>>dp(i+1,vector<int>(j+1,0));

	for(int p =1;p<=i;p++)
	{
		for(int q=1;q<=j;q++)
		{
			if(s[p-1]==t[q-1])
			{
				dp[p][q]=1+dp[p-1][q-1];
			}
			else
			{
				dp[p][q]=max(dp[p-1][q],dp[p][q-1]);
			}
		}
	}

	return dp[i][j];
    //return slv(i-1,j-1,s,t,dp);
}







// space optimization




int lcs(string s, string t)
{
	//Write your code here

	int i =s.length();
	int j = t.length();

    vector<int>prev(max(i,j)+1,0);
    vector<int>curr(max(i,j)+1,0);
	for(int p =1;p<=i;p++)
	{
		for(int q=1;q<=j;q++)
		{
			if(s[p-1]==t[q-1])
			{
				curr[q]=1+prev[q-1];
			}	
			else
			{
				curr[q]=max(prev[q],curr[q-1]);
			}
		}
		prev=curr;
	}

	return prev[j];

	//return slv(i-1,j-1,s,t,dp);
}