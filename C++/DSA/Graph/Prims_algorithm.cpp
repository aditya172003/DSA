    #include<bits/stdc++.h>
    using namespace std;


// CORRECT PRIMS ALGORITHM 

    int min_(vector<int>&w,int n,vector<bool>&mst)
    {
        int k;
        int a=INT_MAX;
        for(int i =1;i<=n;i++)
        {
                if(w[i]<a && !mst[i])
                {
                    k=i;
                    a=w[i];
                }
        }

        return k;
    }

    vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
    {
        // Write your code here.
        unordered_map<int ,vector<pair<int,int>>>adj_l;
        
        for(int i =0;i<g.size();i++)
        {
            int u = g[i].first.first; 
            int v = g[i].first.second;
            int w = g[i].second;
            adj_l[u].push_back({v,w});
            adj_l[v].push_back({u,w});
        }

        // weight 
        vector<int>w(n+1,INT_MAX);

    

        // parent 
        vector<int>parent(n+1,-1);
    

        // mst
        vector<bool>mst(n+1,false); 

    vector<pair<pair<int, int>, int>>ans;
    

    // step 1 
    w[1]=0;
    int i1 =1;
   
    while(i1<=(n-1))
    {
        //step 2 
        int ind =min_(w,n,mst);
         
            mst[ind]=true;
             i1++;
            for(auto i :adj_l[ind])
            {
                int v  = i.first;
                int wt = i.second;
                // step 3 
                if(wt<w[v]&& mst[v]==false)
                {
                    parent[v]=ind;
                    w[v]=wt;
                }
                
            }
           
       

        
        
    }
    
    for(int i =2;i<=n;i++)
        {
            ans.push_back({{parent[i],i},w[i]});
        }
        
    
        sort(ans.begin(),ans.end());
    return ans;


    }
