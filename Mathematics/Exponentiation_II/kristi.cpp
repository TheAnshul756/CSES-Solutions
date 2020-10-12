#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define p_q priority_queue
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
 
const int MOD = 1e9 + 7;
int t;
 
ll fun(ll a, ll b, ll mod)
{
    ll res = 1;
    while(b > 0)
    {
        if(b&1)
        res = (res*a)%mod;
 
        a = (a*a) % mod;
        b = b>>1; //remove last bit
    }
    return res;
}
 
int main()
{
    fast_io;
 
    cin>>t;
while(t--)
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll k =fun(b,c,MOD-1); // Fermat's theorem
    cout<<fun(a,k,MOD)<<endl;
    
   // cout<<fun(a,b)<<endl;
}
 
return 0;
}