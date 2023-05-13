#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()

{
int t;
cin>>t;

while(t--)
{

    string s;
    int n,k;
    cin>>n>>k;
    cin>>s;

    map<char,bool>checked;
    map<char,int>mp;
    for(int  i =0;i<n;i++)
    {
        mp[s[i]]++;
    }

    int ans =0;
    for(auto i :mp)
    {
        char c1 = i.first;
        int  cn1= i.second;
        char c2 = c1^(1<<5);
        int  cn2= mp[c2];
        if(!checked[c1] && !checked[c2])
        {
            ans+=min(cn1,cn2);
            int diff = max(cn1,cn2)-min(cn1,cn2);
            ans += min(k,(diff/2));
            k-=min(k,diff/2);
            checked[c1]=true;
            checked[c2]=true;


        }
        

    }
    cout<<ans<<endl;
}


}