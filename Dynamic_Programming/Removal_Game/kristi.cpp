#include <bits/stdc++.h>
#define ll long long
#define s 5005
using namespace std;

ll dp[s][s],a[s];

ll fun(ll i,ll j)
{

    //Base case
    if(i > j)
    return 0;

    //Lookup case
    if(dp[i][j] != -1)
    return dp[i][j];

    //Recursion case
    ll op1 = a[i] + min(fun(i+2,j), fun(i+1,j-1) );
    ll op2 = a[j] + min(fun(i+1,j-1), fun(i,j-2) );

    return dp[i][j] = max(op1,op2);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;

    for(ll i=0;i<n;i++)
    cin>>a[i];

    memset(dp,-1,sizeof(dp));
    cout<<fun(0,n-1)<<endl;

    return 0;

}