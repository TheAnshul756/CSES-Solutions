// Problem Link = https://cses.fi/problemset/task/1666
#include<bits/stdc++.h> 
// *****************************Template Begins ************************** //
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
    This question can also be solved by DSU but I've used DFS, logic behind this question is that since we're given undirected graph, we will have several connected components(or maybe 1), now minimum number of roads required to connect them is size of connected component - 1, you can feel it like, if we have 3 connected components containing several vertices, let's assume, Component 1 has a vertex 1, 2 has vertex 2 and 3 has vertex 3, since the graph is undirected, optimal strategy to merge these 3 components will be to build a road between 1 and 2, 1 and 3. Now you can look that for 3 components we created 2 components, since we merge all components into 1. 
    Since the logic behind the solution is pretty simple, let's walk through the solution - 
    1. Taking input, list of global variables defined along with their work - 
        i.   n, m is number of vertices and edges respectively.
        ii.  Vector edge, is the adjaceny list for the graph.
        iii. vis is the array which is true, if that vertex is visited, false otherwise.
    2. Since the graph is undirected, we walk through the edges from 1 to n and if that vertex is unvisited, it means that it is in different connected component, so we run dfs from this vertex and push this vertex in a vector, which marks that this vertex is in different connected component for further steps.
    3. Now we output minimum number of edges required to connect all the components as size of head of components(v) - 1 and merge all the components from the first entry in v.
    I've further marked each step in the code also, you'int se something like step 1 begins, step 1 ends etc.
    End of the solution.
*/
int n, m;
vi edge[N];
bool vis[N];
void dfs(int node)
{
	vis[node]=1;
	for(auto i:edge[node])
	if(!vis[i])
	dfs(i);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tests = 1;
//    cin >> tests;
    while(tests--)
    {
        // step 1 begins
    	vi v;
        cin >> n >> m;
        rep(i, 0, m)
        {
        	int a, b;
        	cin >> a >> b;
        	edge[a].pb(b);
        	edge[b].pb(a);
        }
        // step 1 ends
        // step 2 begins
        rep(i, 1, n+1)
        {
        	if(!vis[i])
        	{
        		v.pb(i);
        		dfs(i);
        	}
        }
        // step 2 ends
        // step 3 begins
        cout << sz(v) - 1 << endl;
        rep(i, 1, sz(v))
        {
            cout << v[0] << " " << v[i] << endl;
        }
        // step 3 ends
    }
    return 0;
}