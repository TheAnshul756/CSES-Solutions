#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back
#define in(x) ll x; cin>>x;
#define ln(x) long long x; cin>>x;
#define memf(a) memset(a,false,sizeof(a))
#define F first
#define S second
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main()
{
	fast
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin>>a[i];
	map<ll,ll> m; // creating a map to count frequency of remainders 
	ll presum[n+1]; // to store prefix sums
	presum[0]=0;
	for(ll i=1;i<=n;i++)
	{
		presum[i]=presum[i-1]+a[i-1];
		m[((presum[i]%n)+n)%n]++;
	}
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		ans+=(m[i]*(m[i]-1)/2);// selection of any two with same remainders
	}
	ans+=m[0];// add the elements which are divisible by n itself i.e., the elements whose sum = 0 
	
	cout<<ans;

	return 0;
}
