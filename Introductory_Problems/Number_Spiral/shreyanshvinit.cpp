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
		ll y, x;
		cin>>y>>x;
		y>x ? y%2==1 ? cout<<(y-1)*(y-1)+x : cout<<y*y-x+1 : x%2==1 ? cout<<x*x-y+1 : cout<<(x-1)*(x-1)+y ;
		cout<<endl;
	}
 
	return 0;	
}
