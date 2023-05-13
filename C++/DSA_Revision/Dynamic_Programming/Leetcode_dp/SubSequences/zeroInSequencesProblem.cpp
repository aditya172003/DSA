#include<bits/stdc++.h>

using namespace std;

/*

    here the case of zero we  need to handle 

    https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbTc2Zno3c2NOTlRUbVBjUnZWd0ZtZkhHaGtWZ3xBQ3Jtc0trTGVja1lPcTkwNUl5YVJhRS1VMTRzdnF0RGNrbEdFUXlMMFpsSnRfb2JOZmhPLTlzTGNjS0syQ2Y4b0oxQTlnZF9JMVdpR1JiZTIxSTNtc2h2eHJlM0FFV0ZQdXpNaV9VTnJvS1NWVHhmM0EyVzRabw&q=https%3A%2F%2Fbit.ly%2F3B5JBkU&v=ZHyb-A2Mte4
*/


int solve(int i,int target,vector<int>&num,vector<vector<int>>&dp)
    {
      
      if(i==0)
      {
          if(target==0 && num[0]==0)return 2;

          if(target ==0||num[i]==target)return 1;

          return 0;
      }

       if(dp[i][target]!=-1)return dp[i][target];

        int inc = 0,exc;
       if(target>=num[i])
       {
           inc = solve(i-1,target-num[i],num,dp);
       }
           exc = solve(i-1,target,num,dp);

        
        dp[i][target]=inc+exc;

        return dp[i][target];

    }