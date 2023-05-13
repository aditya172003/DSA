#include<iostream>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;

        if(n==1)
        {
            cout<<1<<endl;
        }
        else{
            cout<<n-1<<endl;
        }
    }

    return 0;
}