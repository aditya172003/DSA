#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int p=0;
        int a=0;
        int c=0;
        int u =0;
        for(int i =0;i<n;i++)
        {
          
            int z;
            cin>>z;
            
            if(z==1)
            {
                if(a<=0)
                {
                    p++;
                
                    
                }
                else
                {
                    a--;
                
                    
                }
                u++;
                c++;
            }
            else
            {
                a+=u-((c/2 )+ (c%2>0)?1:0);
                u=0;
                c=0;
                
            }
        }

        cout<<p<<endl;
    
    }




    
}