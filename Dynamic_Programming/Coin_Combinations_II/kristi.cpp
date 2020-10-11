#include <bits/stdc++.h> 
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 

int main()
{
    fast_io;

    ll n,x;
    ll mod = 1e9+7;
    cin>>n>>x;

    vector <ll> coin(n);
    for(ll&i : coin)
    cin>>i;

    vector <ll> dp(x+1,0);
    dp[0] = 1; // ways to achieve sum of 0,using the array = 1, i.e = taking a null subset. 
    
    for(ll i=0;i<n;i++)//we take each coin specifically, and do the needed calculations
    {
        for(ll j=0;j<=x;j++)//we build numbers from 0 to sum, using the taken coin i.e- coin[i]
        {
            if(j-coin[i] >= 0)
            {
            dp[j] += dp[j-coin[i]];
            dp[j] %= mod;
            }
        }
    }
    cout<<dp[x]<<endl;

    return 0;
}