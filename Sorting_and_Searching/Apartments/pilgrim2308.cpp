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
    ll n,m,k,ans=0;
    cin>>n>>m>>k;
    ll a[n],b[m];
    rep(i,n)
        cin>>a[i];
    rep(i,m)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    for(ll i=0,j=0;i<n,j<m;){
        if(a[i]-k<=b[j] && a[i]+k>=b[j]){	//succesfully matched apartment to applicant
            ans++;
            i++;
            j++;
        }
        if(a[i]-k>b[j])			//apartment too small for applicant,
            j++;				//moving to next apartment
            
        if(a[i]+k<b[j])			//no apartment is suitable for applicant,
            i++;				//moving to next applicant
    }
    cout<<ans;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T=1;
    //cin>>T;
    while(T--){
    solve();}
    return 0;    
}
