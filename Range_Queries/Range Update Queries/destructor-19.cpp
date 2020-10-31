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
#define int         ll



struct FenwickTree {
	vector<int> bit;
	int n;

	FenwickTree(int n) {
		this->n = n;
		bit.assign(n, 0);
	}

	FenwickTree(vector<int> a) : FenwickTree(a.size()) {
		for (size_t i = 0; i < a.size(); i++)
			add(i, a[i]);
	}

	int sum(int r) {
		int ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ret += bit[r];
		return ret;
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, int delta) {
		for (; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
	}
};



int solve()
{
	int n;
	cin >> n;
	int q;
	cin >> q;
	int arr[n];
	rep(i, 0, n)
	cin >> arr[i];
	vi abc;
	abc.assign(n + 2, 0);
	struct FenwickTree obj(abc);
	rep(i, 0, q)
	{
		int d;
		cin >> d;
		if (d == 1)
		{
			int a, b, u;
			cin >> a >> b >> u;
			obj.add(a, u);
			obj.add(b + 1, -u);
		}
		else
		{
			int k;
			cin >> k;
			int r = obj.sum(k);
			cout << r + arr[k - 1] << endl;
		}
	}
	return 0;
}
signed main()
{
	FAST
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t = 1;
	//  cin>>t;
	while (t)
	{
		solve();
		t--;
	}
	return 0;
}