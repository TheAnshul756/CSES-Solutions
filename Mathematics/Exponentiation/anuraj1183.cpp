#include<bits/stdc++.h>
#define N 2000006
#define hell 10000000
#define ll long long
using namespace std;
ll mod;
ll power(ll n,ll x)
{
	if(x==0)
		return 1;
	ll res=power(n,x/2);
	res=(res*res)%mod;
	if(x%2==0)
		return res;
	return (res*n)%mod;
}
void solve(long long cno)
{
 
 
 
int i,n,m,k;
int x;
cin>>n>>m;
mod=1e9+7;
 
cout<<power(n,m)<<endl;
 
 
 
	
 
	
 
 
 
 
 
 
 
 
 
 
 
 
 
 
}
// cout<<mn<<endl;	
/*
 
*/
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long TESTS=1;
	cin>>TESTS;
	long long i=1;
	while(TESTS--)
	{
		solve(i);
		i++;
	}
	return 0;
} 
