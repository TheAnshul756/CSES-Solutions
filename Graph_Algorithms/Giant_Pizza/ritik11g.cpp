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
const int inf = 1e9;
const int nax = 1e5+1;
vector< int > posm[nax] , negm[nax] , posn[nax] , negn[nax] , a(nax,0) , b(nax,0) ,ans(nax,-1) , use(nax,0);

void solve()
{
  //code begins from here//
  int n,m;
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++ )
    {
        char x,z;
        int y,w;
        cin >> x >> y >> z >> w;
        if( x=='+' ) posn[i].pb(y), posm[y].pb(i), a[y]++;
        else         negn[i].pb(y), negm[y].pb(i), b[y]++;
        if( z=='+' ) posn[i].pb(w), posm[w].pb(i), a[w]++;
        else         negn[i].pb(w), negm[w].pb(i), b[w]++;
    }
    set<pair<pii,int> , greater<pair<pii,int>> > pq;
    for(int i=1 ; i<=m ; i++ )
    {
        int f= 0 ;
        if( a[i] )pq.insert({{a[i],i},0}) , f=1;
        if( b[i] )pq.insert({{b[i],i},1}) , f=1;
        if( !f ) ans[i] = 1;
    }
    while( !pq.empty() )
    {
        pair<pii,int> p = *pq.begin();
        int val = p.ff.ff;
        int node = p.ff.ss;
        int sign = p.ss;
        auto it = pq.begin();
        pq.erase( it );
        if( ans[node] != -1 ) continue;
        
        if( !sign )
        {
            ans[node] = 0;
            for( auto &i : posm[node] )
            {
                use[i] = 1;
                for( auto &j : posn[i] )
                {
                    if(pq.find( {{a[j],j},0} ) != pq.end() )
                    {
                        pq.erase( pq.find( {{a[j],j},0} ));
                    a[j]--;
                    if( a[j] != 0 )
                        pq.insert( {{a[j],j},0} );}
                }
                for( auto &j : negn[i] )
                {
                    if( pq.find( {{b[j],j},1} ) != pq.end() )
                    {
                    pq.erase( pq.find( {{b[j],j},1} ) );
                    b[j]--;
                    if( b[j] != 0 )
                        pq.insert( {{b[j],j},1} );}
                }
            }
        }
        else
        {
            ans[node] = 1;
            for( auto &i : negm[node] )
            {
                use[i] = 1;
                for( auto &j : posn[i] )
                {
                    if(pq.find( {{a[j],j},0} ) != pq.end() ){
                        pq.erase( pq.find( {{a[j],j},0} ));
                    a[j]--;
                    if( a[j] != 0 )
                        pq.insert( {{a[j],j},0} );}
                }
                for( auto &j : negn[i] )
                {
                    if( pq.find( {{b[j],j},1} ) != pq.end() )
                    {
                        pq.erase( pq.find( {{b[j],j},1} ) );
                        b[j]--;
                        if( b[j] != 0 )
                            pq.insert( {{b[j],j},1} );
                    }
                }
            }
        }
    }
    bool f=0;
    for(int i=1;i<=n;i++) if( !use[i] ) f=1;
    if(f) cout <<"IMPOSSIBLE";
    else
    {
        for(int i=1;i<=m;i++) cout << (ans[i]==1?'-':'+') << " " ;
    }
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
