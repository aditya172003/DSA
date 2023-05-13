#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n;
        cin>>n;
        cin>>s;
        
        vector<int>vec;
        int fone=0,sone=0,cone=0;
        
        int i=0;
        for(i ;i<n;i++)
        
        {
            if(s[i]=='1')
            {
                fone++;
            }
            else
            {
                break;
            }
        }
        for(i ;i<n;i++)
        { 
            
            sone=0;
            if(s[i]=='1')
            {
                  while(s[i]=='1')
                {
                    sone++;
                    i++;
                }
                i--;
                 cone=max(sone,cone);
            }
          
        }
                                                          
        // if(sone!=0)
        //     vec.push_back(sone);
        
       
        
        // int ma=*max_element(vec.begin()+1,vec.end());
        
        cout<<(fone+cone)<<endl;
    }
	// your code goes here
	return 0;
}