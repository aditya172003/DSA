#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
    Node()
    {
        left = NULL;
        right = NULL;
    }

    friend class Binary_Search_tree;
};

class Binary_Search_tree
{
private:
    Node *root;

public:
    Binary_Search_tree()
    {
        root = NULL;
    }

    Node *Insert_data(Node *p, int d)

    {
        if (p == NULL)
        {
            p = new Node(d);
            return p;
        }

        if (p->data >= d)
        {
            p->left = Insert_data(p->left, d);
        }
        else
        {
            p->right = Insert_data(p->right, d);
        }

        return p;
    }

    // inserting the node in binary search tree iterative method

    void Insert_BST(int d)

    {
        if (root == NULL)
        {
            root = new Node(d);
            return;
        }
        Node *p, *q, *r;
        p = root;

        while (p)
        {
            r = p;
            if (p->data == d)

            {
                return;
            }

            if (p->data > d)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }

        q = new Node(d);
        if (r->data > d)
        {
            r->left = q;
        }
        else
        {
            r->right = q;
        }
    }

    void create()
    {
        int d;

        while (d != -1)
        {
            cout << "Enter the data : ";
            cin >> d;
            if (d == -1)
            {
                break;
            }
            root = Insert_data(root, d);
        }
    }

    void level_order_()
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *p = q.front();
            q.pop();

            if (p == NULL)
            {
                cout << endl;
                if (!q.empty())

                {

                    q.push(NULL);
                }
            }
            else
            {
                cout << p->data << " ";
                if (p->left)
                {
                    q.push(p->left);
                }
                if (p->right)
                {
                    q.push(p->right);
                }
            }
        }
    }

    void iter_inorder()
    {
        Node *p = root;
        stack<Node *> st;
        st.push(p);
        while (!st.empty())
        {
            while (p->left)
            {
                st.push(p->left);
                p = p->left;
            }
            p = st.top();
            st.pop();
            cout << p->data << " ";

            if (p->right)
            {
                st.push(p->right);
                p = p->right;
            }
        }
        cout << endl;
    }

    void inter_preorder()
    {
        Node *p = root;

        stack<Node *> st;

        st.push(root);

        while (!st.empty())
        {
            while (p)
            {
                cout << p->data << " ";
                p = p->left;
                if (p != NULL)
                {
                    st.push(p);
                }
            }

            p = st.top();
            st.pop();
            p = p->right;
            if (p != NULL)
            {
                st.push(p);
            }
        }
        cout << endl;
    }

    bool search(Node *p, int k)
    {
        if (p == NULL)
        {
            return false;
        }
        if (p->data == k)
        {
            return true;
        }

        if (p->data > k)
        {
            return search(p->left, k);
        }
        else
        {
            return search(p->right, k);
        }
    }

    bool SearchBST(int k)
    {
        return search(root, k);
    }

    Node *minVal_BST()
    {
        Node *p = root;
        while (p->left)
        {
            p = p->left;
        }
        return p;
    }

    Node *maxVal_BST()
    {
        Node *p = root;
        while (p->right)
        {
            p = p->right;
        }
        return p;
    }

    // deletion of node in bst;

    Node *search_DEL(Node *p, int k)
    {
        if (p == NULL)
        {
            return NULL;
        }
        if (p->data == k)
        {
            return p;
        }

        if (p->data > k)
        {
            return search_DEL(p->left, k);
        }
        else
        {
            return search_DEL(p->right, k);
        }
    }

    Node *Inorder_pred(Node *p)
    {
        Node *q = p;
        q = q->left;
        while (q->right)
        {
            q = q->right;
        }
        return q;
    }

    bool is_leaf(Node *p)
    {
        if (p->left == NULL && p->right == NULL)
        {
            return true;
        }
        return false;
    }

    //................correct delete functionn

    Node *Del_BST(Node *p, int k)
    {
        if (p == NULL)
        {
            return NULL;
        }

        if (p->data == k)
        {
            // CHECK FOR CHILS
            if (is_leaf(p))
            {
                delete p;
                return NULL;
            }

            if (p->left != NULL && p->right == NULL)
            {
                Node *temp = p->left;
                delete p;
                return temp;
            }

            if (p->left == NULL && p->right != NULL)
            {
                Node *temp = p->right;
                delete p;
                return temp;
            }
            // if you have taken inorder -predicessor then p->left is used lese if
            // you have taken inorder successor then you will have to use p->right
            Node *pre = Inorder_pred(p);

            p->left = Del_BST(p->left, pre->data);
            return p;
        }
        else
        {
            if (p->data > k)

            {
                p->left = Del_BST(p->left, k);
            }
            else
            {
                p->right = Del_BST(p->right, k);
            }

            return p;
        }
    }

    void DELETE_BST(int d)
    {

        root = Del_BST(root, d);
    }

    // valid BST ............................. 1 ]

    bool isValid(Node *p, int l, int h)
    {
        if (p == NULL)
        {
            return true;
        }

        if (p->data < l || p->data > h)
        {
            return false;
        }

        return isValid(p->left, l, p->data) && isValid(p->right, p->data, h);
    }

    bool Is_Valid_BST()
    {
        return isValid(root, INT_MIN, INT_MAX);
    }

    Node *Kth_s(Node *p, int k, int &c)
    {
        if (p == NULL)
        {
            return NULL;
        }

        Node *x, *y;

        x = Kth_s(p->left, k, c);
        c++;
        if (c == k && x == NULL)
        {
            return p;
        }

        y = Kth_s(p->right, k, c);

        if (x)
        {
            return x;
        }
        else
        {
            return y;
        }
    }

    int kth_min(int k)
    {
        int c = 0;
        return Kth_s(root, k, c)->data;
    }

    int Kth_small(Node *p, int k, int &c)
    {
        if (p == NULL)
        {
            return -1;
        }

        int x = Kth_small(p->left, k, c);

        if (x == -1)
        {

            return -1;
        }

        c = c + 1;

        return Kth_small(p->right, k, c);
    }

    // lca of the two node

    Node *LCA(Node *root, Node *p, Node *q)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data > p->data && root->data > q->data)
        {
            return LCA(root->left, p, q);
        }

        if (root->data < p->data && root->data < q->data)
        {
            return LCA(root->right, p, q);
        }

        return root;
    }
    Node *LCAinaBST(Node *root, Node *P, Node *Q)
    {

        return LCA(root, P, Q);
        // Write your code here
    }


    Node*conv(Node*p)
    {
        if(p->left==NULL&& p->right==NULL)
        {
            return p;
        }

    Node*x,*y;
      x=conv(p->left);
      y=conv(p->right);

      Node*q=x;
      while(q->right)
      {
        q=q->right;
      }
      q->right=p;
      p->left=NULL;
      p->right=y;

      
      return x;


    }

    void Convert_Linked_List()
    {
        root=conv(root);
    }


    void inorder_vector(vector<Node*>&vec,Node*p)
    {
        if(p==NULL)
        {
            return;

        }


        inorder_vector(vec,p->left);
        vec.push_back(p);
        inorder_vector(vec,p->right);
    }

   
   Node*CLL(Node*p)
   {
        vector<Node*>vec;
        inorder_vector(vec,p);

       int n=vec.size();
       for(int i =0;i<n-1;i++)
       {
        vec[i]->right=vec[i+1];
        vec[i]->left=NULL;
       }
       return vec[0];
   }

   void ConvLL()
   {
    root=CLL(root);
   }


    void show()
    {
        Node*p=root;
        while(p)
        {
            cout<<p->data<<" ";
            p=p->right;
        }
        cout<<endl;
    }



    // balanced binary tree ;
    //using inorder vecctor;
     void inorder_DV(vector<int>&vec,Node*p)
    {
        if(p==NULL)
        {
            return;

        }


        inorder_DV(vec,p->left);
        vec.push_back(p->data);
        inorder_DV(vec,p->right);
    }


    Node*Balancing(vector<int>vec,int l,int h)
    {
        if(l>h)
        {
            return NULL;
        }

        int mid=l+h/2;
        Node*p=new Node(vec[mid]);

        p->left=Balancing(vec,l,mid-1);
        p->right=Balancing(vec,mid+1,h);

        return p;

    }

    

    // BST from preorder ;...........given preorder vector


    Node*Pre_BST(vector<int>&vec,int i,int l,int h)
     
    {
        if(i>=vec.size())
        {
            return NULL;
        }

        if(l>h)
        {
            return NULL;
        }
        
        Node*p=new Node(vec[i]);
        i++;
        int z=p->data;

        if(vec[i]<p->data && vec[i]<h)
        {
            p->left=Pre_BST(vec,i,l,p->data);
        }

        if(vec[i]>p->data && vec[i]<h)
        {
            p->right=Pre_BST(vec,i,p->data,h);
        }

        return p;

    }


    // Merging two bst ....


    Node*IN_BST(vector<int>&vec,int l,int h)
    {
        if(l>h)
        {
            return NULL;
        }

        int mid=(l+h)/2;

        Node*p=new Node(vec[mid]);

        p->left =IN_BST(vec,l,mid-1);
        p->right=IN_BST(vec,mid+1,h);

        return p;
    }

    void Merge(Binary_Search_tree t ,Binary_Search_tree t2)
    
    {      
            vector<int>v1;
            inorder_DV(v1,t2.root);
            vector<int>v2;
            inorder_DV(v2,t.root);

            int i =0,j=0;

            int n=v1.size();
            int m=v2.size();
             vector<int>ans;
            while(i<n && j<m)
            {
                if(v1[i]<v2[j])
                {
                    ans.push_back(v1[i]);
                    i++;
                }
                else
                {
                    ans.push_back(v2[j]);
                    j++;
                }

            }
            while(i<n)
            {
                ans.push_back(v1[i]);
                i++;

            }
            while(j<m)
            {
                ans.push_back(v2[j]);
                j++;
            }
            
  
            int l=0;
            int h=ans.size()-1;

            root=IN_BST(ans,l,h);    
  }


//  is Complete binary tree or not 
bool isCBT(Node*p,int i,int count)
{
    if(p==NULL)
    {
        return true;
    }
    
    if(i>count)
    {
        return false;
    }

    bool x,y;
    x= isCBT(p->left,2*i+1,count);
    y= isCBT(p->right,2*i+2,count);

    return x&y;
}


};

int main()
{

    Binary_Search_tree b1;
   // Binary_Search_tree c2;
    

    b1.create();
  // cout<<"creating bst 2 "<<endl;
 //   b1.level_order_();
   //  c2.create();
  // b2.level_order_();
        /*
    cout << endl;

    b1.iter_inorder();

    cout << endl;
    b1.inter_preorder();

    cout << endl;

    cout << "Search" << endl;
    cout << b1.SearchBST(5) << endl;
    cout << "delete : " << endl;
    b1.DELETE_BST(5);
    b1.level_order_();
    cout << endl;
    b1.iter_inorder();

    cout << endl;
    cout << endl;

   // cout << b1.Is_Val 
            
    id_BST() << endl;

   // cout << endl;

   // cout << b1.kth_min(3);
*/

   // b1.Convert_Linked_List();
    //b1.show();

 //   b1.ConvLL();
   // b1.show();

//Binary_Search_tree b3;
 // b3.Merge(b1,c2);

// b3.level_order_();



    return 0;
}