#include<bits/stdc++.h>
using namespace std;
/*
Given a rectangle of dimensions L x B find the minimum number (N) of
  identical squares of maximum side that can be cut out from that rectangle
  so that no residue remains in the rectangle. Also find the dimension K of that square.

    Input: L = 2, B = 4
    Output: N = 2, K = 2
    Explaination: 2 squares of 2x2 dimension.

    Input: L = 6, B = 3
    Output: N = 2, K = 3
    Explaintion: 2 squares of 3x3 dimension. 
*/
   vector<long long int> minimumSquares(long long int L, long long int B)
    {
        vector<long long int>ans(2);
           long long int G = __gcd(L,B);
           
           ans[1] = G;
           ans[0] = (L*B)/(G*G);
           
           return ans;
    }