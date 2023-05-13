#include<iostream>

using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,a,b;

        cin>>n>>a>>b;

        if(a<=b)
        {
            long long int p=n/a;
            if(n%a!=0)
            {
                p++;
            }
            cout<<p<<endl;
        }
        else
        {
            cout<<1<<endl;
        }

    }
}