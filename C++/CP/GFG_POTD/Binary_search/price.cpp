

#include<bits/stdc++.h>
using namespace std;

class Shop
{
    public:
    int get(int d)
    {
            int a=1;
        return a;
    }
};


class Solution{
    public:
    
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
       long long int ans=0;
       
       vector<int>pr(n,0);
       
      
       while(k>0)
       {
           int l =  0;
           int h =  n-1;
           int p =  0;
           int mid = (l)+ (h-l)/2;
           int mp = -1;
            while(l<=h)
            {
               if(pr[mid]==0)
               {
                   pr[mid]=shop.get(mid);  //<--------similar to dp------------------------------- logic :::::::
                   p=pr[mid];
               }
               else
               {
                   p=pr[mid];
               }
               
                
                if(p<=k)
                {
                    if(mp<p)
                    {
                        mp=p;
                    }
                    l=mid+1;
                }
                else
                {
                    h=mid-1;
                }
                mid = (l)+ (h-l)/2;
            }
            
            
         if(mp!=-1)
         {
                ans+=k/mp;
                k%=mp;
         }else
         {
             return ans;
         }
          
           
            
       }
       
       return ans;
    }

};