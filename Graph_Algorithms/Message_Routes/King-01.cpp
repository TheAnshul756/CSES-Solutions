// Problem Link = https://cses.fi/problemset/task/1667
#include<bits/stdc++.h> 
// *****************************Template Begins ************************** //
#define int                long long int
#define pb                 push_back                                                     
#define s                  second
#define mii                map<int ,int >
#define dbg(x)             { cerr<<#x<<": "<<x<< endl; }
#define dbg2(x,y)          { cerr<<#x<<": "<<x<<" , "<<#y<<": "<<y<<endl; }
#define rep(i, a, b)         for(int  i=a;i<b;i++)
#define pii                pair<int ,int >
#define ppb                pop_back
#define f                  first 
#define vi                 vector<int >
#define vii                vector<pair<int , int >>
#define si                 set <int>
#define all(a)             (a).begin(),(a).end()
#define sz(x)              (int )x.size()
#define hell               1000000007
#define mp                 make_pair
#define yes                cout << "YES" << endl;
#define no                 cout << "NO" << endl;
#define inf                1e18L+1
#define endl               '\n' 
using namespace std;
#define N  300005
// *****************************Template ends **************************** //
/* 
    Solution - 
    So in this question we have to find shortest path in an undirected graph for a destination from a source. To do these kind of problems, implementing BFS is pretty standard, and i've also done the same.
    Since the logic behind the solution is pretty simple, let's walk through the solution - 
    1. Taking input and initializing variables, list of global variables defined along with their work - 
        i.   n, m is number of vertices and edges respectively.
        ii.  Vector edge, is the adjaceny list for the graph.
        iii. vis is the array which is true, if that vertex is visited, false otherwise.
        iv. dist is the array which stores smallest distance of a vertex v from source s, and is equal to a large value(inf) if it is unreachable from source. 
    2. Now we apply BFS, we have implemented standard bfs traversal using queue, if you are unaware about its implementation, google it.
    3. If the destination vertex is unreachable, we output IMPOSSIBLE, otherwise, we backtrack from our destination vertex to the source.
    I've further marked each step in the code also, you'int se something like step 1 begins, step 1 ends etc.
    Time Complexity Analysis - O(V + E) (V = Vertices and E = Edges) (since we're implementing BFS, each entry in adjacency list will be visited atmost once, and there are O(E) such entries and V vertices will be visited by BFS in worst case, for the backtracking part, O(E) entries will be used to reach source in the worst case and also O(V) vertex will be backtracked).
    End of the solution.
*/
int n, m, dist[N], vis[N];
vi edge[N];
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tests = 1;
//    cin >> tests;
    while(tests--)
    {
        // step 1 begins.
    	cin >> n >> m;
    	rep(i, 0, m)
    	{
    		int a,b;
    		cin >> a >> b;
    		edge[a].pb(b);
    		edge[b].pb(a);
    	}
    	rep(i, 1, n+1)dist[i] = inf;
    	rep(i, 1, n+1)vis[i] = 0;
        // step 1 ends.
        // step 2 begins.
    	queue<int> q;
    	q.push(1);
    	dist[1] = 1;
    	while(!q.empty())
    	{
    		// cout << 1;
    		int k = q.front();
    		q.pop();
    		if(vis[k])continue;
    		vis[k] = 1;
    		for(auto itr:edge[k])
    		{
    			if(!vis[itr])
    			q.push(itr);
    			dist[itr] = min(dist[itr], dist[k]+1);
    		}
    	}
        // step 2 ends.
        // step 3 begins.
    	if(dist[n] == inf)
    	{
    		cout << "IMPOSSIBLE";
    		return 0;
    	}
    	int node = n;
    	vi ans ;
    	cout << dist[n] << endl;
    	while(dist[node] > 1)
    	{
    		ans.pb(node);
    		for(auto itr:edge[node])
    		{
    			if(dist[itr] == dist[node] - 1)
    			{
    				node = itr;
    				break;
    			}
    		}
    	}
    	ans.pb(node);
    	reverse(all(ans));
    	for(auto itr:ans)cout << itr << " ";
        // step 3 ends.
    }
    return 0;
}