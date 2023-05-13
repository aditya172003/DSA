#include<bits/stdc++.h>

using namespace std;


int dfs (map<int,int>&childs,map<int,vector<int>>&adj_l,int i )
{
    int ans =0;
    for(int j =0;j<adj_l[i].size();j++)
    {
        ans+=dfs(childs,adj_l,adj_l[i][j]);
    }
    childs[i]=ans;

    return (ans+1);
}

int main()
{
    map<int,vector<int>>mp;
    map<int,int>childs;
    map<int ,vector<int>>adj_l;
    queue<int> q;

    q.push(1);
    q.push(NULL);
    while(!q.empty())
    {
    
    }

   



}