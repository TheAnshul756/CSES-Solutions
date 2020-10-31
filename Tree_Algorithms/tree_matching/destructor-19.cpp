# include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define eb          emplace_back
#define endl		'\n'
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define vi          vector<int>
#define vii         vector<pair<int, int> >
#define mp          make_pair
#define mem1(a)     memset((a),-1,sizeof(a))
#define mem0(a)     memset((a),0,sizeof(a))
#define memf(a)     memset((a),false,sizeof(a))
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    (a)*((b)/gcd((a),(b)))
#define DECIMAL(n)  cout << fixed ; cout << setprecision(n);
#define FAST        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mi          map<int,int>
#define sz(x)       (ll)(x).size()
#define rep(i,a,b)  for(int i=(a);i<(b);i++)
#define pii         pair<int,int>
#define MAX          200005

inline long long  MAX2(long long  a, long long  b) {return (a) > (b) ? (a) : (b);}

vector<int>adj[MAX];
ll dp[MAX][2];

void dfs (int src, int par) {
	int leaf = 1;
	dp[src][1] = 0;
	dp[src][0] = 0;

	for (auto child : adj[src]) {
		if (child != par) {
			leaf = 0;
			dfs(child, src);
		}
	}
	if (leaf == 1)return ;

	for (auto child : adj[src]) {
		if (child != par) {
			dp[src][0] += MAX2(dp[child][0], dp[child][1]);

		}
	}

	for (auto child : adj[src]) {
		if (child != par) {
			dp[src][1] = MAX2(dp[src][1], 1 + dp[child][0] + ( dp[src][0] - MAX2(dp[child][0], dp[child][1])));
		}
	}

}


int solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int ss, ee;
		cin >> ss >> ee;
		adj[ss].pb(ee);
		adj[ee].pb(ss);
	}
	dfs(1, 0);
	cout << MAX2(dp[1][0], dp[1][1]) << endl;
	return 0;
}
signed main()
{
	FAST
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t = 1;
	//cin >> t;
	while (t)
	{
		solve();
		t--;
	}
	return 0;
}