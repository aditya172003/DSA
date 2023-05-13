#include<bits/stdc++.h>
using namespace std;


struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};





class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        Node*p=head;
        Node*q=head;
      
        
     
        map<char,int>mp;
        for(int i =0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        
        int c=0;
        vector<Node*>ans;
        while(p)
        {
            char ch = p->data;
            if(mp.find(ch)!=mp.end()&& mp[ch]!=0)
            {
                c++;
                mp[ch]--;
                if(c==s.length())
                {
                    ans.push_back(q);
                    q=p;
                    c=0;
                    p=p->next;
                    q->next=NULL;
                    q=p;
                     for(int i =0;i<s.length();i++)
                     {
                        mp[s[i]]++;
                     }
        
                }else
                {
                    
                     p=p->next;
                }
            }
            else
            {
                for(int i =0;i<s.length();i++)
                {
                        mp[s[i]]=0;
                }
                for(int i =0;i<s.length();i++)
                {
                        mp[s[i]]++;
                }
                p=q->next;
                q=p;
                c=0;
            }
            
        }
        
        return ans;
        // code here
    }
};



/*
Given a linked list of characters and a string S.Return all the anagrams of the string present 
in the given linked list.In case of overlapping anagrams choose the first anagram from left.

        Input: a -> b -> c -> a -> d -> b -> c -> a
        S = bac

        Output: [a -> b -> c, b -> c -> a]

        
        Explanation: In the given linked list,
        there are three anagrams: 
        1. a -> b -> c -> a -> d -> b -> c -> a
        2. a -> b -> c -> a -> d -> b -> c -> a
        3. a -> b -> c -> a -> d -> b -> c -> a
        But in 1 and 2, a -> b -> c and b -> c-> a
        are ovelapping.So we take a -> b -> c as it
        comes first from left.So the output is:
        [a->b->c,b->c->a]

*/