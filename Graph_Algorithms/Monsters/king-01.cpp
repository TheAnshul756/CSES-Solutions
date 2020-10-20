// problem link - https://cses.fi/problemset/task/1194
#include<bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
// #pragma GCC optimize("-O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
using namespace std;
using namespace __gnu_pbds;
#ifdef ON_LINUX  
#include <sys/resource.h>
#define meminc             rlimit rlim;if (getrlimit(RLIMIT_STACK, &rlim)) return 1;rlim.rlim_cur = 26843556;if (setrlimit(RLIMIT_STACK, &rlim)) return 2;
#else
#define meminc      
#endif
#ifdef LOCAL
#define dbg(args...)       { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#else
#define dbg(args...)
#endif
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
template<typename T,typename U> std::ostream& operator<<(std::ostream& out, std::pair<T,U> a) {
    out<< a.first << " " << a.second;
    return out;
}
 
template<typename T,typename U> std::istream& operator>>(std::istream& in, std::pair<T,U> &a) {
    in >> a.first >> a.second;
    return in;
}
#define int                long long int
#define ll                 int
#define x                  first
#define y                  second
#define pii                pair<int, int>
#define vii                vector<pii>
#define vi                 vector<int >
#define ordered_set        tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// -------------------Standard Traversal Moves---------------------
vi movement_in_x = {1 ,-1 ,0, 0}, movement_in_y = {0, 0, -1, 1};
// vi movement_in_x = {2, -2, 2, -2,  1, -1, 1, -1}, movement_in_y = {1, 1, -1, -1, 2, 2, -2, -2};
// vi movement_in_x = {1, 1, 1, -1, -1 , -1, 0, 0}, movement_in_y = {1, -1, 0, 1, -1, 0, 1, -1};
// ----------------------------------------------------------------

#define rep(i, a, b)       for(int  i=a;i<b;i++)
#define all(a)             (a).begin(),(a).end()
#define sz(x)              (int )x.size()
#define yes                cout << "YES" << endl
#define no                 cout << "NO" << endl
#define endl               '\n' 
// const int hell = (int)998244353;
const int hell = (int)1e9 + 7;
const int inf = 3223372036854775807;
const double PI = 3.14159265;
const int N = (int) 1e3 + 5;
int n, m, k, a[N];
string labyrinth[N];
int key = 0;
int is_visited[N][N];
char previous_move[N][N];
string path;
bool check(int x, int y)
{
	return (x > -1 and y > -1 and x < n and y < m);
}
void bfs(int starting_x, int starting_y)
{
	priority_queue<pair<pii, pii>> pq;
	rep(i, 0, n)
	{
		rep(j ,0, m)
		{
			if(labyrinth[i][j] == 'M')
			{
				pq.push({{0, 2}, {i, j}});
				is_visited[i][j] = 1;
			}
		}
	}
	pq.push({{0, 1}, {starting_x, starting_y}});
	is_visited[starting_x][starting_y] = 1;
	while(!pq.empty())
	{
		auto p = pq.top();
		pq.pop();
		int time = p.first.first, type = p.first.second, current_x = p.second.first, current_y = p.second.second;
		if(type == 1 and (current_x == 0 or current_y == 0 or current_x == n - 1 or current_y == m - 1))
		{
			key = 1;
			while(current_x != starting_x or current_y != starting_y)
			{
				path += previous_move[current_x][current_y];
				if(previous_move[current_x][current_y] == 'R')
				{
					current_y--;
				}
				else if(previous_move[current_x][current_y] == 'L')
				{
					current_y++;
				}
				else if(previous_move[current_x][current_y] == 'D')current_x--;
				else current_x++;
			}
			reverse(all(path));
			return ;
		}
		rep(i, 0, 4)
		{
			int new_x = current_x + movement_in_x[i], new_y = current_y + movement_in_y[i];
			if(!check(new_x, new_y) or is_visited[new_x][new_y] or labyrinth[new_x][new_y] == '#')continue;
			pq.push({{time - 1, type}, {new_x, new_y}});
			is_visited[new_x][new_y] = 1;
			if(movement_in_x[i] == 1)
			{
				previous_move[new_x][new_y] = 'D';
			}
			else if(movement_in_x[i] == -1)previous_move[new_x][new_y] = 'U';
			else if(movement_in_y[i] == -1)previous_move[new_x][new_y] = 'L';
			else previous_move[new_x][new_y] = 'R';
		}
	}

}
int32_t main()
{
  //  meminc;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cerr.precision(10);
    cout.precision(25);
    cout << fixed;
    #ifdef ON_LINUX
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int tests = 1;
    // cin >> tests;
    rep(test, 1, tests+1)
    {
        cin >> n;
        cin >> m;
        rep(i, 0, n)cin >> labyrinth[i];
    	memset(is_visited ,0, sizeof is_visited);
		int starting_x, starting_y;
    	rep(i, 0, n)
    	{
    		rep(j, 0 ,m)
    		{
    			if(labyrinth[i][j] == 'A')
    			{
    				starting_x = i;
    				starting_y = j;
    				bfs(starting_x, starting_y);
    				if(!key)no;
    				else
    				{
    					yes;
    					cout << sz(path) << endl;
    					cout << path << endl;
    				}
    				return 0;
    			}
    		}
    	}
    }
    #ifdef LOCAL
        // cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " labyrinth.\n";
    #endif
    return 0;
}
