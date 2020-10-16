#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
#define pii pair<ll int, ll int>
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define repi(i, n) for(ll i=0; i<n; i++)
#define rep(i, a, b) for(ll i=a; i<=b; i++)
#define M 1000000007
#define INF 1e18
 
using namespace std;
 
void build(vector <ll> &v, vector <ll> &tree, ll i, ll j, ll root){
	if(i==j) {tree[root] = v[i]; return;}
	ll m = (i+j)/2;
	build(v, tree, i, m, 2*root+1); build(v, tree, m+1, j, 2*root+2);
	tree[root] = tree[2*root+1] + tree[2*root+2];
}
 
void update(vector <ll> &tree, ll i, ll j, ll root, ll k, ll u) {
    if(i == j) {tree[root] = u; return;}
    ll m = (i+j)/2;
    if(k <= m) update(tree, i, m, 2*root+1, k, u);
    else update(tree, m+1, j, 2*root+2, k, u);
    tree[root] = tree[2*root+1] + tree[2*root+2];
}
 
ll query(vector <ll> &tree, ll i, ll j, ll root, ll l, ll r){
	if(r < i || l > j) return 0;
	if(l <= i && j <= r) return tree[root];
	ll m = (i+j)/2;
	ll left = query(tree, i, m, 2*root+1, l, r);
	ll right = query(tree, m+1, j, 2*root+2, l, r);
	return left + right;
}
 
int main() {
    ios
    ll n, q;
    cin>>n>>q;
    vector <ll> v(n);
    repi(i, n) cin>>v[i];
    vector <ll> tree(4*n+5);
    build(v, tree, 0, n-1, 0);
    while(q--){
    	ll t; cin>>t;
    	if(t==1){
    		ll k, u;
    		cin>>k>>u;
    		k--; 
    		update(tree, 0, n-1, 0, k, u);
    	}
    	else{
    		ll a, b;
    		cin>>a>>b;
    		a--; b--;
    		cout<<query(tree, 0, n-1, 0, a, b)<<endl;
    	}
    }
    return 0;
}
