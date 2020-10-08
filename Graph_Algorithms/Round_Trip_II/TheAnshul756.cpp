#include<bits/stdc++.h>
using namespace std;
#define N 	100005

vector<int> stronglyConnectedNode; // vector to store strongly connected component
vector<int> cycle; // vector to store cycle 
vector<int> conn[N], reverseConn[N];
stack<int> topoOrder; // stack for topological sorting 
bool visited[N],visited2[N];
bool cycleFound; // global variable to end recursion when cycle found

void findCycle(int node) {
	visited[node] = 1;
	visited2[node] = 1;
	cycle.push_back(node);

	for(auto i : conn[node]) {
		if(!visited[i]) {
			findCycle(i);
		} else if(visited2[i]) {
			cycle.push_back(i);
			cycleFound = true;
			return;
		}
		if(cycleFound) {
			return;
		}
	}
	if(cycleFound) {
		return;
	}

	cycle.pop_back();
}

void topoSort(int node) {
	visited[node] = true;
	for(auto i : conn[node]) {
		if(!visited[i]) {
			topoSort(i);
		}
	}
	topoOrder.push(node);
}

void dfs(int node) {
	visited[node] = 1;
	stronglyConnectedNode.push_back(node);

	for(auto i: reverseConn[node]) {
		if(!visited[i]) {
			dfs(i);
		}
	}
}
 
//  Solution starts here
void solve() {
	/*
		So our task is to find a cycle in directed graph. Which is similar to find a Strongly Connected Component.
		But its not exactly same as strongly connected component have many cycles. So we are goinf to use Kosaraju's Algorithm
		to find strongly connected compopnent.(If you don't know this then read about it first.) Then once we have found a SCC 
		(strongly connected compomnent) of size greater than 1 length then we need to find a cycle in it. We can use cycle 
		detection algorithm here to detect cycle and while doing so we will also store the depth till that in a vector to print 
		that cycle. That vector will look somewhat like this:
								n6 -> n7 -> n1 -> n2 -> n2 -> n3 -> n4 -> n1
		here lenght of cycle is 4. Once we find a cycle we will use a global variable to end our recursion function and insure 
		not to delete from out cycle vector. Then we will iterate from backwads and store that cycle in a different vector.
		Note : because we are iterating backwards that cycle will be in reverse order so make sure to reverse it before printing.
	*/

	int n,m;
	cin >> n >> m;

	int a,b;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		conn[a].push_back(b);	// Original Graph
		reverseConn[b].push_back(a);  // Transpose of Graph
	}


	// topological sort
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			topoSort(i);
		} 
	}
	
	memset(visited,false,sizeof(bool)*(n+1));
	
	//  searching for SCC in transpose graph
	while(!topoOrder.empty()) {
		int node = topoOrder. top();
		topoOrder.pop();

		if(!visited[node]) {
			
			stronglyConnectedNode.clear();

			dfs(node);

			if(stronglyConnectedNode.size() > 1) {
				//  SCC found
				break;
			}

		}
	}
	if(stronglyConnectedNode.size() <= 1) {
		//  No SCC thus no cycle.
		cout << "IMPOSSIBLE\n";
		return;
	}

	// Cycle detection algorithm
	cycleFound = false;
	// rest all nodes which are not in SCC are marked visited so that we do not traverse through them
	memset(visited,true,sizeof(bool)*(n+1));
	for(auto node: stronglyConnectedNode) {
		visited[node] = 0;
	}
	findCycle(stronglyConnectedNode[0]);
	

	vector<int> out;
	int node = cycle.back();
	cycle.pop_back();
	
	//  getting node of cylce from backwards
	out.push_back(node);
	while(cycle.back() != node) {
		out.push_back(cycle.back());
		cycle.pop_back();
	}
	out.push_back(node);

	//  reversing cycle
	reverse(out.begin(),out.end());
	cout << out.size() << endl;
	for(auto i : out) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	// solution is in solve function
	solve();
	return 0;
}
