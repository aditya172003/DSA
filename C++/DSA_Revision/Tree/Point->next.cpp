#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;

        if(root==NULL)return NULL;
        q.push(root);
       
        Node*p;
        while(!q.empty())
        {
            int s = q.size();
           
           
            for(int i =0;i<s;i++)
            {
                p=q.front();
                q.pop();
                if(i==s-1)
                {
                    p->next=NULL;
                }
                else
                {
                    p->next=q.front();
                }
                if(p->left)
                {
                    q.push(p->left);
                    
                }

                if(p->right)
                {
                    q.push(p->right);
                }

            }    
                 
          
           
           

        }

        return root;
    }


};