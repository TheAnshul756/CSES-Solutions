#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, ans=0LL, r=1LL;
	cin>>n;
	//trailing zeros 
	// = power of 10 in n! 
	// = min(power of 2 in n!, power of 5 in n!)
	// = power of 5 in n! [since number of 5 < 2 always]

	while(n/r > 0)
	{
		r*=5; //r will become all powers of 5 less than n
		ans += n/r;
	}
	cout<<ans;
	return 0;	
}