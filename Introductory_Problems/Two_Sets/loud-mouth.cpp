#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin>>n;
	if(n%4==1 or n%4==2){
		cout<<"NO\n";
	}
	else if(n%4 == 0)
	{
		cout<<"YES\n";
		//2 sets of size n/2

		//set 1
		//combination of first and last n/4 numbers
		cout<<n/2<<"\n";
		for(int i=1; i<=n/4; ++i)
			cout<<i<<" "<<n-i+1<<" ";
		cout<<"\n";

		//set 2
		//rest of the numbers
		cout<<n/2<<"\n";
		for(int i=n/4+1; i<=n/2; ++i)
		{
			cout<<i<<" "<<n-i+1<<" ";
		}
	}
	else
	{
		cout<<"YES\n";
		vector<int> a,b; 
		//a for odd, b for even
		for(int i=1; i<=n; ++i)
		{
			if(i%2)
				a.pb(i);
			else b.pb(i);
		}
		//right now there is a difference of ((n-n/2)/2)*2 between the two sets

		for(int i=0; i<(n-n/2)/2; ++i)
			swap(a[i+1], b[i]); 
			//doing this will create a gap of 2 for each swap
			//since a[i+1] and b[i] are consecutive

		//set 1
		cout<<(int)a.size()<<'\n';
		for(auto i : a)
			cout<<i<<" ";

		//set 2
		cout<<"\n"<<(int)b.size()<<"\n";
		for(auto i : b)
			cout<<i<<" ";
	}
	return 0;	
}