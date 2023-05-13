#include<bits/stdc++.h>

using namespace std;

int M =1000000007;

int solve(int p,int m,int n,vector<int>&col,vector<int>ans,int k)
{
    if(p>n)return 0;
    if(m==0)
    {
            bool f =true;
            int i =0;
            while(i<ans.size())

            {
                int z = ans[i];
                int j =0;
               
                

                while(j<k)
                {
                    if(ans[i]!=z)
                    {
                        f=false;
                    }
                    i++;
                    j++;
                }
            }
            if(f)return 1;
            return 0;
    }

    int exc = solve(p+1,m,n,col,ans,k);
    ans.push_back(col[p]);
    int inc = solve(p+1,m-1,n,col,ans,k);

    int ans1 = ((exc)%M +(inc)%M)%M;
    return ans1;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>col(n);
        for(int i=0;i<n;i++)
        {
            cin>>col[i];
        }
        vector<int>ans;
       cout<<solve(0,2*k,n,col,ans,k)<<endl;
        
    }
}