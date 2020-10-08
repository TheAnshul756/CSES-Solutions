#include<bits/stdc++.h>
using namespace std;
#define N  100005

vector<int> req[N];
int visited[N];
bool isPossible;
stack<int> topoOrder;

void dfs(int node) {
	visited[node] = 1;

	for(auto i : req[node]) {
		if(!visited[i]) {
			dfs(i);
		} else if(visited[i] == 1) {
			isPossible = 0;
		}
	}

	visited[node] = 2;
}

void topoSort(int node) {
	visited[node] = 1;
	for(auto i : req[node]) {
		if(!visited[i]) {
			topoSort(i);
		}
	}
	topoOrder.push(node);
}

//  Soultion Start here
void solve()
{
	/*
	All courses and there requirements will form a directed graph.
	We first check if there exist a cycle in this directed graph. If yes, then its impossible to assign subjects.
	else we will topological sort the graph and print it.
	*/
	int n,m;
	cin >> n >> m;

	int a,b;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		req[a].push_back(b);
	}

	isPossible = 1;

	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			dfs(i);
		}
	}

	if(!isPossible) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	memset(visited,0,sizeof(int)*(n+1));
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			topoSort(i);
		}
	}

	while(!topoOrder.empty()) {
		cout << topoOrder.top() << " ";
		topoOrder.pop();
	}
	cout << endl;

	return;
}

int main()
{
	solve();
	return 0;
}