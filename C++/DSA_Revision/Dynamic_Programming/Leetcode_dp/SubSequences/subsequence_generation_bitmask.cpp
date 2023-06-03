#include<bits/stdc++.h>
using namespace std ;

//https://leetcode.com/contest/biweekly-contest-105/problems/maximum-strength-of-a-group/
class Solution {
public:
    
    void sub(int i,vector<int>a ,vector<vector<int>>&seq,vector<int>&nums)
    {
        if(i>=nums.size())
        {
            seq.push_back(a);
            return;
        }
        
        
        sub(i+1,a,seq,nums);
        a.push_back(nums[i]);
        sub(i+1,a,seq,nums);
    }
    
    
    long long maxStrength(vector<int>& nums) {
        
        vector<vector<int>>dp;
        vector<int>a;
        //sub(0,a,dp,nums);
        int n =nums.size();
         
        long long ans =INT_MIN;
        for(int i=1;i<(1<<n);i++)
        {   
            long long c =1;
            for(int j=0;j<n;j++)
            {
                if((i>>j)&1)c*=nums[j];        
            }
            ans=max(ans,c);
            
        }
        
        
       
       
        return ans;
    }
};  