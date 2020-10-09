#include<bits/stdc++.h>
#define N 2000006
#define hell 1000000007
#define maxN 10000000+10
#define ll long long
#define mod (ll)1e9+7
using namespace std;
vector<ll> adj[maxN];
ll depth[maxN]={0};
ll n,m;

/* first make dfs call from any node and get the farthest node from that root node*/
/* then take this farthest node as root node and then do another dfs and get farthest node*/
/*distance between these two node will be the diameter of the tree*/
void dfs(ll root,ll par=-1)
{
	if(par==-1)
		depth[root]=0;
	else
		depth[root]=depth[par]+1;
	for(auto x:adj[root])
	{
		if(x!=par)
		{
			dfs(x,root);
		}
	}
}
void solve(long long cno)
{
 
cin>>n;
for(ll i=0;i<n-1;i++)
{
	ll j,k;
	cin>>j>>k;
	j--;k--;
	adj[j].push_back(k);
	adj[k].push_back(j);
}
 
dfs(0);
 
int root=-1;
int mx=0;
for(auto i=0;i<n;i++)
{
	if(depth[i]>mx)
	{
		mx=depth[i];
		root=i;
	}
}
dfs(root);
 
cout<<*max_element(depth,depth+n);

}

 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long TESTS=1;
	// cin>>TESTS;
	long long i=1;
	while(TESTS--)
	{
		solve(i);
		i++;
	}
	return 0;
}
