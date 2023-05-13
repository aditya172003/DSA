#include<bits/stdc++.h>
using namespace std;

// Reason of TLE is we are using the unordered map 
// in this question we have used the vector insted of unordered map in the visited structure 

void DFS(unordered_map<int,vector<int>>&adj_l,vector<bool>&visited,int src,stack<int>&ans)
{
  visited[src]=true;
  for(auto i : adj_l[src])
  {
    if(!visited[i])
    {
        DFS(adj_l,visited,i,ans);
        
    }
  }
   ans.push(src);
  
}



vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,vector<int>>adj_l;
    vector<bool>visited(v);
    stack<int>ans;

    for(int i =0;i<e;i++)
    {
             int u1=edges[i][0];
             int v1=edges[i][1];

             adj_l[u1].push_back(v1);


    }

     for(int i =0;i>v;i++)
     {
         visited[i]=false;
     }
    vector<int>ansf;

    for(int i =0;i<v;i++)
    {
        if(!visited[i])
        {
            DFS(adj_l,visited,i,ans);

        }

    }

    while(!ans.empty())
    {
        ansf.push_back(ans.top());
        ans.pop();
    }



return ansf;
}



// Kahn's algorithm 


// it uses the bfs for finding the topological sort ................

// indegree_vector is used 

// 1 ] find adjacency list
// 2 ] indegree vector 
// 3 ] push vertex into q if its indegree is equal to 0 
// 4 ] pop from queue 
// 5 ] decrement the degree of the connected vertex of the popped vertex 
// 6 ] if indegree ==0 push it in to the queue 
// 7 ] push popped vertex into the ans vector 