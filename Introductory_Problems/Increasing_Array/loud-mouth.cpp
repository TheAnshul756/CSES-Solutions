#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin>>n;
	ll max_so_far=0,ans=0;
	for(int i=0; i<n; ++i)
	{
		ll a;
		cin>>a;

		//if the current element 'a' is less than max value so far
		//we will increase 'a' to the max 
		ans += max(0LL, max_so_far-a);

		//keeping track of maximum value in array so far
		//from index 0 to i
		max_so_far=max(max_so_far, a);
	}
	cout<<ans;
	return 0;	
}