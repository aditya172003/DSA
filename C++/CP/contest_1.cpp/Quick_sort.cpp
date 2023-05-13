#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)

    {
        int n,k;
        cin>>n>>k;
        vector<int>vec(n);
        for(int  i =0;i<n;i++)
        {
               cin>>vec[i];
 
        }
        int a =n-1;
        
        while(a>=0 && vec[a]>vec[a-1])
        {
                    a--;
        }
        
       

        if(a==-1)
        {
            cout<<0<<endl;
        } 
       
        else
        {
           int b=n-1;
           
            int c=0;
            for(int i =a-1;i>=0;i--)
            
            { 
                if(vec[i]>vec[a])
                {
                    c++;
                }
               
            }
            c=(b-a)+c;
            int ans = ((c)%k==0)?(c)/k:((c)/k)+1;
            cout<<ans<<endl;
        }


    
    }
    return 0;
}