#include<bits/stdc++.h> 
 
#define pb push_back
using namespace std; 
 
vector<vector<int> > g; 
int n; 
 
pair<int, int> bfs(int root){ 
    vector<int> dist(n+1, 0); 
    dist[root] = 1; 
    queue<int> q; 
    q.push(root); 
    while(!q.empty()){ 
        int curr = q.front(); 
        for(auto it : g[curr]){ 
            if(dist[it] != 0){ 
                continue; 
            } 
            q.push(it); 
            dist[it] = dist[curr] + 1; 
        } 
        q.pop(); 
    } 
    int mx = INT_MIN, vertex = -1; 
    for(int i=1 ; i<=n ; i++){ 
        if(mx < dist[i]){ 
            mx = dist[i]; 
            vertex = i; 
        } 
    } 
    return make_pair(mx, vertex); 
} 
 
int diameter(int root){ 
    pair<int, int> p1 = bfs(root), p2; 
    p2 = bfs(p1.second); 
    return p2.first - 1; 
} 
 
int main(){ 
    cin >> n; 
    g.resize(n+1); 
    for(int i=0, u, v ; i<n-1 ; i++){ 
        cin >> u >> v; 
        g[u].pb(v); 
        g[v].pb(u); 
    } 
    cout << diameter(1) ; 
    return 0; 
} 
