
#include<bits/stdc++.h>
using namespace std;





//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/submissions/921411876/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

 #include<string>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(!root)return ans;

        queue<TreeNode*>q;

        q.push(root);
    

        while(!q.empty())
        {
            TreeNode*p=q.front();
            q.pop();

           

           if(p)
           {
                string s = to_string(p->val)+',';
                ans.append(s);
                q.push(p->left);

                q.push(p->right);
           }
           else
           {
               ans.append("null ,");
           }
        }

         return ans;
        


    }
    


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
      
        TreeNode*root =new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*p;
        
        while(!q.empty())
        {

                p =q.front();
                q.pop();
                getline(s,str,',');

                if(str == "null ")
                {
                    p->left=NULL;
                }
                else
                {
                     cout<<str<<"** "<<endl;

                    p->left= new TreeNode(stoi(str));
                    q.push(p->left);
                }
               
               getline(s,str,',');


                if(str=="null ")
                {
                    p->right=NULL;
                }
                else
                {
                     cout<<str<<"***"<<endl;
                    p->right= new TreeNode(stoi(str));
                    q.push(p->right);
                }


               
                
        }

        return root;
      

       
    }
};
