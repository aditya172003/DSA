#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countSubstring(string s)
    {
        int ans =0;
        int n = s.length();
        for(int i =0;i<n;i++)
        {
            int c=0;
            int sm=0;
            for(int j =i;j<n;j++)
            {
                if((int(s[j])&(1<<5))==32)
                {
                    c++;
                }
                else
                {
                    sm++;
                }
                
                if(c==sm)ans++;
            }
            
        }
        
        return ans;
    }
};