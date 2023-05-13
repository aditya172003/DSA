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

    // traversals in binary tree 

    //============================
    //----------------------------





    // 1 ] level order Traveral 
    

            void Level_order_traversal()
            {
                Node*p;

                queue<Node*>q;

                q.push(root);
                q.push(NULL);

                while(!q.empty())
                {
                    p = q.front();
                    q.pop();
                    if(p==NULL)
                    {
                        cout<<endl;
                        if(!q.empty())
                        {
                            q.push(NULL);
                        }
                    }
                    else
                    {
                        
                            cout<<p->data<<" ";

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
                 cout<<endl;

            }

            //  reverse level orde 
                                                       
            vector<int> reverseLevelOrder(Node *root) 
            {   
                vector<int>ans;
                stack<int>st;
                queue<Node*>q;
                q.push(root);
                Node*p;
                while(!q.empty())
                {
                    p=q.front();
                    q.pop();
                    
                    st.push(p->data);
                    if(p->right)
                    {
                        q.push(p->right);
                        
                    }
                    
                    if(p->left)
                    {
                        q.push(p->left);
                    }
                }
                
                while(!st.empty())
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                
                return ans;
                // code here
            }
    //-----------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------

    // 2]  Inorder traversal

         // 1 ] using recursion 

         void Inord_T(Node*p)
         {
            if(p==NULL)
            {
                return ;
            }

            Inord_T(p->left);
            cout<<p->data<<" ";
            Inord_T(p->right);
         }

         void inorderRecursive()
         {
            Inord_T(root);
            cout<<endl;
         }

         // 2 ] Iterative inorder traversal

         void Inorder_Traversal()
         {
            Node*p=root;
            stack<Node*>st;

        
            while(!st.empty() || p!=NULL)
            {
                if(p!=NULL)
                {
                   st.push(p);
                   p=p->left;
                   
                }
                else
                {

                    p = st.top();
                    st.pop();
                    cout<<p->data<<" ";
                    p=p->right;

                }
            }
             cout<<endl;
         }

         // ---------------------------------------------------------------------------------------------------



         // 3 ] Preorder Traversal 

            // 1 ] recurive preorder 

            void Preord_T(Node*p)
            {   
                if(p==NULL)
                {
                    return;
                }

                cout<<p->data<<" ";
                Preord_T(p->left);
                Preord_T(p->right); 

            }

            void Preorder_Traversal()
            {
                Preord_T(root);
                cout<<endl;
            }

            // 2 ] iterative preorder traversal


            void preorderIterative()
            {
                Node*p;
                stack<Node*>st;
                p=root;
                while(!st.empty()||p!=NULL)
                {   
                    if(p==NULL)
                    {
                        p=st.top();
                        st.pop();
                        p=p->right;
                    }
                    else
                    {
                        cout<<p->data<<" ";
                        st.push(p);
                        p=p->left;

                    }

                }
                cout<<endl;
            }


        // 4 ] Post order traversal 


            // 1 ] recursive method 

                void Postord_T(Node*p)
                {
                    if(p==NULL)
                    {
                        return;
                    }

                    Postord_T(p->left);
                    Postord_T(p->right);
                    cout<<p->data<<" ";
                }

                void postorderRecursive()
                {
                    Postord_T(root);
                    cout<<endl;
                }
            // 2 iteraive

            void postorderIterative()
            {
                Node*p=root;
                stack<Node*>st1;
                stack<Node*>st2;
                st1.push(p);
                while(!st1.empty())
                {
                    p = st1.top();
                    st1.pop();
                    st2.push(p);

                    if(p->left)
                    {
                        st1.push(p->left);
                    }

                    if(p->right)
                    {
                        st1.push(p->right);
                    }

                }

                while(!st2.empty())
                {
                    cout<<st2.top()->data<<" ";
                    st2.pop();
                }
                cout<<endl;

                
            }

