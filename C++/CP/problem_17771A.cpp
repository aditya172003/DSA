#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        vector<int>m;
        for(long long int i =0;i<n;i++)
        {
            long long  int p;
             cin>>p;
             m.push_back(p);
        }

        sort(m.begin(),m.end());
          long long int min=*min_element(m.begin(),m.end());
          long long int max=*max_element(m.begin(),m.end());
        long long int  a = count(m.begin(),m.end(),min);
        long long int b=count(m.begin(),m.end(),max);

        if(min==max)
        {
            cout<<a*(a-1)<<endl;
        }
        else
        {
            cout<<2*a*b<<endl;
        }
        
        
    }
        
    

    return 0;
}
