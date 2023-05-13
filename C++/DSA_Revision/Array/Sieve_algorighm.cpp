#include<bits/stdc++.h>
using namespace std;

// concept of sieve algorithm is used 



class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
       // sort(arr.begin(),arr.end());
        int p = *max_element(arr.begin(),arr.end());
        vector<bool>is(n,0);
         vector<int>mp(p+1,0);
        for(int i= 0;i<n;i++)
        {
            int j = arr[i];
            int k =i;
          if(mp[j]<2)
          {
            for(;j<=p;j+=arr[i])
            {
                mp[j]++;
            }
            
          }
           
            
            
        }
        
        int c=0;
        for(int i =0;i<n;i++)
        {
            if(mp[arr[i]]>1)
            {
                c++;
            }
        }
        return c;
    }
};


/*

    You are given an array arr[ ] of size N consisting of only positive integers. 
    Your task is to find the count of special numbers in the array. A number  is 
    said to be a special number if it is  divisible by at  least 1 other element 
    of the array.


Input:
N = 3
arr[] = {2, 3, 6}
Output:
1
Explanation:
The number 6 is the only special number in the
array as it is divisible by the array elements 2 
and 3. Hence, the answer is 1 in this case.


*/