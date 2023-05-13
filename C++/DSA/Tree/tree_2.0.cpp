#include <bits/stdc++.h>

using namespace std;

class node
{
private:
    int data;
    node *left;
    node *right;

public:
    node()
    {
        left = NULL;
        right = NULL;
    }

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
    friend class Tree;
};

class Tree
{
    node *root;

public:
    Tree()
    {
        root = NULL;
    }

    // 1 ] create function iterative   .... queue is used it is level order insertion

    void create()
    {
        int t;
        cout << "Enter the data in the root node :" << endl;
        cin >> t;
        root = new node(t);

        // declear the queue
        queue<node *> q;

        q.push(root);

        while (!q.empty())
        {
            node *p = q.front();
            q.pop();

            cout << "Enter the data in the left node of " << p->data << endl;
            cin >> t;
            if (t != -1)
            {
                p->left = new node(t);
                q.push(p->left);
            }
            cout << "Enter the data in the right node of " << p->data << endl;
            cin >> t;
            if (t != -1)
            {
                p->right = new node(t);
                q.push(p->right);
            }
        }
    } // end of create iter function

    // 2 ]  create recursive function ............... recursion

    node *create_rec()
    {
        int t;

        cout << "Enter the data in the node " << endl;
        cin >> t;
        node *p = new node(t);
        // base case condition
        if (t == -1)
        {
            return NULL;
        }
        p = new node(t);

        cout << "Enter the data in the left of " << p->data << endl;
        p->left = create_rec();
        cout << "Enter the data in  the right of " << p->data << endl;
        p->right = create_rec();

        return p;
    }

    void create_recursive()
    {
        root = create_rec();
    }

    // end of create recursive function  ............................................................



    // traversals of tree

    // 3 ] [1] level order traversal ...................... queue is used here

    void Level_order()
    {

        queue<node*> q;
        node *p = root;
        q.push(p);
        q.push(NULL);
        while (!q.empty())
        {
            node *t = q.front();
            q.pop();

            if (t == NULL)
            {
                cout << endl;

                if (!q.empty())
                {
                    q.push(NULL);
                }
            
            }
            else
            {
                cout<<t->data<<" ";
                if(t->left)
                {
                    q.push(t->left);

                }
                if(t->right)
                {
                    q.push(t->right);
                }
            }
        }
    }  // end of level order traversal............................................................



    // 4 ] [2] inorder recursive traversal 


    
};

int main()
{
    Tree t1;
    //t1.create();
    t1.create_recursive();
    t1.Level_order();
}