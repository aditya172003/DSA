#include<iostream>

using namespace std;

class node
{
private :
	int data;
	node*left;
	node*right;
public:
	node(int d)
    {
		data =d;
		left=NULL;
		right=NULL;
    }
	node()
	{
		left=NULL;
		right=NULL;
		data =0;
	}

	friend class BST;

};

class BST
{
private:
	node*root;
public:
	BST()
   {
		root=NULL;
   }


   node*search_node(int d)
	{
		node*p=root;
        node*q=NULL;
		while(p && p->data !=d)
		{   q=p;
			if(p->data >d)
			{
				p=p->left;
			}
			else
			{
				p=p->right;
			}

		}

		if(p){
			return q;
		}
		return NULL;
	}

    node*Inord_pred(node*pre)
	{
		node*p=pre;

		p=p->left;
		while(p->right)
		{
			p=p->right;
		}

		return p;
	}


    node*delete_main(node*d)
	{
		if(d==NULL)
		{
		    return NULL;
		}

		if(d->left !=NULL && d->right !=NULL)
		{
			        node* preo=Inord_pred(d);

					d->data = preo->data;


					d->left= delete_main(d->left);
					return d;


		}

		if(d->left)
		{
	        node*temp = d->left ;
	        delete d;

			return temp;
		}

		if(d->right )
		{
			node*temp = d->right;
			delete d;
			return temp;
		}



		delete d;
		return NULL;
	}

	void delete_node(int d)
	{
		node*p = search_node(d);
		if(p==NULL)
		{
			cout<<"DATA NOT FOUND \n";
			return;
		}
      if(p->left !=NULL && p->right !=NULL)
      {
    	  if(p->left->data == d)
    	  {
    		  p->left = delete_main(p->left);
    	  }
    	  else
    	  {
    		  p->right=delete_main(p->right);
    	  }
      }

      if(p->left)
      {
    	  p->left = delete_main(p->left);
      }

      if(p->right)
      {
    	  p->right = delete_main(p->right);
      }

	}

};


