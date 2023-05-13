#include <bits/stdc++.h> 

using namespace std;

// correct code for dijkstra's algorithm 

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //  adjacency list 
    //             u        v  dist
    unordered_map<int,vector<pair<int,int>>>adj_l;
    
    for(int i =0;i<edges;i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj_l[u].push_back(make_pair(v,w));
        adj_l[v].push_back(make_pair(u,w));
 
    }




    // distance array 

    vector<int>dist(vertices , INT_MAX);


    // set 
    //       pair<dist,vertice>  
    set<pair<int,int>>s;
    dist[source]=0;
    s.insert(make_pair(0,source));
    
    while(s.size()!=0)
    {   
       
        pair<int,int>p= *s.begin();
        s.erase(s.begin());

        int dist_d = p.first;
             int v = p.second;
          
        for(auto i :adj_l[v])
        {
            int old_d = dist[i.first];
            int new_d = dist_d+i.second;

            if(old_d>new_d)
            {   
                //update old distance 
                dist[i.first]=new_d;

                // here was the mistake

                // erase the record if exist 

                if(s.find({dist[i.first],i.first})!=s.end())
                {
                    s.erase(s.find({dist[i.first],i.first}));
                }
               // insert the updated record 
                s.insert(make_pair(new_d,i.first));

            }
        }


    }

    return dist;
}


