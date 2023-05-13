#include<bits/stdc++.h>

using namespace std;

void bit(int n )
{
    int c=0;
     for(int i =31 ;i>=0;i--)
    {
            if((n&(1<<i))>0)                    //<--------------------logic should be known ]]]]]]]]]
                                                                        // bit magic 
            {
                c++;
                if(c==3)
                {
                    n= n&(~(1<<i));
                    c=0;
                }
                
            }
            else
            {
                c=0;
            }   

    }

    for(int i =31 ;i>=0;i--)
    {
         cout<<((n&(1<<i))>0?1:0)<<"";

    }
    cout<<endl;
}

int main()
{
    int n;
    n=135;
    bit(n);
    return 0;
}

/*
    Given an non-negative integer n. You are only allowed to make set bit unset. 
    You have to find the maximum possible value of query so that after performing
    the given operations, no three consecutive bits of the integer query are set-bits. 


    input:
    n = 7
    Output: 
    6
    Explanation: 
    7's binary form is .....00111.We can observe that 3
    consecutive bits are set bits. This is not allowed.
    So, we can perfrom the operation of changing set 
    bit to unset bit. Now, the number 
    becomes 6 that is .....00110. It satifies the 
    given condition. Hence, the maximum possible 
    value is 6.

*/