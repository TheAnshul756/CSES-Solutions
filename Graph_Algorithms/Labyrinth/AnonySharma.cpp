#include <bits/stdc++.h>
using namespace std;
 
//DEFINE and TYPEDEF--------------------------------------------------------------
#define SPEEDUP ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define st first
#define nd second

typedef long long int lld;
//--------------------------------------------------------------------------------
 
lld n,m;
char arr[1002][1002];
queue<pair<lld,lld>> q; //Queue for BFS
bool visited[1002][1002];
map<pair<lld,lld>,pair<lld,lld>> parent; //if parent[{a,b}]={c,d} then (a,b) was visited just after visiting (c,d)
 
void bfs(lld x, lld y)
{
	q.push({x,y});
	visited[x][y]=1;
 
	while(q.size()) // Normal BFS
	{
		pair<lld,lld> temp=q.front();
		q.pop();
 
		x=temp.st;
		y=temp.nd;
 
		if(arr[x][y]=='B') // If found B then break
			break;
 
		if(x) //If going left is possible, add it to the queue 
		{
			if(!visited[x-1][y] and arr[x-1][y]!='#')
			{
				parent[{x-1,y}]={x,y};
				q.push({x-1,y});
			}
			
			visited[x-1][y]=1; //Mark it visited
		}
 
		if(y) //If going up is possible, add it to the queue
		{
			if(!visited[x][y-1] and arr[x][y-1]!='#')
			{
				parent[{x,y-1}]={x,y};
				q.push({x,y-1});
			}
			
			visited[x][y-1]=1; //Mark it visited
		}
		
		if(x<n-1) //If going right is possible, add it to the queue
		{
			if(!visited[x+1][y] and arr[x+1][y]!='#')
			{
				parent[{x+1,y}]={x,y};
				q.push({x+1,y});
			}
			
			visited[x+1][y]=1; //Mark it visited
		}
		
		if(y<m-1) //If going down is possible, add it to the queue
		{
			if(!visited[x][y+1] and arr[x][y+1]!='#')
			{
				parent[{x,y+1}]={x,y};
				q.push({x,y+1});
			}
		
			visited[x][y+1]=1; //Mark it visited
		}
	}
}
 
int main()
{
    SPEEDUP;
	lld x,y,a,b;
	cin>>n>>m;
 
	for(lld i=0;i<n;i++)
	for(lld j=0;j<m;j++)
	{
		cin>>arr[i][j];
		if(arr[i][j]=='A')
			x=i,y=j; //Storing the location of 'A'
		else if(arr[i][j]=='B')
			a=i,b=j; //Storing the location of 'B'
	}
 
	bfs(x,y);
	cout<<(visited[a][b]?"YES\n":"NO");

	if(visited[a][b])
	{
		vector<pair<lld,lld>> path;
		while(1)
		{
			path.push_back({a,b});
			if(x==a and y==b) // If reached the location of 'B' then break
				break;
 
			lld ta=a,tb=b;
			a=parent[{ta,tb}].st;
			b=parent[{ta,tb}].nd;
		}
 
		reverse(path.begin(), path.end()); //Since we have to give the path from A to B, we need to reverse it
		string s;
		for(lld i=0;i<path.size();i++)
		{
			if(i!=(lld)path.size()-1)
			{
				if(path[i].st==path[i+1].st and path[i].nd<path[i+1].nd)
					s+='R';
				if(path[i].st==path[i+1].st and path[i].nd>path[i+1].nd)
					s+='L';
				if(path[i].st<path[i+1].st and path[i].nd==path[i+1].nd)
					s+='D';
				if(path[i].st>path[i+1].st and path[i].nd==path[i+1].nd)
					s+='U';
			}
		}
 
		cout<<s.length()<<endl<<s;
	}
	return 0;
}
