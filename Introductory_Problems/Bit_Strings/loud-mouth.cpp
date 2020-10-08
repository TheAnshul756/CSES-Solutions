#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin>>n;
	//n digits of the strings can be filled with either 1 or 0
	// 2 options
	//therefore total ways is 2^n

	ll base=2, ans=1;

	//iterative binary exponentiation for 2^n
	while(n)
	{
		if(n%2)
		{
			ans*=base;
			ans%=mod;
		}
		base*=base;
		base%=mod;
		n/=2;
	}

	cout<<ans;
	return 0;	
}