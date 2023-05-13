#include<bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/



class Solution {
public:


    int lengthOfLongestSubstring(string s) {
       
        unordered_set<char>st;
        int c =0;
        int cf=0;
        int n = s.length();
        int k=-1;
        for(int i =0;i<n;i++)
        {

            if(st.find(s[i])==st.end())
            {
                if(k==-1)k=i;
                cf++;
                st.insert(s[i]);
            }
            else
            {
                c = max(c,cf);
                st.clear();
                cf=0;
                i=k;
                k=-1;
            }
        }
        c=max(cf,c);

        return c;
    }
};