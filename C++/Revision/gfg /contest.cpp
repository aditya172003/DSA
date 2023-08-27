#include<bits/stdc++.h>
using namespace std;
 
 
 

 
class Solution{
public:
    
    long long int f(int l,int h,string s)
    {
        if(l==h)return 0;
        
        
        long long int ans=0;
        for(int k=l;k<h;k++)
        {
            string s1 = s.substr(l,k);
            string s2 =s1;
            reverse(s1.begin(),s1.end());
            if(s1!=s2)
            {
                ans+=1+f(k,h,s);
            }
            
        }
        
        return ans;
    }
    
    long long int countStrings(string s){
        // Your code goes here
        
        return f(0,s.length()-1,s);
    }
};