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

    friend class Tree;
};

class Tree
{
private:
    Node *root;

public:
    Tree()
    {
        root = NULL;
    }

    void create()
    {
        int a, b;

        cout << "Enter the data in the root node :";
        cin >> a;
        root = new Node(a);
        queue<Node *> q;
        q.push(root);
        Node *p = NULL;
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            cout << "Enter the data to left of " << p->data << endl;
            cin >> a;
            if (a != -1)
            {
                p->left = new Node(a);
                q.push(p->left);
            }

            cout << "Enter the data to right of " << p->data << endl;
            cin >> a;
            if (a != -1)
            {
                p->right = new Node(a);
                q.push(p->right);
            }
        }
    }

    void level_order()
    {
        Node *p = root;
        queue<Node *> q;
        q.push(p);
        q.push(NULL);
        while (!q.empty())
        {
            p = q.front();
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

    int height_of_bt()
    {
        return height(root);
    }

    int height(Node *p)
    {
        if (p == NULL)
        {
            return 0;
        }

        int x = height(p->left);
        int y = height(p->right);

        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }

    // right most
    int rightmax(Node *p)
    {
        if (p == NULL)
        {
            return 0;
        }

        int y = 1 + rightmax(p->right);
        if (p->left)
        {
            p = p->left;
            y = max(y, rightmax(p->right));
        }
        return y;
    }

    int leftmax(Node *p)
    {
        if (p == NULL)
        {
            return 0;
        }

        int x = 1 + leftmax(p->left);

        if (p->right)
        {
            p = p->right;

            x = max(x, leftmax(p->left));
        }
        return x;
    }

    int maxdia()
    {
        int x = leftmax(root);
        int y = rightmax(root);

        cout << x << " " << y << endl;

        return abs(x + y) - 1;
    }

    // above is one qestion i observed

    // Q 2 ] successfully solved max diameter of the tree

    // it required 4 funcions

    // 1
    int leftmax_height(Node *p)
    {
        if (p == NULL)
        {
            return 0;
        }

        int x = height(p->left);
        int y = height(p->right);
        int z = leftmax_height(p->left);

        return max(z, (x + y + 1));
    }

    // 2
    int rightmax_height(Node *p)
    {
        if (p == NULL)
        {
            return 0;
        }

        int x = height(p->left);
        int y = height(p->right);

        int z = rightmax_height(p->right);

        return max(z, (x + y + 1));
    }

    // 3
    int diameter_of_tree()
    {
        int x = leftmax_height(root);
        int y = rightmax_height(root);
        cout << x << " " << y << endl;
        return max(x, y);
    }

    // and 4 th one is height function

    pair<int, int> diameter(Node *p)
    {
        if (p == NULL)
        {
            pair<int, int> pr;
            pr.first = 0;
            pr.second = 0;

            return pr;
        }

        pair<int, int> x = diameter(p->left);
        pair<int, int> y = diameter(p->right);
        pair<int, int> pr;
        pr.first = (x.first > y.first) ? x.first + 1 : y.first + 1;

        pr.second = max((x.first + y.first + 1), max(x.second, y.second));

        return pr;
    }

    // optimised solution of the above question ;;;; O(n) .. time complexity
    pair<int, int> dia()
    {
        return diameter(root);
    }

    // checking the balanced binary tree

    // we can make  it optimised using pair  <int,bool>
    // where int will store the height of tree and bool will store the result

    bool balanced(Node *p)
    {
        if (p == NULL)
        {
            return true;
        }

        int x = height(p->left);
        int y = height(p->right);

        bool res = balanced(p->left);
        bool res1 = balanced(p->right);

        if (abs(x - y) >= 2)
        {
            return false;
        }

        else
        {
            return res & res1;
        }
    }

    // this is the optimized solution of this question
    pair<int, bool> IsBalanced(Node *p)
    {
        if (p == NULL)
        {
            pair<int, bool> pr;
            pr.first = 0;
            pr.second = true;
            return pr;
        }

        pair<int, bool> x = IsBalanced(p->left);
        pair<int, bool> y = IsBalanced(p->right);
        pair<int, bool> pr;
        pr.first = (x.first > y.first) ? (x.first + 1) : y.first + 1;

        if (abs(x.first - y.first) >= 2)
        {
            pr.second = false;
        }
        else
        {
            pr.second = x.second & y.second;
        }

        return pr;
    }
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return balanced(root);
    }

    // two trees identical or not ..........................//////
    bool Identical(Node *p, Node *q)
    {
        // here may chance to miss check the condition and all
        if (p == NULL || q == NULL)
        {

            if (p == NULL && q == NULL)
            {
                return true;
            }
            return false;
        }

        if (p->data != q->data)
        {
            return false;
        }

        bool x = Identical(p->left, q->left);
        bool y = Identical(p->right, q->right);
        // here this is x&&y not x&y causes segmentaion fault
        return x && y;
    }
    // Function to check if two trees are identical.
    bool isIdentical(Tree t)
    {
        return Identical(this->root, t.root);
        // Your Code here
    }

    // sum tree ......data in the node is equla to sum of its left subtree data sum  and right sub tree data sum
    // of the tree

    pair<int, bool> isSum(Node *p)
    {
        if (p == NULL)
        {
            pair<int, bool> pr;
            pr.first = 0;
            pr.second = true;
            return pr;
        }

        if (p->left == NULL && p->right == NULL)
        {
            pair<int, bool> pr;
            pr.first = p->data;
            pr.second = true;
            return pr;
        }

        pair<int, bool> x = isSum(p->left);
        pair<int, bool> y = isSum(p->right);
        pair<int, bool> pr;

        int z = (x.first + y.first);
        pr.first = z + p->data;
        if (z != p->data)
        {
            pr.second = false;
        }
        else
        {

            pr.second = x.second && y.second;
        }
        return pr;
    }

    bool isSumTree(Node *root)
    {
        return isSum(root).second;
    }

    //.................................................................................

    vector<int> zigzag()
    {
        Node *p = root;
        queue<Node *> q;
        q.push(p);

        vector<int> z;
        bool left = true;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);
            for (int i = 0; i < size; i++)
            {
                Node *p = q.front();
                q.pop();
                int index = left ? i : size - 1 - i;
                ans[index] = p->data;

                if (p->left)
                {
                    q.push(p->left);
                }
                if (p->right)
                {
                    q.push(p->right);
                }
            }
            for (int i = 0; i < ans.size(); i++)

            {
                z.push_back(ans[i]);
            }
            left = !left;
        }

        return z;
    }

    // very much time comsumed question ..............................................border traversal
    void left_t(Node *p, vector<int> &vec)
    {
        if (p == NULL)
        {
            return;
        }
        if (p->left == NULL && p->right == NULL)
        {

            return;
        }

        vec.push_back(p->data);
        if (p->left)
        {
            left_t(p->left, vec);
        }
        else
        {
            left_t(p->right, vec);
        }
    }

    void right_t(Node *p, vector<int> &vec)
    {
        if (p == NULL)
        {
            return;
        }
        if (p->left == NULL && p->right == NULL)
        {

            return;
        }

        if (p->right)
        {
            right_t(p->right, vec);
        }
        else
        {
            right_t(p->left, vec);
        }

        vec.push_back(p->data);
    }

    void leaf_t(Node *p, vector<int> &vec)
    {
        if (p == NULL)
        {
            return;
        }
        if (p->left == NULL && p->right == NULL)
        {
            vec.push_back(p->data);
            return;
        }

        leaf_t(p->left, vec);
        leaf_t(p->right, vec);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        ans.push_back(root->data);
        left_t(root->left, ans);
        leaf_t(root->left, ans);
        leaf_t(root->right, ans);

        right_t(root->right, ans);

        return ans;
    }

    /*
   void verticle_traversal(map<int,vector<int>>&mp,int n,Node*p)
   {
            if(p==NULL)
            {
               return;
            }

            mp[n].push_back(p->data);
            verticle_traversal(mp,n-1,p->left);
            verticle_traversal(mp,n+1,p->right);

   }

   vector<int>verticle_t()
   {         map<int,vector<int>>mp;
           verticle_traversal(mp,0,root);
             vector<int>ans;
             for(auto i :mp)
             {
                for(auto j : i.second)
                {
                   ans.push_back(j);
                }
             }

             return ans;
   }

   */

    // for verticle order traversal , top and bottom view of the tree
    vector<int> verticle_t(Node *p)
    { // hd   level    nodes
        map<int, map<int, vector<int>>> mp;
        // hd level
        queue<pair<Node *, pair<int, int>>> q;

        int h = 0;
        int l = 0;
        q.push(make_pair(p, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<Node *, pair<int, int>> pr = q.front();
            q.pop();
            int hd = pr.second.first;
            int lev = pr.second.second;
            mp[hd][lev].push_back(pr.first->data);

            if (pr.first->left)
            {
                q.push(make_pair(pr.first->left, make_pair(hd - 1, lev + 1)));
            }
            if (pr.first->right)
            {

                q.push(make_pair(pr.first->right, make_pair(hd + 1, lev + 1)));
            }
        }

        vector<int> ans;

        for (auto i : mp)
        {

            // this is for verticle traversal
            // for(auto j : i.second)
            // {
            //     for(auto k : j.second)
            //     {
            //         ans.push_back(k);

            //     }

            // }

            // this is for top order traversal
            auto j = i.second;
            //  ans.push_back(j.begin()->second[0]);

            // for bottom order travesal
            int siz = i.second.rbegin()->second.size();
            ans.push_back(j.rbegin()->second[siz - 1]);
        }

        return ans;
    }

    vector<int> verticle_treaversal()
    {
        return verticle_t(root);
    }

    // for left and right view of tree .......................

    vector<int> level(Node *p)
    {

        map<int, vector<int>> mp;
        queue<pair<Node *, int>> q;
        q.push(make_pair(p, 0));

        while (!q.empty())
        {
            pair<Node *, int> pr = q.front();
            q.pop();
            int l = pr.second;
            mp[l].push_back(pr.first->data);

            Node *d = pr.first;
            if (d->left)
            {
                q.push(make_pair(d->left, l + 1));
            }

            if (d->right)
            {
                q.push(make_pair(d->right, l + 1));
            }
        }

        vector<int> ans;

        // right view

        for (auto i : mp)
        {
            // this is for right view
            ans.push_back(*i.second.rbegin());

            // this is for left view
            ans.push_back(*i.second.begin());
        }
        return ans;
    }

    // sum of longest path           /..correct

    pair<int, int> sum_l(Node *p)
    {
        if (p == NULL)
        { // sum,path
            pair<int, int> pr;
            pr.first = 0;
            pr.second = 0;
            return pr;
        }

        pair<int, int> x = sum_l(p->left);
        pair<int, int> y = sum_l(p->right);

        pair<int, int> pr;
        if (x.second == y.second)
        {
            if (x.first > y.first)
            {
                pr.second = x.second + 1;
                pr.first = p->data + x.first;
            }
            else
            {
                pr.second = y.second + 1;
                pr.first = p->data + y.first;
            }
        }
        else if (x.second > y.second)
        {
            pr.second = x.second + 1;
            pr.first = p->data + x.first;
        }
        else
        {
            pr.second = y.second + 1;
            pr.first = p->data + y.first;
        }

        return pr;
    }

    int max_path_sum()
    {
        return sum_l(root).first;
    }

    // lowest ancestors ......correct

    pair<Node *, bool> LCA(Node *p, int a, int b)
    {
        if (p == NULL)
        {
            pair<Node *, bool> pr;
            pr.first = NULL;
            pr.second = false;
            return pr;
        }

        if (p->data == a || p->data == b)
        {
            pair<Node *, bool> pr;
            pr.first = p;
            pr.second = true;
            return pr;
        }

        pair<Node *, bool> x, y, pr;
        x = LCA(p->left, a, b);
        y = LCA(p->right, a, b);

        if (x.second && y.second)
        {
            pr.first = p;
            pr.second = false;
        }
        else
        {
            if (x.first)
            {
                pr.first = x.first;
            }
            else
            {
                pr.first = y.first;
            }

            pr.second = x.second | y.second;
        }
        return pr;
    }

    Node *LCA_T(int a, int b)
    {
        return LCA(root, a, b).first;
    }

    // k sum path .......................................................

    void kSum(Node *p, int &count, vector<int> vec, int k)
    {
        if (p == NULL)
        {
            return;
        }

        vec.push_back(p->data);

        kSum(p->left, count, vec, k);
        kSum(p->right, count, vec, k);

        int i = vec.size();
        int sum = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            sum = sum + vec[j];
            if (sum == k)
            {
                count++;
            }
        }

        vec.pop_back();
    }

    int k_sum_path(int k)
    {
        int count = 0;
        vector<int> vec;
        kSum(root, count, vec, k);

        return count;
    }



    // k th ancestor

        int kAncestor(Node *p, vector<int> vec, int k,int node)
    {
        if (p == NULL)
        {
            return -1;
        }
        if(p->data==node)
        {
            int si=vec.size();
            if(si<k)
            {
                return -1;
            }
            return vec[si-k];
        }
        vec.push_back(p->data);

       int x =kAncestor(p->left, vec, k,node);
       int y=  kAncestor(p->right,vec, k,node);


        vec.pop_back();
        
        if(x==-1 && y==-1)
        {
            return -1;
        }
        if(x!=-1 && y==-1)
        {
            return x;
        }
        else
        {
            return y;
        }
    }
// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{ 
        vector<int> vec;
       return kAncestor(root, vec, k,node);

        
}



// another approach


Node*kthA(Node*p,int &k,int node)
{
   
    if(p==NULL)
    {
        return NULL;
    }

    if(p->data==node)
    {
        return p;
    }

    Node*x,*y;

    x=kthA(p->left,k,node);
    y=kthA(p->right,k,node);
      
    if(x!=NULL)
    {    k--;
        if(k==0 && x->data==node)
        {
            return p;
        }
        if(k<0)
        {
            return x;
            
        }
       
        return x;
    }

    if(y!=NULL)
    {
        k--;
        if(k==0 && y->data==node)
        {
            return p;
        }
        if(k<0)
        {
            return y;
            
        }
     
        return y;
    }
    
    return NULL;

}

int KthAnc(int k,int node)
{
    Node*p= kthA(root,k,node);

    if(p->data==node)
    {
        return -1;
    }
    return p->data;

}
//...........................................................................



//  max sum of non adjacent nodes 

pair<int,int> s_max(Node*p)
{
   if(p==NULL)
    {
        pair<int,int>pr;
        pr.first=0;
        pr.second=0;
        return pr;

    }

    pair<int,int> x,y,pr;
    x=s_max(p->left);
    y=s_max(p->right);
     pr.first=x.second+y.second+p->data;
     pr.second=max(x.first,x.second)+max(y.first,y.second);
    
    
   return pr;

}

int max_sum_non_adjacent()
{
   pair<int,int>pr= s_max(root);

   return (pr.first>pr.second)?pr.first:pr.second;
}





// construct a binary tree from inorder and pre order

// requre one find function 

 int find_(vector<int>in ,int n)

 {
           for(int i =0;i<in.size();i++)
           {
            if(in[i]==n)
            {
                return i;
            }

           }
           return -1;
 }


Node* ctr(int index,int low,int high,vector<int>in,vector<int>pre)
{
    if(index>=pre.size()||low>high)
    {
        return NULL;
    }


    int ele=pre[index];

    Node*p=new Node(ele);

    int pos=find_(in,ele);

    p->left=ctr(index+1,low,pos-1,in,pre);
    p->right=ctr(index+2,pos+1,high,in,pre);
   
   return p;

   
    
    
}



void counst(vector<int>in,vector<int>pre)
{
   int low=0;
   int high=in.size()-1;
    
    root =ctr(0,low,high,in,pre);
}





// ......................Moriss traversal
Node*Find_pred(Node*curr)
{
   Node* p=curr->left;
    while(p->right!=NULL && p->right!=curr)
    {
        p=p->right;
    }
    return p;
}


void Moris_Treaversal()
{
    Node*curr=root;

    while(curr)
    {
             if(curr->left==NULL)
             {
                cout<<curr->data<<" ";
                curr=curr->right;
             }
             else
             {
                Node*pred=Find_pred(curr);
                if(pred->right==NULL)
                {
                    pred->right=curr;
                    curr=curr->left;
                }
                else
                {
                    pred->right=NULL;
                    cout<<curr->data<<" ";
                    curr=curr->right;
                }
             }
            
         
    }
     cout<<endl;

}



    // converting into linked list .....................................using morris traversal
    // using find_predict function 


    void Conv_Pre_linnked_list()
    {
        Node*curr=root;
        while(curr!=NULL)
        {   
            if(curr->left)
            {
                Node*pred=Find_pred(curr);
                 pred->right=curr->right;
                 curr->right=curr->left;
                 curr->left=NULL;
                

            }
             curr=curr->right;
         
        }
    }


    void show()
    {
        Node*p=root;
        while(p)
        {  
            
            cout<<p->data<<" ";
            p=p->right;
        }
    }




};

int main()
{
    Tree t1, t2;

    t1.create();
    // t2.create();

    //t1.level_order();
    // t2.level_order();

    // t1.iter_inorder();
    cout << endl;
    // t1.inter_preorder();
    cout << endl;
    cout << "height of a tree " << t1.height_of_bt() << endl;
    // cout<<"Diameter of tree is "<<t1.maxdia()<<endl;

    cout << "Diameter of the tree " << t1.diameter_of_tree() << endl;

    pair<int, int> pr = t1.dia();
    cout << "Diameter of tree using pair " << pr.second << endl;

    // if (t1.isIdentical(t2))
    // {
    //     cout << "Identical" << endl;
    // }
    // else
    // {
    //     cout << "Not identical" << endl;
    // }

    //.....................................
    cout << "Zigzag" << endl;
    for (auto i : t1.zigzag())
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Border traversal " << endl;

    //  vector<int>o=t1.boundary();

    //  for(auto i : o)
    //  {
    //     cout<<i<<" ";
    //  }

    cout << endl;

    for (auto i : t1.verticle_treaversal())
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "max path sum :  " << t1.max_path_sum() << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << t1.LCA_T(2, 3) << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    int k =3;
    cout<<t1.k_sum_path(k)<<endl;

    //    vector<int>in={3 ,1 ,4 ,0 ,5 ,2};
    //    vector<int>pre={0,1 ,3, 4, 2 ,5};
    // t2.counst(in,pre);
    // t2.level_order();

    t1.Moris_Treaversal();

    t1.Conv_Pre_linnked_list();
    t1.show();
    
    return 0;
}
