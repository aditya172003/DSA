#include<bits/stdc++.h>


// solved but one testcase fail .....
using namespace std;

void paths( vector<vector<int>>&visit,vector<vector<int>>can,int i ,int j,int n,vector<string>&ans,string &path)
{
    if(i==n-1 && j==n-1)
    {
          ans.push_back(path);
          path="";
          return;
    }

    if(i>-n |j>=n |i<=0|j<=0)
    {
        return ;
    }


    visit[i][j]=1;

    if(can[i][j+1]==1 && visit[i][j+1]==0)
    {
        path=path+'R';
        paths(visit,can,i,j+1,n,ans,path);
    }

    if(can[i][j-1]==1 && visit[i][j-1]==0)
    {
        path=path+'L';
        paths(visit,can,i-1,j,n,ans,path);
    }
    
    if(can[i-1][j]==1 && visit[i-1][j]==0)
    {
        path=path+'U';
        paths(visit,can,i-1,j,n,ans,path);
    }


    if(can[i+1][j]==1 && visit[i+1][j]==0)
    {
        path=path+'D';
        paths(visit,can,i+1,j,n,ans,path);
    }


   visit[i][j]=0;
}



int main()
{

    int n;
    vector<vector<int>>vec;

    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            vec[i][j]=0;
        }
    }
}