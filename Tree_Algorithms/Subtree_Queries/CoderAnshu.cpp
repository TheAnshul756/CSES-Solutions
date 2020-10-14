#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 200005;

vector<int> v[N]; // adj list

ll val[N];

int in[N],out[N];
int cur = 1;// cur _size_of_array

// for_storing_the_dfs_order(flattening the tree)

// BIT - > Binary Indexed Tree
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

void dfs(int s,int p)
{
    // s -> source p-> parent
    in[s] = cur ++ ;
    for(int &j:v[s])
        if(j!=p)
            dfs(j,s);
    out[s] = cur-1;
}

int main()
{
    int n,Q;
    cin>>n>>Q;
    for(int i=1;i<=n;++i)
        cin>>val[i];
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y),v[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;++i)
    {
        // intializing the values
        fenw.a[in[i]] = val[i];
    }
    fenw.build(n);
    for(int i=0;i<Q;++i)
    {
        int tt,s,x;
        cin>>tt>>s;
        if(tt==1)
        {
            cin>>x;
            // update in the fenwick tree
            fenw.update(in[s],x-val[s]);
            val[s] = x;
        }
        else
            cout<<fenw.query(in[s],out[s])<<"\n";
    }
}
// the core concept in this question is that if we flatten the tree using dfs_order then any of the node's
// subtree will always form a continous range and we can efficiently use range query data structures