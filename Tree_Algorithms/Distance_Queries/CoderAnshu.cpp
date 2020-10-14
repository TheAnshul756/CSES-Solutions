#include<bits/stdc++.h>
using namespace std ;
 
#define ll long long
 
const int N=200005;
const int LOGN=20; // approximate logn for 2e5
 
// adj list
vector<int> v[N];
int dep[N],par[N][LOGN];
 
 
/*  We only need to calculate lca of two vertices.

    For detailed explanation on how to calculate LCA efficiently , refer to Questions -> Comapny Queries 1 and 2
 
*/
 
void dfs(int s,int p)
{
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j]=dep[s]+1,par[j][0]=s;
            dfs(j,s);
        }
    }
}
 
// lca -> lowest common ancestor
int lca(int u,int v)
{
    if(dep[u]>dep[v])
        swap(u,v);
 
    // df -> difference
    int df=dep[v]-dep[u];
    // first we raise the vertex v to the same level as of vertex u and this is exactly
    // same as lifting it to its (dep[v] - dep[u])th  parent, which we did earlier.
 
    for(int i=0;i<LOGN;++i)
        if(df&(1<<i))v=par[v][i];
 
    // now u and v are at same level
 
    // if (u==v) then we have found our lca and we are done
    if(u==v)
        return u;
 
    /*  Here we check for 2^i th parents and if they are not same then we jump both nodes to their 
        respective parents .
        In this way when the loop terminates we are just below out lca and our answer is 
        either par[u][0] (immediate parent of u) or par[v][0];
    */
 
    for (int i=LOGN-1; i>=0; i--) 
    {
        if(par[u][i]!=par[v][i]) 
        { 
            u=par[u][i]; 
            v=par[v][i];
        } 
    }
    return par[u][0]; 
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y),v[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<LOGN;++i)
    {
        for(int j=1;j<=n;++j)
        {
            // DP type construction of parent array
            par[j][i]=par[par[j][i-1]][i-1];
        }
    }
 
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        int l = lca(u,v);

        /*  For length of path between u and v :
            Any path between two vertices in a tree can be decomposed into two paths of
            u -> lca and lca -> v and there is always one unique path in a tree between any two vertices
            Now , out answer is just (dep[u] + dep[v] - 2*dep[lca]) since lca is ancestor of both u and v
            and their path can be simply computed using depth of the nodes .
        */
        cout << dep[u] + dep[v] - 2*dep[l] << "\n";
    }
 
    return 0;
}
