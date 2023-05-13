#include<bits/stdc++.h>
using namespace std;





vector<int> solve(long long int p1,int i,long long  n,vector<vector<int>>&dp)
{
   cout<<p1<<" == "<<i<<endl;
  
    if(i>40)
    {
        vector<int>ans;
        ans.push_back(-1);
        return ans;
    }
    if(p1>n)
    {

        vector<int>ans;
        ans.push_back(-1);
        return ans;
    }
    if(dp[p1].size()!=0)return dp[p1];
    


     long long x1 = (2*p1)+1;
     long long  x2 = (2*p1)-1;

     if(x1==n)
    {
        vector<int>ans;
        ans.push_back(2);
        return ans;
    }

    

    if(x2==n)
    {
        vector<int>ans;
        ans.push_back(1);
        return ans;
    }

     

       vector<int>ans1 ;
      
       vector<int>ans2; 
    
     if(x1!=p1)
     {
        ans1= solve(x1,i+1,n,dp);
     }
     else{
         ans1.push_back(-1);
     }


    if(x2!=p1)
    {
        ans2 = solve(x2,i+1,n,dp);
    }
    else
    {
         ans2.push_back(-1);
    }

     if(ans1[0]!=-1)
     {
        ans1.push_back(2);
        return dp[p1] = ans1;
     }
     
     if(ans2[0]!=-1)
     {
        ans2.push_back(1);
        return dp[p1]= ans2;
     }

     
     return dp[p1]= ans1;


}




int main()
{
        int t;
        cin>>t;

        

    
   
    while(t--){
        long long int n;

        cin>>n;
        if(n%2==0)
        {
            cout<<-1<<endl;
        }
        else
        {
              vector<vector<int>>dp(n,vector<int>());
                vector<int>ans = solve(1,0,n,dp);

                if(ans.size()==1 && ans[0]==-1)
                {
                    cout<<-1<<endl;

                }
                else{
                        cout<<ans.size()<<endl;
                        reverse(ans.begin(),ans.end());
                        for(auto i :ans)
                        {
                            cout<<i<<" ";
                        }
                        cout<<endl;
       }

        }
      

       
    }
    
return 0;

}