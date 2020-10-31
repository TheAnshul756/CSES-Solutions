#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mem(a,val) memset(a,(val),sizeof((a)))
#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define decimal(n)  cout << fixed ; cout << setprecision((n));
#define mp make_pair
#define eb emplace_back
#define f first 
#define s second
#define all(v) v.begin(), v.end()
#define endl "\n"
#define lcm(m,n) (m)*((n)/__gcd((m),(n)))
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(ll (i)=1;(i)<(n);(i)++)
#define repa(i,n,a) for(ll (i)=(a);(i)<(n);(i)++)
#define repr(i,n) for(ll (i)=(n)-1;(i)>=0;(i)--)
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define vll vector<ll>
#define sz(x) (ll)x.size()
#define ub upper_bound
#define lb lower_bound
#define pcnt(x) __builtin_popcountll(x)
const long long nax=1e5+10;
const long long NN=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
template<typename T,typename T1>T maxn(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T minn(T &a,T1 b){if(b<a)a=b;return a;}
//Topic : Eular-tour

vector<int> g[nax];//graph
stack<int> s;
vector<int> indeg(nax,0),outdeg(nax,0),vis(nax,0),eular;
 
void dfs(int v)//normal dfs
{
    vis[v] = 1;
    for(auto &i : g[v] )
        if( !vis[i] )
            dfs(i);
    return ;
}
void eular_dfs(int v)//euler tour
{
    s.push(v);
    while( g[v].size() )
    {
        int xx = g[v].back();
        g[v].pop_back();
        eular_dfs(xx);
    }
    eular.eb(s.top());
    s.pop();
    return;
}

void solve()
{
  //code begins from here//
    int n , m;
    cin >> n >> m;
    for(int i=1 ; i<=m ; i++ )
    {
        int u ,v;
        cin >> u >> v;
        g[u].eb(v);
        indeg[v]++;
        outdeg[u]++;
    }
    dfs(1);//condition-1 : all nodes are connected
    bool f = 0;
    for(int i=1 ; i<=n ; i++ )
    {
        if( !vis[i] && g[i].size() ) 
            f = 1;
        if( i!=1 && i!=n && indeg[i] != outdeg[i] )
            f = 1;
    }
    if( f )cout << "IMPOSSIBLE\n";
    eular_dfs(1);
    if( eular[0] != n )cout<<"IMPOSSIBLE\n";
    for(int i=(int)(eular.size())-1 ; i>=0 ; i-- )
        cout << eular[i] << " ";
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
