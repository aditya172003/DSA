#include<bits/stdc++.h>
using namespace std;



struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



class Solution
{
public:
   
    Node *reverse(Node *head, int k)
    {
       Node*curr= head;
       Node*prev= NULL;
       Node*ford= NULL;
       Node*p   = head;
       
       for(int i =0 ;i<k;i++)
       {
           p=p->next;
       }
       
       
       
       while(curr)
       {
           ford = curr->next;
          
           curr->next=prev;
           prev= curr;
          
           curr=ford;
           
           
       }
       
      head->next = prev;
      head= p->next;
      p->next=NULL;
      //cout<<p->data<<" "<<p->next->data<<" "<<prev->data<<" "<<head->data<<endl;
      p->next=NULL;
      
      return head;
    }
};