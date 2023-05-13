#include<bits/stdc++.h>

using namespace std;


class node
{
    public:
    int data;
    int i;
    int j;
  
    node(int d,int row,int col)
    {
        data=d;
        i=row;
        j=col;
    }
};

class compare
{
   public:

   bool operator()(node*a,node*b)
   {
       return a->data>b->data;
   }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
  
    priority_queue<node*,vector<node*>,compare>pq;
    
    
     int maxi= INT_MIN;
    for(int i =0;i<k;i++)
    {
        node*p=new node(a[i][0],i,0);
        maxi=max(maxi,a[i][0]);
        pq.push(p);

    }
  
   int mini =pq.top()->data; 
   
    int smax=maxi,smin=mini;
    while(!pq.empty())
    {
           node*p =pq.top();
           pq.pop();

         
           mini=p->data;
           if((maxi-mini)<(smax-smin))
           {
               smax=maxi;
               smin=mini;
               
           }
        
        if(p->j+1<n)
        {
            maxi=max(a[p->i][p->j+1],maxi);
         
            node*q=new node(a[p->i][p->j+1],p->i,p->j+1);
            
            pq.push(q);
       }else
        {
           break;
        }
        
          
    }

    return (smax-smin +1);
 
}