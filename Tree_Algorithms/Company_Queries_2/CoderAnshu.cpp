#include<bits/stdc++.h>
using namespace std ;

#define ll long long

const int N=200005;
const int LOGN=20; // approximate logn for 2e5

// adj list
vector<int> v[N];
int dep[N],par[N][LOGN];


/*  The technique here is same as in the previous question Company Queries 1 .

    Here we just need to find the first(deepest) node which is the ancestor of both u and v given two
    vertices u and v. 

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
    for(int i=2;i<=n;++i)
    {
        int p;
        cin>>p;
        v[p].push_back(i),v[i].push_back(p);
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
        cout<<lca(u,v)<<'\n';
    }

    return 0;
}