#include<bits/stdc++.h>
//#include<triple.h>
#include<cmath>
using namespace std;
 
#define ll long long
typedef vector<ll> vi;
typedef vector<vi > vvi;
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define repa(i,n) for(ll i=1;i<n;i++)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define pb push_back
typedef pair<ll,pair<ll,ll> > pii;
#define inf 1e10
 
bool prime[100005]={false};
void sieve(){
    prime[0]=true;
    prime[1]=true;
    for(ll i=2;i<100005;i++){
        if(prime[i]==false){
            for(ll j=i*i;j<100005;j+=i)
                prime[j]=true;
                }
            }
 
}
 
 
void solve(){
    ll n,a,b,ls=0,cnt=0;
    vi p;
    vector<pair<ll,ll> > q;
    cin>>n;
    rep(i,n){
        cin>>a>>b;
        p.pb(a);		//p contains starting times of all movies
        q.pb(mp(b,i));		//q contains pairs of ending time and movie number
    }
    sort(q.begin(),q.end());	
    for(auto u:q){
        if(p[u.S]>=ls){	//if starting time of (u.S)th movie is greater than
            cnt++;		//ending time of last watched movie,
            ls=u.F;		//then increase count of movies and 	
        }			//update ending time of last watched movie
    }
    cout<<cnt;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T=1;
    //cin>>T;
    while(T--){
    solve();}
    return 0;    
}
