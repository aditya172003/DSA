#include<bits/stdc++.h>

using namespace std;

int solve(vector<char>ch,int m)
{
    int n = ch.size();
    int i=0,j=0;
    int in=0,jn=0;
    int ans=INT_MIN;
    while(j<n)
    {
        

        while(ch[j]!='O')
        {
            jn++;
            
        }
        jn++;
        while(i!=j)
        {
            i++;
            in++;
        }
        while(ch[j]!='O')
        {
            j++;
            jn++;
        }

        m--;
        if(m==0)
        {
           ans=max(ans,(in+1+jn));
           in=0;
           jn=0;
        }




    }

    return ans;
}