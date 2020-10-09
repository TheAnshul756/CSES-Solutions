#include<bits/stdc++.h>
#define F first
#define S second
#define endl "\n"
#define Endl "\n"
#define lop(i,n) for(i=0;i<n;i++)
#define lop1(i,n) for(i=1;i<=n;i++)
#define lopxy(i,x,y) for(i=x;i<y;i++)
#define ll long long
#define vl vector<long long>
#define pll pair<long long,long long>
#define sl set<long long>
#define uset unordered_set<long long>
#define umap unordered_map
#define prq priority_queue
#define pqll priority_queue<ll> 
#define hell 1000000007
#define mod 998244353
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define N 100000
#define N2 200000
#define bpc(x) __builtin_popcount(x)
#define inf 1e16
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define all(v) (v).begin(),(v).end()
#define D1(x) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<endl
#define D2(x,y) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define D3(x,y,z) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
using namespace std;
int main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin>>n;
    ll a[1000001];
    for(ll i=1;i<=6;i++)
      a[i]=pow(2,i-1);
    for(ll i=7;i<=n;i++){
      ll sum=0;
      for(ll j=1;j<=6;j++)
        sum=(sum+a[i-j])%hell;
      a[i]=sum;
    }
    cout<<a[n];
    return 0;
}
