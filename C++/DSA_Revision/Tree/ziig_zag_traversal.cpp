#include<bits/stdc++.h>
using namespace std;


#include<bits/stdc++.h>
using namespace std;


// BASIC TERMANOLOGY OF THE TREE
class Node
{
    public:
    int data;
    Node*left;
    Node*right;
    public:
    Node()
    {
        left  =NULL;
        right =NULL;
    }
    Node(int t)
    {
        data  = t;
        left  =NULL;
        right =NULL;
    }

    friend class Tree;

};

Node*root;

vector<int>zigzag()
{
    Node*p=root;
    queue<Node*>q;

    q.push(p);
    int i=0;
    bool left =true;
    vector<int>ans;
    while(!q.empty())
    {

        int size = q.size();
        vector<int>v(size);

        for(int i=0;i<size;i++)
        {
            p=q.front();
            q.pop();
            int ind = left?i:size-1-i;
            v[ind]  = p->data;  

            if(p->left)
            {
                q.push(p->left);
            }
            if(p->right)q.push(p->right);
        }

        for(auto i :v)
        {
            ans.push_back(i);
        }

       left=!left;

    }

    return ans;

}