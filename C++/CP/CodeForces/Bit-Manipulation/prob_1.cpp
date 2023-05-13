#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()

{
    int t;
    cin>>t;
    while(t--)
    {
        map<int,bool>mp;
        
        int n,m;
        cin>>n>>m;
        vector<int>ans(n,-1);
        vector<int>p;
        for(int i =0;i<m;i++)
        {
            int a;
            cin>>a;
            mp[a]=false;
            p.push_back(a);
        }
        int k=n-1;
        for(int i =0;i<m;i++)
        {
           if(!mp[p[i]] && k>=0)
           {
            ans[k]=i+1;
            k--;
            mp[p[i]]=true;
           }            
        }
        
        for(auto i :ans)
        {
            cout<<i<<" ";
        }
        cout<<endl;

    }
}