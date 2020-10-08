#include<bits/stdc++.h>
using namespace std;
#define ll long long
 

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin>>t;
	while(t-->0)
	{
		ll a,b;
		cin>>a>>b;
		if(a>b) swap(a,b);
		ll k = b-a;
		//k is difference of 2 pile sizes
		if((a-k)%3==0 and a>=k) 
		//we can remove 2 from larger one and 1 from smller till they are equal
		//then that equal value must be divisible by 3
		{
			cout<<"YES\n";
		}
		else cout<<"NO\n";
 
	}
 
	return 0;	
}