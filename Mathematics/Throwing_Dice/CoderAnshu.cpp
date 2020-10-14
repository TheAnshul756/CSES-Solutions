#include<bits/stdc++.h>
using namespace std ;
 
#define ll long long

const int M = 1e9+7;

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

/*  This question is based on matrix exponentiation and DP
    
    Here the DP transitions are 
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6];
    which can be optimized using matrices .

      dp[i]    | 1 1 1 1 1 1 | dp[i-1]
    dp[i-1]    | 1 0 0 0 0 0 | dp[i-2]
    dp[i-2]    | 0 1 0 0 0 0 | dp[i-3]
    dp[i-3] =  | 0 0 1 0 0 0 | dp[i-4]
    dp[i-4]    | 0 0 0 1 0 0 | dp[i-5]
    dp[i-5]    | 0 0 0 0 1 0 | dp[i-6]
*/

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n;
    cin>>n;
    Matrix dp(6);
    dp.set(0);
    for(int i=0;i<6;++i)
        dp.val[0][i]=1;
    for(int i=1;i<6;++i)
        dp.val[i][i-1]=1;
    ll ans[6]={1,1,2,4,8,16};
    if(n<6)
    {
        cout<<ans[n];
        return 0;
    }
    dp=power(dp,n-5);
    ll p=0;
    for(int i=0;i<6;++i)
        p+=dp.val[0][5-i]*ans[i],p%=M;
    cout<<p;

    return 0;
}
