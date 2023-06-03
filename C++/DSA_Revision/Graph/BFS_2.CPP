#include<bits/stdc++.h>
using namespace std ;



//https://leetcode.com/problems/time-needed-to-inform-all-employees/description/



// nice question to revise the bfs use and why not dfs and all 

// one of the real time application of graph bfs traversal 

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& it) {
        map<int,vector<int>>mp;
        for(int i =0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                mp[manager[i]].push_back(i);
            }
        }


        queue<pair<int,int>>q;
        q.push({headID,0});

        int t=0;
        int ans =0;
        while(!q.empty())
        {   int s =q.size();
            while(s--)
            {
                 auto j =q.front();
                 q.pop();
                 t=j.second+it[j.first];
                ans = max(ans,t);
                for(auto i : mp[j.first])
                {
                        q.push({i,t});
                }
            }
           


        }

        return ans;

    }
};