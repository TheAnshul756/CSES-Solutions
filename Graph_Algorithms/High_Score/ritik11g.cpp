#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mem(a,val) memset(a,(val),sizeof((a)))
#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define decimal(n)  cout << fixed ; cout << setprecision((n));
#define mp make_pair
#define eb emplace_back
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
const int inf = 1e16;
const int nax = 3e3+10;
vector<bool> vis(nax,0);
vector<int> g[nax];
 
void dfs( int v )
{
    vis[ v ] = 1;
    for( auto &i : g[v] )
        if( !vis[i] )
            dfs( i );
    return ;
}

void solve()
{
  //code begins from here//
  int n , m ;
    cin >> n >> m;
    vector< pair<pii,int> > ip(m);
    for(int i=0 ; i<m ; i++ )
        cin >> ip[i].ff.ff >> ip[i].ff.ss >> ip[i].ss, g[ip[i].ff.ff].pb( ip[i].ff.ss);
 
    vector<int> dist(n+1,-inf);
    dist[1] = 0;
 
    for(int i = 0 ; i<n-1 ; i++ )
    {
        for(int j=0 ; j<m ; j++ )
        {
            if( dist[ ip[j].ff.ff ] != -inf )
            {
                if( dist[ ip[j].ff.ss ] < dist[ ip[j].ff.ff ] + ip[j].ss )
                {
 
                    dist[ ip[j].ff.ss ] = dist[ ip[j].ff.ff ] + ip[j].ss ;
                }
            }
        }
    }
    for(int i=0 ; i<m ; i++ )
    {
        if( dist[ip[i].ff.ff] != -inf && dist[ ip[i].ff.ss] < dist[ip[i].ff.ff] + ip[i].ss )
            dfs( ip[i].ff.ff );
    }
    if( !vis[n] )
        cout << dist[n];
    else
        cout << "-1\n";
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
