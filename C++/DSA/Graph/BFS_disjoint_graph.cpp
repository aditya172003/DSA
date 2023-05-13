#include<bits/stdc++.h>

using namespace std;



// solution is correct but tle  ....error time limit exceeds


// tle removed by removing the calls of below function 
    
void adjacency_list(int node, vector<pair<int, int>> &edges,  unordered_map<int,set<int>>&adj_l)
{
    
     for(int i=0;i<edges.size();i++)
     {
         int u=edges[i].first;
         int v=edges[i].second;
     
         adj_l[u].insert(v);
         adj_l[v].insert(u);
        
     }
}

void bfs(vector<int>&ans,unordered_map<int,set<int>>&adj_l,int node, map<int,bool>&visited)
    
{
    queue<int>q;
    q.push(node);
    visited[node]=true;
    
    while(!q.empty())
    {
        int front_node=q.front();
        q.pop();
        ans.push_back(front_node);
        for(auto i :adj_l[front_node])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
            
    }
}


// for disjoint graph 

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{   
    unordered_map<int,set<int>>adj_l;
     for(int i=0;i<edges.size();i++)
     {
         int u=edges[i].first;
         int v=edges[i].second;
     
         adj_l[u].insert(v);
         adj_l[v].insert(u);
        
     }
    vector<int>ans;
    map<int,bool>visited;
    for(int i=0;i<vertex;i++)
    {
        visited[i]=false;
    }
   // adjacency_list(vertex,edges,adj_l); 
    
    for(int i =0;i<vertex;i++)
    {    
        if(!visited[i])
       {
           bfs(ans,adj_l,i,visited);
       }
            
    }

    return ans;
    // Write your code here
}