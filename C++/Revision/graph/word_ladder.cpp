#include<bits/stdc++.h>

using namespace std;


int wordLadder(string begin, string end, vector<string> &dict) 
{
   // set<string>st;
    unordered_set<string>st; 
    // using unordered_set over set is that time duration 
    /*
        when we use set           t= 69ms  31%
        when we use unordered set t= 43ms  91%
    */
   
    for(auto i : dict)
    {
        st.insert(i);
    }

    queue<pair<string,int>>q;
    q.push({begin,0});
    while(!q.empty())
    {
        auto s = q.front();
        q.pop();
        int n =s.first.length();
        if(s.first==end)
        {
            return s.second;
        }
        for(int i=0;i<n;i++)
        {   
            string temp = s.first;
            for(char ch ='a';ch<='z';ch++)
            {
                temp[i]=ch;
                if(st.find(temp)!=st.end())
                {
                    q.push({temp,s.second+1});
                    st.erase(temp);
                }
            }
        }
        
    }
	return -1;
}




vector<vector<string>> shortestTransitionPaths(string start, string end, vector<string>& dict)
{
    unordered_set<string>st; 
    // using unordered_set over set is that time duration 
    /*
        when we use set           t= 69ms  31%
        when we use unordered set t= 43ms  91%
    */
   
    for(auto i : dict)
    {
        st.insert(i);
    }
    vector<vector<string>>ans;
    queue<vector<string>>q;
    q.push({start});
    while(!q.empty())
    {
        auto s = q.front();
        q.pop();
        string str =*s.rbegin();
        int  n = str.length();
        if(str==end)
        {
            ans.push_back(s);
        }
        vector<string>rem;


        for(int i=0;i<n;i++)
        {   
            string temp = str;
            for(char ch ='a';ch<='z';ch++)
            {
                temp[i]=ch;
                if(st.find(temp)!=st.end())
                {
                    s.push_back(temp);
                    q.push(s);
                    s.pop_back();
                    rem.push_back(temp);
                    
                }
            }
        }
        for(auto i : rem)st.erase(i);
        
    }
	
    return ans;
}