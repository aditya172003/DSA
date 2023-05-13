#include<bits/stdc++.h>
using namespace std;


// here the different thing is that the visited map

// we have counted the nodes because some stings are similar and they are connected nice question 

//https://leetcode.com/problems/similar-string-groups/submissions/942461962/


class Solution {
public:

    bool isSimilar(string s1,string s2)
    {
        int c=0;
        for(int i =0;i<s1.length();i++)
        {

            if(s1[i]!=s2[i])
            {
                c++;
            }
        }

        if(c==2)return true;
        if(c==0)return true;
        return false;
    }

    int bfs( string s,map<string,int>&visited,map<string,vector<string>>&mp)
    {
        

        visited[s]--;
            
            int ans=0;
       
            for(int i =0;i<mp[s].size();i++){
               int c=0;
                if(visited[mp[s][i]])
                {
                    
                    bfs(mp[s][i],visited,mp);
                    ans++;
                    
                }       
            
               
                
            }
        return ans;
        
    }

    int numSimilarGroups(vector<string>& strs) {

            int n =strs.size();
             int c =0;
            map<string,vector<string>>mp;


             map<string,int>visited;
            for(int i=0;i<n;i++)
            {
                visited[strs[i]]++;
                for(int j=0;j<n;j++)
                {

                
                    if(isSimilar(strs[i],strs[j]))
                    {   
                        visited[strs[j]]++;
                        mp[strs[i]].push_back(strs[j]);

                    }

                  
                }
            }
           

           

           

            for(int i=0;i<n;i++)
            {   
                
                if(visited[strs[i]])
                {
                     if(bfs(strs[i],visited,mp))
                     {
                         c++;
                     }

                }
                
                
            }

        return c;
        
    }
};