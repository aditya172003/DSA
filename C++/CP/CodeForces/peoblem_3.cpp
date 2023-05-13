#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n;
        cin>>s;
        int ans =0;
        int db=0;
        string s1;
        s1.push_back(s[0]);
        s1.push_back(s[1]);
        for(int i =1;i<n;i++)
        {   
            string s2;
            s2.push_back(s[i]);
            s2.push_back(s[i-1]);
            if(s1==s2)
            {
                db++;
            }
            else
            {
                if(db>1)
                {
                  ans+=(db-1);
                 
                }
                db=0; 
                s1=s2;
                 
            }

        }
        if(db>1)
        {
            ans+=(db-1);
        }

        cout<<(n-1-ans)<<endl;
    }
}