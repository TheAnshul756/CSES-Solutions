#include<iostream>
using namespace std;

const int N = 200005;

// BIT -> Binary Indexed Tree
// can support point update and range_sum queries
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
        // adds val to a[j] -> a[j] += val;
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

fenwick<> fenw;
// call fenw.build(n);

int main()
{
    int n,Q;
    cin>>n>>Q;
    for(int i=1;i<=n;++i)
    {
        // initializing the fenwick tree
        cin>>fenw.a[i];
    }
    fenw.build(n);
    while(Q--)
    {
        int tt,l,r;
        cin>>tt>>l>>r;
        if(tt==1)
        {
            // point update in BIT
            fenw.update(l,r-fenw.a[l]);
            fenw.a[l] = r;
        }
        else
            cout<<fenw.query(l,r)<<"\n";
    }
    return 0;
}