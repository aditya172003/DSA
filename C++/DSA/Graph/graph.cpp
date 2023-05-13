#include<bits/stdc++.h>
using namespace std;


class Graph
{   // this is used as adjacency list ........................................ representation of graph 
    unordered_map<int,vector<int>>adj_l;

    public:

    void Add_edge(int u,int v,bool direction)
    {
        adj_l[u].push_back(v);

        // if graph is undirected then add u in the list of v also 

        if(direction ==0)
        {
            adj_l[v].push_back(u);
        }

    }

    void print()
    {
        for(auto i :adj_l)
        {
            for(auto j :i.second)
            {
                cout<<i.first<<" --> "<<j<<endl;
            }
        }
    }


    void create_graph()
    {
        cout<<"Enter the two nodes who has an edge "<<endl;
        int u,v;
        cout<<"To stop enter -1"<<endl;

        while(true)
        {
            cin>>u>>v;
            if(u==-1 |v==-1)
            {
                return;
            }
            Add_edge(u,v,false);

        }
    }


    void BFS_traversal()
    {
        map<int,bool>visited;
        queue<int>q;
        for(int i =0 ;i<adj_l.size();i++)
        {
            visited[i]=false;
        }

        q.push(0);
        visited[0]=true;
        while(!q.empty())
        {
            int front_node=q.front();
            q.pop();

            cout<<front_node<<" ";

            for(int i =0; i<adj_l[front_node].size();i++)
            {
                if(!visited[adj_l[front_node][i]])
                {
                       q.push(adj_l[front_node][i]);
                       visited[adj_l[front_node][i]]=true;
                }
            }
        }
    }
};

int main()
{
        Graph g1;
        g1.create_graph();
        g1.print();
        g1.BFS_traversal();

        return 0;
}