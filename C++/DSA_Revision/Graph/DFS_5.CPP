#include<bits/stdc++.h>
using namespace std ;


//https://leetcode.com/problems/detonate-the-maximum-bombs/description/

// dont consider always what you have given is considered as node keep in mind 

// here we have given the coordinates of the bomb we can consider them as a node number 
// from 0 ----> bomb,size();


// little bit different 




class Solution {
public:

    void f(int p,map<int,vector<int>>&mp,vector<int>&v)

    {
        int ans =1;

        v[p]=1;

        for(auto i : mp[p])
        {
            if(v[i]==0)
            {
                f(i,mp,v);
            }
        }
        
        
    }


    int maximumDetonation(vector<vector<int>>& bombs) {
        
        map<int,vector<int>>mp;

        

        for(int  i=0;i<bombs.size();i++)
        {
            long long int u = bombs[i][0];
            long long int vr = bombs[i][1];
            long long int  r = bombs[i][2];
            pair<int,int> z = {u,vr};
           
            for(int j=0;j<bombs.size();j++)
            {
               
                if(i!=j)
                {
                    int p = bombs[j][0];
                    int q = bombs[j][1];

                    if((p-u)*(p-u)+(q-vr)*(q-vr) <=r*r)
                    {
                        mp[i].push_back(j);
                        // mp[{p,q}].push_back(z);
                    }
                
                }
                   
            }

        }

        int ans=0;
        for(int i =0;i<bombs.size();i++)
        {vector<int>v(bombs.size(),0);

            if(v[i]==0)
            {
                    f(i,mp,v);
            }
            int a=0;
            for(auto j : v)if(j)a++;
            ans=max(ans,a);
        }

        
        return ans;
    }
};