#include<bits/stdc++.h>
using namespace std;


// dfs for creating topological sort stack

void DFS (stack<int>&topo_s,unordered_map<int,vector<pair<int,int>>>&adj_l,int src,vector<bool>&visited)
{
    visited[src]=true;
    for(auto i :adj_l[src])
    {
        if(!visited[i.first])
        {
            DFS(topo_s,adj_l,i.first,visited);
        }
    }

    topo_s.push(src);
}

// adjacency list is littlebit different .........................
                            // u        v   w
void adjcency_list(vector<pair<int,pair<int,int>>>&edges,int n,int m,unordered_map<int,vector<pair<int,int>>>&adj_l)
{
    for(int i =0;i<m;i++)
    {
        int u = edges[i].first;
        int v = edges[i].second.first;
        int weight = edges[i].second.second;

        pair<int,int>p = make_pair(v,weight);
        adj_l[u].push_back(p);
        
    }
}


int shortest_path(vector<pair<int,pair<int,int>>>&edges,int n,int m,int source,int dest)
{
    // adjacency list 
     unordered_map<int,vector<pair<int,int>>>adj_l;
     adjcency_list(edges,n,m,adj_l);

    // visited
    vector<bool>visited(n,false);


    // topological sort stack 
    stack<int>topo_s;
    for(int i =0;i<n;i++)
    {
        if(!visited[i])
        {
            DFS(topo_s,adj_l,i,visited);
        }
    }

    // distance vector

    vector<int>dist(n,INT_MAX);
    dist[source]=0;
    while(!topo_s.empty())
    {
        int node =topo_s.top();
        topo_s.pop();
        if(dist[node]!=INT_MAX)
        {
            for(auto i :adj_l[node])
            {
                int old_dist=dist[i.first];
                int new_dist=dist[node]+i.second;

                if(old_dist>new_dist)
                {
                    dist[i.first]=new_dist;
                }
            }
        }
        

    }

    return dist[dest];

}




