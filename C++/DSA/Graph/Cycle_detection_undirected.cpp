    #include<bits/stdc++.h>

    using namespace std;

    // same like bfs just parent data structure is added and if condition is also added 

    bool isCycle(unordered_map<int,list<int>>&adj_l,unordered_map<int,bool>&visited,unordered_map<int,int>&parent,int src)
    {
        visited[src]=true;
        parent[src]=-1;
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            int f=q.front();
            q.pop();

            for(auto i :adj_l[f])
            {
                   if(visited[i] && parent[i]!=f)
                   {
                    return true;
                   }
                   else if(!visited[i])
                   {
                     q.push(i);
                     visited[i]=true;
                     parent[i]=f;
                   }
            }

        }

        return false;
    }



string CycleDetection(vector<vector<int>>edges,int n,int m)
{
   unordered_map<int,list<int>>adj_l;
   unordered_map<int,bool>visited;
   unordered_map<int,int>parent;
   bool ans=false;
   for(int i =0;i<m;i++)
   {
    int u=edges[i][0];
    int v=edges[i][1];
    adj_l[u].push_back(v);
    adj_l[v].push_back(u);

   }

   for(int i =0;i<n;i++)
   {
    visited[i]=false;
   }

   for(int i =0;i<n;i++)
   {
    if(!visited[i])
    {
      ans=  isCycle(adj_l,visited,parent,i);
      if(ans)
      {
        return "YES";
      }
    } 
   }

return "NO";
}