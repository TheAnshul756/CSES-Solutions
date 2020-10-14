#include<bits/stdc++.h>
using namespace std ;

#define ll long long

const int NC = 1000005;
const int  MOD = 1e9+7;

// precomputing factorials and their inverse factorials

ll inv[NC],fac_inv[NC],fac[NC];
void initialize()
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

/*  This is a basic question of permutations 
    Number of ways to arrange n objects where a1,a2 .. objects are of one kind =  n! / (a1! * a2! * a3!...)

*/

 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    initialize();

    ll ans=1;
    string s;
    cin>>s;

    // count of each character 
    vector<int> cnt(26,0);
    for(auto j:s)
        cnt[j-'a']++;

    ans=fac[s.size()]; // factorial(n);

    for(int i=0;i<26;++i)
        ans*=fac_inv[cnt[i]],ans%=MOD;
    
    cout<<ans;

    return 0;
}
