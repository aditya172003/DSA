#include<bits/stdc++.h>
using namespace std;



// BASIC TERMANOLOGY OF THE TREE
class Node
{
    private:
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

class Tree
{

            private:
            Node*root ;
            public:
            Tree()
            {
                root =NULL;
            }
    //................................................................................................
    // creating tree using recursive function
            Node*C_t()
            {
                int d;
                cout<<"Enter the data"<<endl;
                cin>>d;
                if(d==-1)
                {
                    return NULL;

                }
                Node*q= new Node(d);
                cout<<"Left _ data of tree"<<d<<endl;
                q->left  =C_t();
                cout<<"right _data of tree"<<d<<endl;
                q->right =C_t();

                return q;

            }

            void CreateRecursive()
            {
                root = C_t();
            }

    //..........................................................................................
    //..........................................................................................

    // using iterative method using queue 
    //----------------------------------------------------------------------------------------------
            void createIterariv()
            {                                                                        // level-order creation    
                int d;
                Node*p;
                queue<Node*>q;
                cout<<"Enter the data in the head"<<endl;
                cin>>d;
                root = new Node(d);
                q.push(root);
                while(!q.empty())
                {
                    p= q.front();
                    q.pop();
                    cout<<"Enter the data to the left of "<<p->data<<endl;
                    cin>>d;
                    if(d!=-1)
                    {
                        p->left =new Node(d);
                        q.push(p->left);
                    }
                

                    cout<<"Enter the data to the righ of "<<p->data<<endl;
                    cin>>d;
                    if(d!=-1)
                    {
                        p->right = new Node(d);
                        q.push(p->right);
                    }
                

                }
            }
    //=------------------------------------------------------------------------------------------------------------
    //=============================================================================================================



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

    // Height of the binary tree

    int height_T(Node*p)
    {
        if(p==NULL) return 0;
        
        int x = height_T(p->left);
        int y = height_T(p->right);

        return (x>y)?x+1: y+1;
    }

    int Height_of_tree()
    {
        return height_T(root);
    }

    pair<int,int>Di(Node*p)
    {
        if(p==NULL)
        {
            return {0,0};
        }

         pair<int,int>p1,p2;

         p1 = Di(p->left);
         p2 = Di(p->right);

         pair<int,int>ans;
        
        ans.first  =(p1.first>p2.first )? p1.first+1:p2.first+1;

        ans.second =max((p1.first+p2.first+1),max(p1.second,p2.second));

        return ans;
    }


    int Diameter()
    {
        pair<int,int >ans = Di(root);
        return ans.second;
    }




    // balanced height of the tree

    pair<int,bool>  bal_h(Node*p)

    {
        if(p==NULL){
            return {0,true};

        }

        pair<int,bool>p1,p2,ans;

        p1= bal_h(p->left);
        p2 = bal_h(p->right);

        ans.first = (p1.first>p2.first)?p1.first+1 : p2.first+1;

        if((abs(p1.first-p2.first)>1))
        {
            ans.second= false;
            return ans;
        }

        ans.second = p1.second&p2.second;
        return ans;

    }

    bool isBalanced_Height()
    {
        pair<int,bool>pr = bal_h(root);
        return pr.second;
    }

    // Mirror of the tree

    Node*Swap(Node*p)
    {
        if(p==NULL)
        {
            return NULL;
        }
        Node*temp = p->left;
        p->left = Swap(p->right);
        p->right= Swap(temp);
        return p;
    }


    void Mirror()
    {
        root= Swap(root);
    }


    pair<int,bool>isSum(Node*p)
    {
        if(p==NULL)
        {
            return {0,true};
        }

        pair<int,bool> x = isSum(p->left);
        pair<int,bool> y = isSum(p->right);

        pair<int,bool>ans;
        ans.first = p->data;

        if(p->data == x.first+y.first )
        {
            ans.second=true&&x.second&&y.second;
        }
        else
        {
            ans.second = false;

        }
        return ans;

    }

    bool isSumTree()
    {
        return isSum(root).second;
    }
};


int main()
{
    Tree t1;
    //t1.CreateRecursive();
    t1.createIterariv();
    t1.Level_order_traversal();

    // Traversals 

    // t1.Inorder_Traversal();
    // t1.inorderRecursive();
    // t1.Preorder_Traversal();
    // t1.preorderIterative();

    // t1.postorderRecursive();
    // t1.postorderIterative();

    // HEIGHT OF THE TREE
    cout<<"Height of the tree"<<endl;
    cout<<t1.Height_of_tree()<<endl;

    //DIAMETER
    cout<<"Diameter of tree"<<endl;
    cout<<t1.Diameter()<<endl;
}