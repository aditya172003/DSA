#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int i ;

    for(int i =1;i<=16 ;i ++)
    {
        cout<<i<<" :"<<(1<<i)<<endl;

    }
    cout<<" 31 :"<<(1ll<<31)<<endl;
    cout<<" 32 :"<<(1ll<<32)<<endl;
    cout<<" 64 :"<<(1ull<<63)<<endl;

    return 0;
}