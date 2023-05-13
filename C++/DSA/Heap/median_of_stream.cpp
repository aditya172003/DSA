#include<bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;

    vector<int>vec;
    
    for(auto i :vec)
    {
        maxh.push(i);
        minh.push(i);
        if(minh.size()%2==0)
        {
            vec.push_back((minh.top()+maxh.top())/2);
        }
        else
        {
            vec.push_back(maxh.top());
        }
    }
   // if you want to find median of unsorted array
    // int i=0;
    // int j=max(minh.size(),maxh.size());
    // while(i<=j)
    // {  
    //     i++;
    //     j--;
    //     if(i>=j)
    //     {
    //         break;
    //     }
    //     minh.pop(),maxh.pop();
        
    // }




}