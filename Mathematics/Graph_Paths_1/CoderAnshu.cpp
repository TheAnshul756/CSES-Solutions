#include<bits/stdc++.h>
using namespace std ;
 
#define M 1000000007
#define ll long long 

// Matrix template 
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
                ans.val[i][j]=0;
                for(ll k=0;k<n_;++k)
                {
                    ans.val[i][j]+=val[i][k]*b.val[k][j];
                    ans.val[i][j]%=M;
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

/*  This is again a pretty standard problem of matrices 
    For complete proof and idea refer to : 
        https://www.geeksforgeeks.org/find-the-number-of-paths-of-length-k-in-a-directed-graph/
*/

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    Matrix dp(n);
    dp.set(0);
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        --x,--y;
        ++dp.val[x][y];
    }
    dp=power(dp,k);
    cout<<dp.val[0][n-1]<<'\n';

    return 0;
}
