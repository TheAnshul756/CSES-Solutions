#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin>>n;
	if(n==1) //corner case n==1
		cout<<1<<" ";
	if(n<=3) //corner cases n==2 or n==3
	{
		cout<<"NO SOLUTION";
	}
	else 
	{
		//just print all even numbers then all odd numbers
		for(ll j : {2, 1}){
			for(ll i=j; i<=n; i+=2)
			{
				cout<<i<<" ";
			}
		}
	}
	return 0;	
}