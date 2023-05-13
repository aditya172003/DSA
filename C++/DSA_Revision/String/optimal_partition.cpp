#include<bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/optimal-partition-of-string/


class Solution {
public:

   
    int partitionString(string s) {
      


      unordered_set<char>st;
      int count=0;

      for(int i =0;i<s.length();i++)
      {
          if(st.find(s[i])!=st.end())
          {
              count++;
              st.clear();
          }
          st.insert(s[i]);
      }

      return count+1;
    }
};