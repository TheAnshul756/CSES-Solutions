#include<bits/stdc++.h>
using namespace std ;

#define ll long long

const int N=200005;
const int LOGN=20; // approximate logn for 2e5

// adj list
vector<int> v[N];
int dep[N],par[N][LOGN];


/*  The main technique used in this question is binary lifting .
    
    Example : We want to find the kth parent of some node .
    We can not do so by jumping over the parents as that would be order n**2 and extremely slow for chain 
    like trees .

    Here we store (2^i) parent for each node for each i from 0 to LOGN . This requires O(nlogn) memory.

    Now the basic trick is that we have stored all 2^i th parents for each node (where 2^0 = 1 is the 
    immediate parent of that node and rest can be computed in DP fashion).
    Like for (2^i) th parent of current node we take (2^(i-1)) parent of the (2^(i-1)) th parent of 
    current node . ( 2^(i-1) + 2^(i-1) = 2^i)

    Now suppose we want to find the kth parent of a node , suppose k = 13
    13 = 1101 (binary)
    then we jump over the set bits of k
    like first we go to 2^0 th parent of current node and then 2^2 parent of current node then 2^3
    parent of current node and we are done as we have traversed (2^0 + 2^2 + 2^3 = 13) nodes and 
    now we are at the required parent node .

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

int lift(int u,int k)
{
    for(int i=0;i<LOGN;++i)
    {
        // just jumping from parent to parent on set bits . 
        if(k&(1<<i))
        {
            u=par[u][i];
        }
    }

    // if(u==0) then the kth parent doesn't exist and we need to print(-1);
    return u==0?-1:u;
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
        cout<<lift(u,v)<<'\n';
    }

    return 0;
}