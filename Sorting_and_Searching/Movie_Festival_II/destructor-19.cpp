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

int solve()
{
	int n, k; cin >> n >> k;
	vector<pair<int, int>>v(n);
	for (int i = 0; i < n; ++i)
	{
		int x, y; cin >> x >> y;
		v[i] = {y, x};
	}
	sort(v.begin(), v.end());
	multiset<int, greater<int>>s;
	s.insert(v[0].first);
	for (int i = 0; i < k - 1; ++i)s.insert(0);
	int cnt = 1;
	for (int i = 1; i < n; ++i)
	{
		auto it = s.lower_bound(v[i].second);
		if ((*it) == s.size())
		{
			if ((*it) <= v[i].second and s.find(v[i].second) != s.end())
			{
				s.erase(it);
				s.insert(v[i].first);
				cnt++;
			}
		}
		else
		{
			s.erase(it);
			s.insert(v[i].first);
			cnt++;
		}
	}
	cout << cnt << endl;

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