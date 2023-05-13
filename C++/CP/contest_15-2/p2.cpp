#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string a,b;
        cin>>a>>b;
        
        
      map<char,pair<int,int>>cta;
      
      
        
        
        for(int i =0;i<n;i++)
        {
            cta[a[i]].first++;
        }
        for(int j =0;j<m;j++)
        {
            cta[b[j]].second++;
        }
        
        int co=0;
        
        
        int c=0;
        
        
        for(auto i :cta)
        
        
        {    int ans =0; 
             int a =i.second.second;
             int b = i.second.first;
             if(m>n)
             {
               
                 ans = a-b;
             }
             else
             {
                 ans=b-a;
             }
             
             if(ans>0)
             {
                 if(ans&1)
                 {
                     co++;
                 }
             }else
             {
                 c++;
             }
        }

       if(co >1 || c>0 )
       {
           cout<<"NO\n";
       }
       else
       {
           cout<<"YES\n";
       }
       
        
    }
	// your code goes here
	return 0;
}
