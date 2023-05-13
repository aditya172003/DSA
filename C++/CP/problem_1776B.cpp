#include<iostream>
#include<string>
#include<map>

#include<algorithm>


using namespace std;

bool isPossible(string s)
{
      map<string,int>mp;
       for(int i =0;s[i+1]!='\0';i++)
       {
         string p;
         p.push_back(s[i]);
         p.push_back(s[i+1]);
        auto it=mp.find(p);
         if(it!=mp.end())
         {
            if(i-it->second>1)
            {
                
               return true;
            }
         
         }
         else
         {
              mp[p]=i; 
         }
        
      
        }


        return false;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       string s;
       int n;
       cin>>n;
       cin>>s;
      

      if(isPossible(s))
      {
        cout<<"YES"<<endl;

      }
      else
      {
        cout<<"NO"<<endl;
      }
      
    }
}