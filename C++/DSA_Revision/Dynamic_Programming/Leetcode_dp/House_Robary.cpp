#include <bits/stdc++.h> 
#define ll long long int

using namespace std;

ll solve(vector<ll>&dp,int i,vector<int>&vih,int n )
{
     if(i==n)
    {
        return vih[i];
    }

    if(i<n)
    {
        return 0;
    }

   
   
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    
    ll inc;
    ll exc;

        inc = solve(dp,i-2,vih,n)+vih[i];
       
        exc = solve(dp,i-1,vih,n);
  
   
   

    dp[i]= max(inc,exc);

    return dp[i];

}


long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    ll n =*max_element(valueInHouse.begin(),valueInHouse.end());
    vector<ll>dp(n+1,-1);
    
    
    ll n2=valueInHouse.size()-1;
    if(n2==0)
    {
        return valueInHouse[0];
    }
    ll ans1 = valueInHouse[n2]+solve(dp,n2-2,valueInHouse,1);

    ll ans2 = solve(dp,n2-1,valueInHouse,0);

    return max(ans1,ans2);
}