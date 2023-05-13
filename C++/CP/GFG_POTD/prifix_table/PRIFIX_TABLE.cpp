 #include<bits/stdc++.h>
 using namespace std;

 
 
 vector<int> solveQueries(int n, int num, vector<int> &A, vector<vector<int>> &Q)
    {
       vector<int>count(n,0);
       for(int i =0;i<n;i++)
       {
           int c=1;
           for(int j=i+1;j<n;j++)
           {
               if(A[j]==A[i])
               {
                   c++;
               }
           }
           count[i]=c;
       }
       
       vector<int>ans;
       for(int i =0;i<num;i++)
       {
           int l =Q[i][0];
           int r =Q[i][1];
           int k =Q[i][2];
            int c=0;
           for(int i=l;i<=r;i++)
           {
              
               if(count[i]==k)
               {
                  
                  c++;
               }
               
           }
           ans.push_back(c);
           
       }
       
       return ans;
    }



    /*


        You are given an array of N elements and num queries, In each query you are given 
    three numbers L,R and K and you have to tell, how many indexes are there in between
    L and R(L<=i<=R) such that the frequency of a[i] from index i to n-1 is k.

        Input:
        N=5
        num=3
        A={1,1,3,4,3}
        Q={{0,2,2},{0,2,1},{0,4,2}}
        Output:
        2 1 2
        Explanation:
        For query 1: 0 2 2
        L=0,R=2,K=2
        let, L<=i<=R
        For i=0: frequency of a[i] i.e. 1 from i to n-1 is 2.
        For i=1: frequency of a[i] i.e. 1 from i to n-1 is 1.
        For i=2: frequency of a[i] i.e. 3 from i to n-1 is 2.
        Hence we have two elements from index 0 to 2 
        whose frequency from i to n-1 is 2.

        For query 2: 0 2 1
        L=0,R=2,K=1
        As we can see from the above query that there is 
        only a single element in 0 to 2 whose frequency 
        from i to n-1 is 1.

        For query 3: 0 4 2
        The answer will be 2 because of the index 0 and 2
    
    */