#include<bits/stdc++.h>

using namespace std;
const int MAX=1e+7;
int dp[MAX];

// top down approach 

// memorization
int fibonacci_number(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n]=fibonacci_number(n-1)+fibonacci_number(n-2);
    return dp[n];
}

// bottom up approach 
// tabulation method 
int tabulation(int n,int *tb)
{
    // 1 ]
    tb[0]=0;
    tb[1]=1;

    // 2 ]
    for(int i = 2 ;i<=n;i++)
    {
        tb[i]=tb[i-1]+tb[i-2];
    }

    // 3 ]
    return tb[n];
}


int main()

{

for(int i =0;i<MAX;i++)
{
    dp[i]=-1;
}

cout<<fibonacci_number(7)<<endl;
cout<<fibonacci_number(8)<<endl;
cout<<fibonacci_number(9)<<endl;
cout<<fibonacci_number(10)<<endl;


int tab[100000];
cout<<tabulation(7,tab)<<endl;
cout<<tabulation(8,tab)<<endl;
cout<<tabulation(9,tab)<<endl;
cout<<tabulation(10,tab)<<endl;


return 0;
}