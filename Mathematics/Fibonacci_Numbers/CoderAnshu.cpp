#include<bits/stdc++.h>
using namespace std ;

#define ll long long


/*  This is a standard problem of matrix exponentiation .
    We can speed up solving of recurrences to O(k^3logn) where k is the size of the matrix .
    For general details and matrices for fibonaaci refer :
        https://www.geeksforgeeks.org/matrix-exponentiation/
*/
const int M =1e9+7;
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

int main()
{
    Matrix dp(2);
    dp.val[0][0]=1;dp.val[0][1]=1;dp.val[1][0]=1;dp.val[1][1]=0;
    ll n;
    cin>>n;
    if(n==0)
    {
        cout<<'0';return 0;
    }
    dp=power(dp,n-1);
    cout<<dp.val[0][0]<<endl;

    return 0;
}
