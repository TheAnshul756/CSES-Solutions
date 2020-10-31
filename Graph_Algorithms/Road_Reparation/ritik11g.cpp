#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mem(a,val) memset(a,(val),sizeof((a)))
#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define decimal(n)  cout << fixed ; cout << setprecision((n));
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define endl "\n"
#define lcm(m,n) (m)*((n)/__gcd((m),(n)))
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(ll (i)=1;(i)<(n);(i)++)
#define repa(i,n,a) for(ll (i)=(a);(i)<(n);(i)++)
#define repr(i,n) for(ll (i)=(n)-1;(i)>=0;(i)--)
#define mll map<ll,ll>
#define vll vector<ll>
#define sz(x) (ll)x.size()
#define ub upper_bound
#define lb lower_bound
#define pcnt(x) __builtin_popcountll(x)
#define ff first
#define ss second
#define int long long
#define pb push_back
#define pii pair< int,int >
const long long N=1e9;
const long long NN=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
template<typename T,typename T1>T maxn(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T minn(T &a,T1 b){if(b<a)a=b;return a;}
const int nax = 1e5+10;
int par[nax] ,sz[nax]; 
int fp(int v)
{
    if( v==par[v] ) return v;
    return par[v] = fp(par[v]);
}
 
struct edge_t
{
    int u ,v, w;
    bool operator<(edge_t const &p) const
    {
        return w < p.w;
    }
};
 
vector<edge_t> e;
void solve()
{
    //code begins from here//
    int n , m;
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++ ) par[i] = i , sz[i] = 1;
    for(int i=0 ; i<m ; i++ )
    {
        int u,v,w;
        cin >> u >> v >> w;
        e.pb({u,v,w});
    }
    sort(all(e));
    int i=0;
    int valid = 0;
    int ans = 0;
    while( i<m && valid< (n-1) )
    {
        int pu = fp(e[i].u);
        int pv = fp(e[i].v);
        if( pu != pv )
        {
            if( sz[pu] > sz[pv] ) swap(pu,pv);
            par[pu] = pv;
            sz[pv] += sz[pu];
            ans += e[i].w;
            valid++;
        }
        i++;
    }
    if( valid == n-1 ) cout << ans << "\n";
    else cout << "IMPOSSIBLE";
}
signed main()
{
FAST
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int testcase=1;
//cin>>testcase;
while(testcase--) solve();
return 0;
}
