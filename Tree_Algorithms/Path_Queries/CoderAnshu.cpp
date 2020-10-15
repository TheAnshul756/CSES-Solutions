#include<bits/stdc++.h>
using namespace std ;

#define ll long long

const int N=200005;
 
template<typename T=long long>
struct fenwick {
    T a[N],bit[N];
    int n;
    fenwick() 
    {
        for(int i=1;i<=N-2;++i)
            a[i] = T(0),bit[i] = T(0);
    }
    void build(int n_)
    {
        n = n_;
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;j+=j&-j)
                bit[j] += a[i];
    }
    void update(int j,T val)
    {
        for(;j<=n;j+=j&-j)
            bit[j] += val;
    }
    T get(int r)
    {
        T u = 0;
        for(;r;r-=r&-r)
            u += bit[r]; 
        return u;
    }
    T query(int l,int r)
    {
        return get(r)-get(l-1);
    }
};
// call fenw.build(n);
fenwick<ll> fenw;
 
vector<int> v[N];

// entry time and exit time
int cur=1,in[N],out[N];
ll val[N];
ll intial_sum_to_root[N];
 
// flatten the tree using dfs_order
void dfs(int s,int p,ll u=0)
{
    in[s]=cur++;
    u += val[s];
    intial_sum_to_root[s] = u;

    for(auto j:v[s])
    {
        if(j!=p)
        {
            dfs(j,s,u);
        }
    }

    out[s]=cur-1;
}

/*  The logic here is that if you update a node then only the nodes in the subtree of that node 
    will get affected i.e if you add some val to node X then the answer for the nodes in the subtree
    of that node will also be +=val since the node X is in the root to node path for every such node .

    Here we need to add a value to a range which we can do using fenwick trees

    Suppose we need to value = x in the range (l,r)
    then we a[l] += x and a[r+1] -= x;
    and whenever we need to get the value added at a particular index we just query for the prefix sum.
*/
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i)
        cin>>val[i];
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y),v[y].push_back(x);
    }
    dfs(1,0);

    fenw.build(n);

    while(q--)
    {
        int t,u;
        ll x;
        cin>>t>>u;
        if(t==1)
        {
            cin>>x;
            fenw.update(in[u],x-val[u]);
            fenw.update(out[u] + 1,val[u] - x);
            val[u]=x;
        }
        else
        {
            cout<<intial_sum_to_root[u] + fenw.get(in[u])<<'\n';
        }
    }

    return 0;
}
