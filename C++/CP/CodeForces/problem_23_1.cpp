#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long
#define finout() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#include "limits.h"
#define find_max *max_element

#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
#define vpl vector<pair<long long,long long>>
#define pb push_back
#define pp pop_back
#define sv(arr) sort(arr.begin(),arr.end())
#define rv(arr) reverse(arr.begin(),arr.end())
 
  
#define si set<int>
#define sl set<long long>
#define st set<string>
#define mst set<int>

#define pi pair<int,int>
#define pl pair<long long,long long>
#define fi first
#define se second
////////////////  STRING///////////////////
#define gl(s) getline(cin,s)
#define le(s) s.length()
#define str(p,q) s.erase(p,q)
// from p index q elements to be removed
// to reverse string --> reverse(s.begin(), s.end())
////////////////////////////////////////////////
typedef long long ll; //8
typedef long double ld; //12
//////////////////  LOOP  ////////////////////////
#define f(i,x,n) for(int i = x; i < n; i++)
#define rf(i,x,n) for(int i = x; i >= n; i--)
#define fr(i,m) for(auto i:m)
#define read(a)        for(auto& x:a) cin>>x
///////////////////////////////////////////////////
const int MOD = 1e9 + 7;;
const int N = 1e6 + 1;
 
int sieve[N];bool prime[N+1];
////////////////////////////////////////////sieve///////////////////
void SieveOfEratosthenes(int n){
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true){
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    // for (int p=2; p<=n; p++)
    //   if (prime[p])
    //       cout << p << " ";
}//////////////////  z- function /////////////////////////////////////
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
////////////////////////////gcd///////////////////////////////
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int factorial(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}
int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int max(int a, int b, int c) { return max(max(a, b), c); }

 
int test(){
  
int a,b;

cin>>a>>b;
a=abs(a);
b=abs(b);
int z =min(abs(a),abs(b));

int ans=2*z;

a-=z;
b-=z;

if(max(a,b)>0)
{
    ans+=2*max(a,b);
    ans--;
}

return ans;





}
 
signed main(){
    finout();
    int t;
    cin>>t;
    
    while(t--){
       cout<<test()<<endl;
    }
    
return 0;
}