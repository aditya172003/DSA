#include<bits/stdc++.h>
using namespace std ;


// simple bfs traversal

 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>ans;
        
        vector<int>v(V,0);
        
        queue<int>q;
        q.push(0);
        v[0]=1;
        
        while(!q.empty())
        {
            int i = q.front();
            ans.push_back(i);
            q.pop();
            for(auto k : adj[i])
            {
                if(v[k]!=1)
                {
                    v[k]=1;
                    q.push(k);
                }
            }
        }
        return ans;
        
    }



    // it is the shortest path in undirected graph 

void bfs()
{

vector<vector<int>> adj;  // adjacency list representation
int n; // number of nodes
int s; // source vertex

queue<int> q;
vector<bool> used(n);
vector<int> d(n), p(n);

q.push(s);
used[s] = true;
p[s] = -1;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (!used[u]) {
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            p[u] = v;
        }
    }
}
}

// bfs for matrix 

  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
     
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                    distance[i][j]=0;
                }
            }
        }
       

        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        while(q.empty()==false){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            distance[r][c]=d;
           
            for(int i=0;i<4;i++){
                int nrow=r+delRow[i];
                int ncol=c+delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]!=2 ){
                    visited[nrow][ncol]=2;
                    q.push({{nrow,ncol},d+1});

                }
            }


        }
        return distance;


    }