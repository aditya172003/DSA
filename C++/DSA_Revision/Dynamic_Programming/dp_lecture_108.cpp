

#include<bits/stdc++.h>

using namespace std;


const long long int M = 1e9+7;


long long int countDerangements(int n) {
    // Write your code here.
    
      vector<int>ret(n+1);
     ret[0]=0;
     ret[1]=0;
     ret[2]=1;
     for(int i = 3 ;i<=n;i++)
     {
         ret[i]=(((ret[i-1]+ret[i-2])%M)*((i-1)%M))%M;
     }
      
      return ret[n];
}

