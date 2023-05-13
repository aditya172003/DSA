
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

  
    long long solve(int N, int K, vector<long long> G) {
       vector<long long int>dp(N+2);
       long long c=0;
       for(int i =1;i<=K;i++)
       {
           dp[i]=G[i-1];
           c=c+dp[i];
           
           
       }
       dp[K+1]=c;
       int j=1;
       for(int i =K+2; i<=N;i++)
       {
           dp[i]=2*dp[i-1]-dp[j];
           j++;
       }
       
       return dp[N];
    }
};
