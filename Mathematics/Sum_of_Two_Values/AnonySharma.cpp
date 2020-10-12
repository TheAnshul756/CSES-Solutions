#include <bits/stdc++.h>
using namespace std;
 
//DEFINE and TYPEDEF--------------------------------------------------------------
#define SPEEDUP ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long int lld;
//--------------------------------------------------------------------------------

int main()
{
    SPEEDUP;
	lld n,x,a;
	cin>>n>>x;
 
	map<lld,lld> m; // m[x] represents the index of x in the inputted array
	for(lld i=0;i<n;i++)
	{
		cin>>a;
		if(m.count(x-a)) // If x-a was already in the array, then (x-a)+a will result into x
		{
			cout<<m[x-a]+1<<" "<<i+1<<endl; // Output the indices of those two numbers
			return 0;
		}

		m[a]=i;
	}
 
	cout<<"IMPOSSIBLE"<<endl; // If not found, print IMPOSSIBLE
	return 0;
}
