#include<bits/stdc++.h>
using namespace std;


int findPages(vector<int>& by, int n, int m) {
        int l=*max_element(by.begin(),by.end());
        int h=0;
        for(auto i : by)h+=i;
        if(n<m)return -1;
   
        int ans =INT_MAX;
        while(l<=h)
        {
            int mid = l+(h-l)/2;

            int a =1;
            int d=0;
            int mxi = INT_MIN;
            for(int i =0;i<n;i++)
            {
               if(d+by[i]<= mid)
               {
                   d+=by[i];

               }
               else{
                   a++;
                    mxi=max(mxi,d);
                    d=by[i];
               }
            }

            if (a <= m)
            {
                  h = mid - 1;
                      
                
            }
              
            else{
              
                  l= mid + 1;
            }
           
        }

        
        return l;
}