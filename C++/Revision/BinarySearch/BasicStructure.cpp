#include<bits/stdc++.h>
using namespace std;



// basic templet for binary search on answer 



 int minDays(vector<int>& by, int m, int k) {
        

        int l=1;
        int h=1e9;
        int n=by.size();
        while(l<=h)
        {
            int mid = l+(h-l)/2;

            int a =0;
            int d=0;
            for(int i =0;i<n;i++)
            {
                if(by[i]<=mid)
                {
                    d++;
                    if(d==k)
                    {
                        a++;
                        d=0;
                    }
                }
                else
                {
                    d=0;
                }
            }

            if(a<m)l=mid+1;
            else h=mid-1;
        }

        if(l>1e9)return -1;
        return l;
}