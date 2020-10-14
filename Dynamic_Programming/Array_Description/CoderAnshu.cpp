#include<bits/stdc++.h>
using namespace std ;

const int mod = 1e9+7;
const int N=100005;
 
int dp[N][101];
int a[N];

// Pretty standard dynamic programming

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];

    /*  Here dp[i][j] = number of ways to fill the first i elements such that the last element is j */

    /*  If the last element is j then the second last element can be only j , j-1 , j+1 obviously
        => dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
    */

    /* Base conditon */
    if(a[1]==0)
    {
        // every integer from 1 to n is possible
        for(int i=1;i<=m;++i)
            dp[1][i]=1;
    }
    else
    {
        dp[1][a[1]]=1;
    }

    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            // check if a[i]==0 || a[i]==j i.e j is feasible as last element or not
            if(a[i]==0 || a[i]==j)
            {
                dp[i][j] = ((dp[i-1][j-1]+dp[i-1][j+1])%mod+dp[i-1][j])%mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=m;++i)
    {
        ans += dp[n][i];
        ans %= mod;
    }
    cout<<ans;

    return 0;
}