#include<bits/stdc++.h>


using namespace std;
int min(int a, int b, int c) { return min(max(a, b), c); }
int main()
{

        int a=8,b=5,c=10;
            int mini =min(a,b,c);
            int i =mini;
            int ans =0;
            for(;i>=1;i--)
            {
                int p =a^i;
                int q = b^i;
                int r = c^i;
                
                if(p<q && q<r)
                {
                    ans =i;
                    break;
                }
                
            }
            
            if(i==0)
            {
                ans =-1;
           
            }


            cout<<ans<<endl;
}