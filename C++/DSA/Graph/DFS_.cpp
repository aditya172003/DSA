#include<bits/stdc++.h>
using namespace std;

void adjacency_list(unordered_map<int,vector<int>>&adj_l)
{
    cout<<"Enter the u and v "<<endl;
    
    int u ,v;
    while(true)
    {
        cin>>u>>v;
        if(u==-1 || v==-1)
        {
            return;
        }
        adj_l[u].push_back(v);
        adj_l[v].push_back(u);

    }
    
}

void DFS(map<int,bool>&visited,unordered_map<int,vector<int>>&adj_l,int node,vector<int>&ans)
{   
    
    
    ans.push_back(node);
    visited[node]=true;
    for(auto i : adj_l[node])
    {
        if(!visited[i])
        {   
            DFS(visited,adj_l,i,ans);
        }
    }


}

int main()
{
    unordered_map<int,vector<int>>adj_l;

    adjacency_list(adj_l);
    map<int ,bool>visited;
    vector<int>ans;
    int node=0;
    
    for(int i =0;i<adj_l.size();i++)
     {
        visited[i]=false;
     }
    visited[node]=true;
    for(int i =0;i<adj_l.size();i++)
    {
               if(!visited[i])
               {
                 DFS(visited,adj_l,i,ans);
               }
    }
   
     
    for(auto i :ans)
    {
        cout<<i<<" ";
    }
    cout<<"\n";


}



/*
// one of the question based on dfs 


Geeks Island is represented by an N * M matrix mat. The island is touched by the
Indian Ocean from the top and left edges and the Arabian Sea from the right and 
bottom edges. Each element of the matrix represents the height of the cell.
Due to the rainy season, the island receives a lot of rainfall, and the water can 
flow in four directions(up, down, left, or right) from one cell to another one with
height equal or lower.
You need to find the number of cells from where water can flow to both the Indian 
Ocean and the Arabian Sea.

*/


/*
Input:
N = 5, M = 5
mat[][] =    {{1, 3, 3, 2, 4},
               {4, 5, 6, 4, 4},
               {2, 4, 5, 3, 1},
               {6, 7, 1, 4, 5},
               {6, 1, 1, 3, 4}}
Output:
8
Explanation:
Indian    ~   ~   ~   ~   ~
Ocean  ~  1   3   3   2  (4) *
        ~  4   5  (6) (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (6)  1   1   3   4  *           
           *   *   *   *   * Arabian Sea
Water can flow to both ocean and sea from the cells
denoted by parantheses().For example at index(1,2),
t/he height of that island is 6. If a water drop falls 
on that island, water can flow to up direction(as 3<=6) 
and reach to Indian Ocean. ALso, water can flow to right 
direction(as 6>=4>=4) and reach to Arabian Sea.

*/