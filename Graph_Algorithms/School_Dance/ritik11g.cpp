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
 
struct Hopcroft_Karp
{
	int n,m;
	vector<int> matchL, matchR, dist;
	vector<vector<int> > g;
 
	Hopcroft_Karp(int n,int m) :
		n(n), matchL(n+1), matchR(m+1), dist(n+1), g(n+1) {}
 
	void addEdge(int u, int v)
	{
		g[u].push_back(v);
	}
 
	bool bfs()
	{
		queue<int> q;
		for(int u=1;u<=n;u++)
		{
			if(!matchL[u])
			{
				dist[u]=0;
				q.push(u);
			}
			else
				dist[u]=inf;
		}
		dist[0]=inf;
 
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(auto v:g[u])
			{
				if(dist[matchR[v]] == inf)
				{
					dist[matchR[v]] = dist[u] + 1;
					q.push(matchR[v]);
				}
			}
		}
 
		return (dist[0]!=inf);
	}
 
	bool dfs(int u)
	{
		if(!u)
			return true;
		for(auto v:g[u])
		{
			if(dist[matchR[v]] == dist[u]+1 &&dfs(matchR[v]))
			{
				matchL[u]=v;
				matchR[v]=u;
				return true;
			}
		}
		dist[u]=inf;
		return false;
	}
 
	void max_matching()
	{
		int matching=0;
		while(bfs())
		{
			for(int u=1;u<=n;u++)
			{
				if(!matchL[u])
					if(dfs(u))
						matching++;
			}
		}
		cout << matching << "\n";
        for( int i=1 ; i<=n ; i++ )
            if( matchL[i] )
                cout << i << " " << matchL[i] << "\n";
	}
};
 

void solve()
{
  //code begins from here//
    int n , m , k;
    cin >> n >> m >> k;
    Hopcroft_Karp a(n,m);
    for(int i=1; i<=k ; i++ )
    {
        int u, v;
        cin >> u >> v;
        a.addEdge(u,v);
    }
    a.max_matching();
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
