#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define int long long
#define ff first
#define ss second
#define pii pair<int,int>
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
 
const int inf = 1e15;
const int nax = 1e5+10;
const int mod = 1e9+7;
vector<pii> g[nax] , dp(nax) ;
vector<int>  vis(nax,0) , dp_mx(nax) , dp_mn(nax) ;
int n,m;
 
signed main()
{
    fast;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[v].push_back({u,w});
    }
    set< pii > pq;
    for(int i=1;i<=n;i++)
    {
        dp_mx[i] = 0;
        dp_mn[i] = n+1;
        dp[i].ss = 0;
        dp[i].ff = inf;
        if( i==n )
        {
            dp[i].ff = 0;
            dp[i].ss = 1;
        }
        pq.insert( {dp[i].ff , i } );
    }
    dp_mx[n] = dp_mn[n] = 0;
    while( !pq.empty() )
    {
        pii p = *pq.begin();
       // cout << p.ff << " " << p.ss << "\n";
        pq.erase(pq.begin());
        int i = p.ss;
        vis[ i ] = 1;
        for( auto &j : g[i] )
        {
            if( vis[ j.ff ] ) continue;
            if( dp[i].ff + j.ss < dp[j.ff].ff )
            {
                pq.erase(pq.find( {dp[j.ff].ff , j.ff} ) );
                dp[j.ff].ff = dp[i].ff + j.ss;
                pq.insert( {dp[j.ff].ff , j.ff } );
                dp[j.ff].ss = dp[i].ss ;
                dp_mx[j.ff] = dp_mx[i]+1 ;
                dp_mn[j.ff] = dp_mn[i]+1 ;
            }
            else if( dp[i].ff + j.ss == dp[j.ff].ff )
            {
                dp[j.ff].ss = (dp[i].ss + dp[j.ff].ss ) % mod ;
                dp_mx[j.ff] = max( dp_mx[i]+1 , dp_mx[j.ff]  );
                dp_mn[j.ff] = min( dp_mn[i]+1 , dp_mn[j.ff]  );
            }     
        }
    }
    
    cout << dp[1].ff << " " << dp[1].ss << " " << dp_mn[1] << " " << dp_mx[1];
}
 