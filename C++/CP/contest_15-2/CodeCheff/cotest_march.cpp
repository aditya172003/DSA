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
        for(int i =0;i<n;i++)
        {
            int z;
            cin>>z;
            if(z==1)
            {
                if(a==0)
                {
                    p++;
                }
                else
                {
                    a--;
                }
                c++;
            }
            else
            {
                a= p-((c/2) + i*(c%2>0)?1:0 );
            }
        }

        cout<<p<<endl;
    
    }




    
}


/*
while(t--)
    {
      
      int ng;
      cin>>ng;
      

    int p=0;

    int n=0;

    for(int i=0;i<ng;i++)
    {
        int a;
        cin>>a;
        if(a>0)
        {
            p++;
        }
        else
        {
            n++;
        }
    }

    int k=0;
    vector<int>ans;
    vector<int>a2;
    for(int i =0;i<p;i++)
    {
        k++;
        ans.push_back(k);
    }
    for(int j=0;j<n;j++)
    {
        k--;
        ans.push_back(k);
    }

     k=0;

       while(n>0)
       {
        a2.push_back(1);
        a2.push_back(0);
        n--;
        p--;
       }
       while(p>0)
       {
        k++;
        a2.push_back(k);
        p--;
       }

        for(auto i : ans)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i : a2)
        {
            cout<<i<<" ";
        }
        cout<<endl;

    }
    
    */