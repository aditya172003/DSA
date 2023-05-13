#include<bits/stdc++.h>

using namespace std;

// solved  ;; ; ;  ;; ;;;;;;;;
int solve(int n)
{
    	
	vector<int> vec(n+1 ,0);
    vec[0]=0;
    vec[1]=1;
    vec[2]=2;
    for(int k=3;k<=n;k++)
    {   
        int i=1,j=k-1;
        int ans = INT_MAX;
        while(i<=j)
        {      if(i*i == k)
               {
                   ans=1;
                   break;
               }
               ans = min(ans,vec[i]+vec[j]);
               i++;
               j--;
        }
        vec[k]=ans;
    }

    return vec[n];
	

}
