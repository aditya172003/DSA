#include<bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
  public:

    long long maxTripletProduct(long long arr[], int n)
    {
    	sort(arr,arr+n);
    	
    	long long ans=1;
    	ll a = arr[0];
    	ll b = arr[1];
    	ll c = arr[n-1];
    	ll d =arr[n-2];
    	ll e = arr[n-3];
    	
    	ll ans1 = a*b*c;
    	ll ans2 = c*d*e;
    	
    	return max(ans1,ans2);
    	
    	
    	
    	
    	
    	
    }
};