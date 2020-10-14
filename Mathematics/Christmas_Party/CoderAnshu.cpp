#include<bits/stdc++.h>
using namespace std ;
 
#define ll long long

const int NC=1000005, MOD=1e9+7;

ll inv[NC],fac_inv[NC],fac[NC];

// function for precomputing the factorials and their inverse factorials modulo MOD;
void precompute()
{
    ll i;
    inv[1]=1;
    for(i=2;i<=NC-2;i++)
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD; 
    fac[0]=fac[1]=1;
    for(i=2;i<=NC-2;i++)
        fac[i]=i*fac[i-1]%MOD;
    fac_inv[0]=fac_inv[1]=1;
    for(i=2;i<=NC-2;i++)
        fac_inv[i]=inv[i]*fac_inv[i-1]%MOD;
}

/*  This is just like deranging the n objects and the formula is :
        
    D(n) = n! (1 - 1/1! + 1/2! - 1/3! .....(-1)^n/n!)
*/
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    precompute();

    ll n;
    cin>>n;
    ll ans=0;
    for(int i=2;i<=n;++i)
    {
        ans += ((i&1)?MOD-1:1)*1LL*fac_inv[i];
        ans %= MOD;
    }
    cout<<(ans*fac[n]%MOD);

    return 0;
}
