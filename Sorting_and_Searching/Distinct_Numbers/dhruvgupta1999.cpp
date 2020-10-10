/*input
5
2 3 2 2 3
*/
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ll long long int
#define vll vector<ll>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 9000000000000000001
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b-1;i>=a;i--) 
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define sz(x)  ((ll)x.size())
#define DEBUG
#ifdef DEBUG
#define dbg(x) cout << (#x) << " is " << (x) << endl
#else 
#define dbg(x)
#endif
#define N 200002

using namespace std;
int main()
{
	fastio
	ll T=1,n,m;string str;
	// cin>>T;
	// cin.ignore(); put after cin, just b4 a getline(cin, s) to avoid getline() directly getting \n
	while(T--)
	{
		ll p=0,q=0,tmp=0,sum=0,cnt=0; //tmp variable
		int flag=0;
		
		cin>>n;
		ll a[n];
		set <int> s;
		for(ll i=0;i < n;i++)
		{
			cin>>a[i];
			s.insert(a[i]);
		}

		cout << s.size() << endl;

		

		
	}
	return 0;
}