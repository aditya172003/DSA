#include<iostream>

using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b;
        cin>>c>>d;
        bool a1=(a>b&&c>d) ||(a<b&&c<d);
        bool a2 =(a>c&&b>d)||(a<c&&b<d);

        if(a1&a2)
        {
            cout<<"YES"<<endl;

        }
        else
        {
            cout<<"NO"<<endl;
        }

    }

    return 0;
}