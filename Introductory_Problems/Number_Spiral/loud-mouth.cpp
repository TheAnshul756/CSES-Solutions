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
		if(y > x)
		{
			if(y%2)
			{
				//square of side (y-1) has been filled
				//hence we just have to fill the xth row
				cout<<(y-1)*(y-1)+x;
			}
			else
			{
				//we fill a square of y side length
				//and move (x-1) steps back
				cout<<y*y-x+1;
			}
		}
		else
		{
			if(x%2)
			{
				//we fill a square of x side length
				//and move (y-1) steps back
				cout<<x*x-y+1;
			}
			else
			{
				//square of side (x-1) has been filled
				//hence we just have to fill the yth column
				cout<<(x-1)*(x-1)+y;
			}
		}
		cout<<endl;
	}
 
	return 0;	
}