#include<bits/stdc++.h>
using namespace std;

class Data
{
    public:
    string key;
    string value;


    public:
    Data(string s1,string s2)
    {
        key =s1;
        value = s2;
    }

    Data()
    {

    }


    void showData()
    {
        cout<<key<<" ";
    }

    void getData()
    {
        cout<<"Enter the key : ";
        cin>>key;
        value="k";
    }
    
};




class Node{
    public:
        Data d;
        Node*left;
        Node*right;

        int height;
        int bf;
    public:
        Node()
        {

            left =NULL;
            right=NULL;

            height=0;
            bf=0;
        }

        Node(Data d,int h,int i)
        {
            this->d = d;
            height  = h;
            bf  = i;
            left =NULL;
            right=NULL;
        }



        void show()
        {
            d.showData();
        
        }
        int getHeight()
        {
            return height;
        }

        int getbf()
        {
            return bf;
        }

        void setHeight(int h)
        {
            height = h;

        }

        void setIndex(int i)
        {
            bf = i;

        }



   
};


int height(Node*p)
{
    if(p==NULL)return 0;
    int hl =height(p->left);
    int hr =height(p->right);
    
   p->height= max(hl,hr);

    p->bf = hl-hr;
   return p->height+1;
}





class AVL_Tree
{
        public :
            Node*root;
        public:
            AVL_Tree()

            {
                root = NULL;
            }
        Node* rr_rotate(Node*p)
        {
            Node*q = p->right;
            p->right  = q->left ;
            q->left = p;
            return q;
        }
        
        Node* ll_rotate(Node*p)
        {
            Node*q = p->left;
            p->left = q->right;
            q->right = p;
            return q;
        }

        Node* rotate(Node*p ,string s,int i )
        {
            if(p->bf >=2)
            {
                if(s[i+1]=='R')
                {
                   
                   return ll_rotate(p->left=rr_rotate(p->left));
                }
                else
                {
                    return ll_rotate(p);
                }
            }
            else if(p->bf == -2)
            {
                if(s[i+1]=='L')
                {
                    
                   return rr_rotate(p->right=ll_rotate(p->right));
                }
                else
                {
                   return rr_rotate(p);
                }
            }else{
                return p;
            }
             
        }

        Node* InsertRec(Node *p,Data dt ,string &s,int i)
        {
            if(p==NULL)return new Node(dt,0,0);
               


            if(stoi(p->d.key)>stoi(dt.key))
            {
                s.push_back('L');
                p->left = InsertRec(p->left ,dt,s,i+1);
            }
            else
            {
                s.push_back('R');
                p->right = InsertRec(p->right,dt,s,i+1);
            }


            cout<<"Heigt = "<<height(p)<<endl;


            return rotate(p,s,i);
        }





        void create()
        {
            cout<<"Enter the data :"<<endl;
            while(true)
            {
                Data d;
                d.getData();
                if(d.key =="-1")return;
                string s;
                cout<<height(root)<<endl;
                    cout<<"----"<<endl;
                
                    cout<<"----"<<endl;
               root= this->InsertRec(root,d,s,0);
                 
               cout<<height(root)<<endl;
               cout<<"----"<<endl;
               levelT();
               cout<<endl;
               
                
            }
        }

        void levelT()
        {
            queue<Node*>q;
            q.push(root);
            q.push(NULL);
            while(!q.empty())
            {
                
                Node*p= q.front();
                q.pop();
                if(p==NULL)
                {
                    cout<<endl;
                    if(!q.empty())q.push(NULL);
                }
                else
                {
                    p->show();
                    if(p->left)q.push(p->left);
                     if(p->right)q.push(p->right);
                }
                
            }
        }
};



int main()
{
    AVL_Tree at;
    at.create();
}