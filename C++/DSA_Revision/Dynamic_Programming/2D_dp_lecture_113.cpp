#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>&day,vector<int>&cost ,int n ,int index,vector<int>&dp)
{

    if(index>=n)

    {
        return 0;
    }

    if(dp[index]!=-1)
    {
        return dp[index];
    }

    // 1 day pass

    int opt1 = cost[index]+solve(day,cost , n , index ++,dp);

    int i;
    for(i=index;i<n && day[i]<=day[index]+7;i++,dp);

    int opt2 = cost[index]+solve(day , cost ,n,i,dp);

    for(i = index;i<n&& day[i]<=day[index]+30;i++,dp);

    int opt3 = cost[index]+solve(day,cost , n ,i,dp);

    dp[index] = min(opt1,min(opt2,opt3));
    
    return dp[index];
}


int main()
{

}