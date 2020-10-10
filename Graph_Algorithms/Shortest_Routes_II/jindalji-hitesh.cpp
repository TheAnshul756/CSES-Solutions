#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vpp vector<pair<pair<ll,ll>,ll>>
#define vp vector<pair<ll,ll>>
#define mk make_pair
#define pb push_back
#define IOS  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

/*
using djikstra's algo for each i , 1<=i<=n we will find d[i][j] (d[i][j] denotes shortest path from i to j) 1<=j<=n 
now queries can easily be answered online
*/
ll n,m;
ll v[501][501];
ll INF = 1e18;
ll d[502][502];
int main()
{
    
    IOS;
    ll q,i,j;
    cin>>n>>m>>q;
    ll a,b,c;
    for(i=0;i<=500;i++){
        for(j=0;j<=500;j++){
            v[i][j]=INF;
        }
    }
    for( ll i=0; i<m; i++)
    {
        cin>>a>>b>>c;
        v[a][b]=min(v[a][b],c);  //if there are two or morre edges between one pair we will keep the one with shortest length
        v[b][a]=v[a][b];
    }
    ll s;
    for(j=1; j<=n; j++){
        s=j;
        for(i=0; i<=n; i++)
            d[s][i] = INF;      // intialize al distances to infinity
 
        d[s][s] = 0;
        using pii = pair<ll, ll>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push(mk(0,s));
	// djiskstra's algo starts here
        while( !q.empty())
        {
            ll ii = q.top().second;
            ll jj = q.top().first;
            q.pop();
     
            if( jj != d[s][ii])
              continue;
     
            for(i=1;i<=n;i++)
            {
                if(v[ii][i]==INF)
                    continue;
                ll to = i;
                ll c1 = v[ii][i];
 
     
                if( d[s][ii]+c1 < d[s][to])
                {
                    d[s][to] = d[s][ii]+c1;
                    q.push(mk(d[s][to],to));
                }
            }
        }
    }
    for( ll i=1; i<=q; i++)
    {
        cin>>a>>b;
        if( d[a][b] != INF)
            cout<<d[a][b]<<"\n";
        else
            cout<<-1<<"\n";
    }
 
}
