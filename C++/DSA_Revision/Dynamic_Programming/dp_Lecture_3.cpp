#include<bits/stdc++.h>

using namespace std;

// using dp 
/*


*/



int solve(vector<int>&num,int x,vector<int>&dp)
{
    if(x==0)
    {
        return 0;
    }

    if(x<0)
    {
        return INT_MAX;

    }
    if(dp[x]!=-1)
    {
          return dp[x];
    }


    int mini=INT_MAX;

    for(int i = 0;i<num.size();i++)
    {
         int ans= solve(num,x-num[i],dp);

         if(ans!=INT_MAX)
         {
             mini = min(mini,ans+1);
         }

    }
    dp[x]=mini;
    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    

    vector<int>dp(10000+1,-1);
    int ans = solve(num,x,dp);
     if(ans==INT_MAX)
     {
         return -1;
     }
     return ans;

}


// tabulation

int solve1(vector<int>&num,int x)
{
    int n =num.size();
    vector<int>dp(x+1,INT_MAX);
    
    
    dp[0]=0;
    
    for(int k =1;k<=x;k++)
    {
        for(int j=0;j<n;j++)
        {
                if(k-num[j]>=0 && dp[k-num[j]]!=INT_MAX )
                { 
                    dp[k]=min(dp[k],1+dp[k-num[j]]);
                }
        }
    
        

    }

    if(dp[x]==INT_MAX)
    {
        return -1;
    }
    return dp[x];

}



int main()
{ 
    
   int t;
   cin>>t;
   while(t--)
   {
    int n,x;
    cin>>n>>x;
    vector<int>dp(x+1,0);
    
    dp[0]=1;

    for(int i =1;i<=n;i++)
    {   
        int x;
        cin>>x;

        dp[x]=1;
    }
    for(int k =1;k<=x;k++)
    {
         int i=1;
         int j=k-1;
          int ans=INT_MAX;
      
          while( i<=j && dp[k]==0)
          {
               ans=min(ans,(dp[i]+dp[j]));
               i++;
               j--;
          }
          if(dp[k]==0)
            dp[k]=ans;

    }

    if(dp[x]>0)
    {   dp[0]--;
        cout<<dp[x]<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }

      
   }


    return  0;

}