#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,x1,y1,x2,y2;

        cin>>n>>x1>>y1>>x2>>y2;
        long long int p=0;
        long long int q=0;

        if(x1>(n/2))
        {
            x1=n+1-x1;
        }
        if(x2>(n/2))
        {
            x2=(n+1)-x2;
        }

        if(y1>=x1 && y1<=(n+1-x1))
        {
           p=x1;
        }
        else
        {
            if(y1<=(n/2))
            {
                p=y1;
            }
            else
            {
                p=(n+1-y1);
            }
        }

         if(y2>=x2 && y2<=(n+1-x2))
        {
           q=x2;
        }
        else
        {
            if(y2<=(n/2))
            {
                q=y2;
            }
            else
            {
                q=(n+1-y2);
            }
        }





        long long diff  =abs(p-q);

        cout<<diff<<endl;
    }
}