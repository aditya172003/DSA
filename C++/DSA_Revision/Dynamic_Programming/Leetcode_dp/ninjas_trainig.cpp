#include<bits/stdc++.h>

using namespace std;

// ninjas training 

// similar to color problem

// here we have only 3 
/*
    if we have k then to get max element 
    in an array 
    do one thing is that find 1 max and 2 nd max elelment from the array 

    if (index of max == index of current )
    {
        then take max as 2 nd max 
    }
    else
    {
        take max as 1st max 
    }

    thats only difference in the 3 points and k points 
*/


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>prev(3);

    for(int i =0;i<3;i++)
    {
        prev[i] = points[0][i];
    }


    for(int i =1;i<n;i++)
    {
        vector<int>curr(3);
        curr[0]=points[i][0]+max(prev[1],prev[2]);
        curr[1]=points[i][1]+max(prev[0],prev[2]);
        curr[2]=points[i][2]+max(prev[1],prev[0]);

        prev=curr;

    }


    return *max_element(prev.begin(),prev.end());
}