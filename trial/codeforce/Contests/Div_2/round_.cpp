#include<bits/stdc++.h>
using namespace std;
 
 
 
 
 

 
 
 
// declaration
typedef long long ll;
#define pr pair<int,int>
#define vr(st) vector<st>
#define mapi  map<int,int>
#define mapc  map<char,int>
#define maps  map<string,int>
#define mapv(st,vt) map<st,vector<vt>>
 
 
 
 
 
// priority queues 
#define min_q(st) priority_queue<st,vector<st>,greater<st>>
#define max_q(st) priority_queue<st>
 
 
 
 
// algorithms 
#define sort(arr) sort(arr.begin(),arr.end());
#define sortd(arr) sort(arr.begin(),arr.end(),greater<>());
 
 
 
 
// functions
#define pb(c) push_back(c);
#define ps(i) push(i);
#define print(v) for(auto i : v)cout<<i<<' ';
#define lbi(vec,a) lower_bound(vec.begin(),vec.end(),a)-vec.begin();
 
 
 
 
// looping 
#define lop(n) for(int i =0;i<n;i++)
#define fr(n,arr) for(int i =0;i<n;i++)cin>>arr[i];
 
 
#define loop(a,b,c) for(int i=a;i<b;i+=c)
#define mx(v) *max_element(v.begin(),v.end());
#define uni(v) unique(v.begin(),v.end());
 
 
 
 
 
 
 
void solve()
{

ll n , p;
cin>>n>>p;
vr(ll)a(n,0);
vr(ll)b(n,0);
fr(n,a);
fr(n,b);
map<ll,ll>mp;

//vr(ll)ct(100005,0);
vr(ll)total(100005,0);
for(int i=0;i<n;i++)
{
 //  ct[b[i]]++;
 
   total[b[i]]+=a[i];
   mp[b[i]]+=a[i];
   
}
ll ans =0;
ll ppl = n;
for(auto i : mp)
{
    ll cost = i.first;
    ll tt   = i.second;
    //if(total[cost]==-1 || tt==0)continue;
   // total[cost]=-1;
    if(n==0)
    {
        break;
    }
    
    if(cost<=p)
    {
        ans+=p;
        n--;
         if(tt<n)
        {
            n-=tt;
            ans+=(cost*tt);


        }
        else{
            ans+=(n*cost);
            n=0;
            break;
        }
        
    }
    else{
        break;
    }
    

}


if(n)
{
    ans+=(n*p);
    n=0;
}

cout<<ans<<endl;
}
 
 
 
 
 
 
 
 
int main()
{
int t;
cin>>t ;
while(t--)
{
solve();
}
}