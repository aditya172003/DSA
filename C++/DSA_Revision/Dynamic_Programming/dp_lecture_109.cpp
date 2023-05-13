#include <bits/stdc++.h>

using namespace std;

// error is becuse the overflow the values during multiplication 

// thats why 1ll has multiplyed here 


const int M = 1e9+7;

int solve(int n,int k,vector<int>&dp)
{
   if(n==2)
   {
    return (k%M+((k%M)*1ll*((k-1)%M))%M)%M;
   }

   if(n==1)
   {
    return k;
   }

   if(dp[n]!=-1)
   {
    return dp[n];
   }

    int s =  ((solve(n-2,k,dp)%M )*1ll*((k-1)%M))%M;
    int d = ((solve(n-1,k,dp)%M )*1ll*((k-1)%M))%M;

    dp[n]=((s%M)+(d%M))%M;
    return dp[n];


}

int numberOfWays(int n, int k) {
    // Write your code here.
    vector<int>dp(n+1,-1);

    return solve(n,k,dp);
}
