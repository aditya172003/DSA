#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>>nums;
    int n;
    
    long long f(int i,set<int>st,int p,int k)
    {
        if(k==0)
        {
            int z = st.size();
            return p+z*z;
        }
        if(i>=n)
        {
            return 0;
        }


        long long  take = f(i+1,st,p,k);
        st.insert(nums[i][1]);
        p+=nums[i][0];
        long long nott  =f(i+1,st,p,k-1);

        return max(take,nott);
         
    }

    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        n=items.size();
        nums=items;

        set<int>st;
        return f(0,st,0,k);
    }
};