#include<bits/stdc++.h>
using namespace std;
#define N  100005

int dp[N];
vector<int> a[N];
bool vis[N];
stack<int> st;


void dfs(int node) {
	vis[node] = 1;
	for(auto i : a[node]) {
		if(!vis[i]) {
			dfs(i);
		}
	}
	st.push(node);
}

void solve()
{
	/*
	Basic idea is to Topological sort the whole graph. Then apply dynamic programming to calcualte the number of 
	ways where dp[i] denotes number of ways to go to n from i. This dp[n] would be initailsed 1. And 
	dp[node] = sum(dp[i]) for all childerns of node.
	*/
	int n,m,x,y;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x].push_back(y);
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			dfs(i);
		}
	}

	dp[n] = 1;
	vector<int> tmp;
	
	while(!st.empty()) {
		tmp.push_back(st.top());
		st.pop();
	}
	
	for(int z = tmp.size() - 1; z >= 0; z--) {
		int node = tmp[z];
		for(auto i:a[node]) {
			dp[node] += dp[i];
			dp[node] %= 1000000007;
		}
	}

	cout<< dp[1] << endl;
	return;
}
int main()
{
	solve();
	return 0;
}