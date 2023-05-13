#include<bits/stdc++.h>
using namespace std;

int max_bst(vector<int>&ans,node*p)
{
    if(p->left==NULL && p->right==NULL)
    {
        return 1;

    }
    
    int l =max_bst(ans,p->left);
    int r = max_bst(ans,p->right);

    if(p->left && p->right)
    {
        int ld=p->left->data;
        int rd=p->right->data;

        if(ld<p->data && rd>p->data)
        {
            return l+r+1;
        }

        
    }

    if(p->left && p->data>p->left->data)
    {
         return l+1;

    }
   if(p->right && p->data>p->right->data)
    {
         return r+1;

    }
    
    ans.push_back(max(l,r));

    return 0;

}