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
#define int           ll


int solve()
{
	int n;
	cin >> n;
	int x;
	cin >> x;
	int arr[n];
	rep(i, 0, n)
	cin >> arr[i];
	int pre[n + 1];
	map<int, int> check;
	check[0]++;
	mem0(pre);
	int ans = 0;
	rep(i, 1, n + 1)
	{
		pre[i] = pre[i - 1] + arr[i - 1];
		int y = pre[i] - x;
		ans += check[y];
		check[pre[i]]++;
	}
	cout << ans;
	return 0;
}
signed main()
{
	FAST
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t = 1;
	//cin>>t;
	while (t)
	{
		solve();
		t--;
	}
	return 0;
}