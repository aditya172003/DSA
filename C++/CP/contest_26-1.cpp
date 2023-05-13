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
        int one=0;
      
        for(int i =0;i<n;i++)
        {
            if(s[i]=='1')
            {
                one++;
            }
            else
            {
                vec.push_back(one);
               
                one=0;
            }
        }
                                                          
        if(one!=0)
            vec.push_back(one);
        
       
        
        int ma=*max_element(vec.begin()+1,vec.end());
        
        cout<<(vec[0]+ma)<<endl;
    }
	// your code goes here
	return 0;
}


