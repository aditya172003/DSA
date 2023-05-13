#include<bits/stdc++.h>
using namespace std;




vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// creating adacency list 

    unordered_map<int,vector<int>>adj_l;

    for(int  i =0;i<m;i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adj_l[u].push_back(v);
        adj_l[v].push_back(u);

    }


    // parent vector 


	
   vector<int>parent(n,0);
    

    

    // visited array


    vector<int>visited(n,false);


    //queue 


    queue<int>q;
	q.push(s);
    visited[s]=true;
	parent[s]=-1;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(auto i : adj_l[front])
        {
            if(!visited[i])
            {
                visited[i]=true;
                parent[i]=front;
                q.push(i);
            }
        } 
    }

    //trace parent 

    
    int z=t;
    vector<int>ans;
    ans.push_back(t);
    while(z!=s)
    {
        z=parent[z];
        ans.push_back(z);
    }
   

    //return array
    
    reverse(ans.begin(),ans.end());
    return ans;
	
	
}
