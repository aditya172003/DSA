#include<bits/stdc++.h>
using namespace std ;

class a 
{
    public:
  void show()
    {
        cout<<" in a"<<endl;
    }
};

class b :public a
{
    public:
    void show()
    {
        cout<<" in b"<<endl;
    }
};

int main()
{
   a i;
   b j;
   a *prt;
   prt->show();
   prt =&j; 
   prt->show();
}