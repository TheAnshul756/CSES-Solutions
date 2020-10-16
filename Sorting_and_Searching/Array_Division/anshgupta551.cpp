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
ll n,k;
ll a[200005];
bool possible(ll x) // whether that particlar max value is feasible within k divisions or not
{
	ll i=0;
	ll z=0;
	ll xx=1;
	while(i<n)
	{
		if((z+a[i])<=x)
		{
			z+=a[i];
		}
		else
		{
			z=a[i];
			xx++;
		}
		i++;
	}
	if(xx<=k)
	{
		return true;
	}
	else
		return false;
}
int main()
{
	fast
	cin>>n;
	cin>>k;
	ll mx=0;
	for(ll i=0;i<n;i++)
		{cin>>a[i];mx=max(mx,a[i]);}
	ll l=mx,r=1e15; //the range in which our answer lies
	ll mid;
	while(l<=r) //applying binary search to find our answer
	{
		mid=(l+r)/2;
		if(l==r)
			break;
		if(l+1==r)
		{
			if(possible(l))
			{
				mid=l;
				break;
			}
			else if(possible(r))
			{
				mid=r;
				break;
			}
		}
		if(possible(mid))
		{
			r=mid;
		}
		else l=mid;
	}
	cout<<mid;
	return 0;
}
