#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,b;
        cin>>n>>b;
        long long int  s1 ,s2;
        long long int m =1;
        if(n>b)
        {
            s1=b-1;
            m=b;
            s1++;

            s1+=((n/2)-m);
            s1+=2;
            if(n%2!=0 && n!=1)s1++;
        }
        else
        {
            s1=n-1;
            m=n;
            s1++;

            s1+=((b/2)-m);
            s1+=2;
            if(b%2!=0&&b!=1)s1++;
        }





        cout<<s1<<endl;
        
    }
}