#include<bits/stdc++.h>
#define N 2000006
#define hell 1000000007
#define maxN 1000000+10
#define ll long long
#define mod (ll)1e9+7
using namespace std;
 
 
ll f[maxN];
 
ll power(ll n,ll x)
{
	if(x==0)
		return 1;
	if(x==1)
		return n%hell;
	ll res=power(n,x/2)%hell;
	res=(res*res)%hell;
	if(x%2==0)
		return res;
	return (res*n)%hell;
}
ll ncr(ll n, ll r)
{
	if(r==0 || r==n)
		return 1;
	if(r==1)
	{
		return (n)%hell;
	}
 
	ll ans=(f[n]*power(f[r],hell-2))%hell; // (1/a) % b  = power(a,b-2) %  b if gcd(a,b)==1
 	ans=(ans*power(f[n-r],hell-2))%hell; 
	return ans;
}
void solve(long long cno)
{
 
 
 
	long long n,i,j,k,l;
	long long ans;
 
 
	f[0]=f[1]=1;
	for(i=2;i<maxN;i++)
	{
		f[i]=(f[i-1]*i)%hell; // calculation factorials f[n] = n!
	}
 
	cin>>n;
	while(n--)
	{
		ll a,b;
		cin>>a>>b;
		cout<<ncr(a,b)<<endl;
	}
  
}

 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long TESTS=1;
	// cin>>TESTS;
	long long i=1;
	while(TESTS--)
	{
		solve(i);
		i++;
	}
	return 0;
}
