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
    ll n,m,x;
    cin>>n>>m;
    multiset<ll> v;
    rep(i,n){
        cin>>x;
        v.insert(x);
    }
    rep(i,m){
        cin>>x;
        if(v.empty()){			//if no tickets are available
            cout<<"-1\n";
            continue;
        }
        auto it=v.upper_bound(x);   
        if(it==v.begin())		//if cheapest ticket is expensive than
        {				//what customer wants to pay
            cout<<-1<<"\n";
            continue;
        }     
        it--;				
        cout<<*it<<"\n";		//customer buys the ticket,
        v.erase(it);			//that ticket is removed from set
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T=1;
    //cin>>T;
    while(T--){
    solve();}
    return 0;    
}
