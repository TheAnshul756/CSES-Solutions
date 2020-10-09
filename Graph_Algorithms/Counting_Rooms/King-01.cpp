// Problem Link = https://cses.fi/problemset/task/1192
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
    So here we use the fact that each room will be reachable from any point inside it to any other point inside it, now since wall cannot be room, we can solve this question either by BFS or DFS, but I've used DFS here.
    Since the logic behind the solution is pretty simple, let's walk through the solution - 
    1. Taking input, I've defined a global variable grid to store the map of the building, n for number of rows and m for nummber of columns, vis array to mark a floor ('.') cell visited if vis is true otherwise unvisited.
    2. initializing vis array to false by default, and counter to 0 where counter denotes number of rooms in our grid.
    3. we walk through the grid, if we find a cell that is a floor('.') and unvisited, we start dfs from that cell.
    4. In dfs of each cell, we first mark it visited, since we can move in each of the 4 directions namely up, down, left and right, we check whether it's valid to move in that cell by checking that the cell is inside boundry, is floor and unvisited, if so we recurse till we reach all the reachable cells in this dfs and mark them visited.
    5. Since each dfs call in our iteration increased a room, thus counter stores the final count of room and is thus our required output.
    I've further marked each step in the code also, you'll se something like step 1 begins, step 1 ends etc.
    End of the solution.
*/
int n, m;
string grid[1001];
bool vis[1001][1001];
// Step 4 begins
void dfs(int i, int j)
{
	vis[i][j] = 1;
	if(i && grid[i-1][j] == '.' && !vis[i-1][j])dfs(i-1, j);
	if(i < n && grid[i+1][j] == '.' && !vis[i+1][j])dfs(i+1, j);
	if(j < m && grid[i][j+1] == '.' && !vis[i][j+1])dfs(i, j+1);
	if(j && grid[i][j-1] == '.' && !vis[i][j-1])dfs(i, j-1);
}
// Step 4 ends
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tests = 1;
//    cin >> tests;
    while(tests--)
    {
        // Step 1 begins
        cin >> n >> m;
        rep(i,0,n)
        {
            cin >> grid[i];
        }
        int counter = 0;
        // Step 1 ends
        // Step 2 begins
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                vis[i][j] = false;
            }
        }
        // Step 2 ends
        // Step 3 begins
        rep(i,0,n)
        {
        	rep(j,0,m)
        	{
        		if(grid[i][j] == '.' && !vis[i][j]){
        			dfs(i, j);
        			counter++;
        		}
        	}
        }
        // Step 3 ends
        // Step 5 begins
        cout << counter << endl;
        // Step 5 ends
    }
    return 0;
}