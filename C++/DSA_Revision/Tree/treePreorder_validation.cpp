#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/submissions/921485524/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream s(preorder);

        
        int c=1;
        string str;
        while(getline(s,str,','))
        {

            c--;
            if(c<0)return false;
            if(str!="#")
            {
                c+=2;
            }
           
            
        }

       

        return c==0;
    }
};