#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {

         vector<vector<int>>v(3,vector<int>(2,0));
        
        vector<int>a;
        vector<int>b;
        for(int  i =0 ;i<3 ;i++)
        {
             int p,q;
                cin>>p>>q;
                a.push_back(p);
                b.push_back(q);
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());


          bool a1 = a[1]>a[0] && a[1]<a[2];
          bool a2 =  b[1]>b[0]&& b[1]<b[2];

         if(a1||a2)
         {
            cout<<"YES"<<endl;
         }
         else
         {
            cout<<"NO"<<endl;
         }
        

    }
    

}