#include<bits/stdc++.h>
using namespace std ;
 
#define M 1000000007
#define ll long long 

// Matrix Template

struct Matrix
{
    vector<vector<ll>> val;
    ll n_;
    Matrix (ll n) : n_(n)
    {
        val.resize(n_);
        for(ll i=0;i<n_;++i)
            val[i].resize(n_);
    }
    void print()
    {
        for(ll i=0;i<n_;++i)
        {
            for(ll j=0;j<n_;++j)
                cout<<val[i][j]<<" ";
            cout<<"\n";
        }
    }
    void set(ll x)
    {
        for(ll i=0;i<n_;++i)
            for(ll j=0;j<n_;++j)
                val[i][j]=x;
    }
    Matrix operator*(const Matrix& b) const 
    {
        ll n=n_;
        Matrix ans(n);
        ans.set(0);
        for(ll i=0;i<n_;++i)
        {
            for(ll j=0;j<n_;++j)
            {
                ans.val[i][j]=4e18;
                for(ll k=0;k<n_;++k)
                {
                    ans.val[i][j] = min(ans.val[i][j],val[i][k]+b.val[k][j]);
                }
 
            }
        }
        return ans;
    }
};
Matrix I(ll n)
{
    Matrix Iden(n);
    Iden.set(0);
    for(ll i=0;i<n;++i)
        Iden.val[i][i]=1;
    return Iden;
}
Matrix power(Matrix m,ll pw)
{
    if(pw==0)
        return I(m.n_);
    if(pw==1)
        return m;
    Matrix t=power(m,pw/2);
    t=t*t;
    if(pw&1)
        t=t*m;
    return t;
}

/*  This is exactly same as Graph_Paths_1 .
    In this case we just need to customize the matrix multiplying function in order to
    obtain the required results for minimum .
*/
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   
    int n,m,k;
    cin>>n>>m>>k;
    Matrix dp(n);
    dp.set(4e18);
    while(m--)
    {
        int x,y;
        ll w;
        cin>>x>>y>>w;
        --x,--y;
        dp.val[x][y] = min(dp.val[x][y] , w);
    }
    dp=power(dp,k);
    ll x=dp.val[0][n-1];
    cout<<(x==4e18?-1:x)<<'\n';

    return 0;
}
