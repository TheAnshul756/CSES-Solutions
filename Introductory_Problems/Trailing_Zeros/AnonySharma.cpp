#include <bits/stdc++.h>
using namespace std;
 
//DEFINE and TYPEDEF--------------------------------------------------------------
#define SPEEDUP ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define st first
#define nd second

typedef long long int lld;
//--------------------------------------------------------------------------------

int main()
{
	SPEEDUP;
	lld n,ans=0;
	cin>>n;
 
 	/*In high school maths, we have learned this technique, which is used to 
 	calculate trailing zeros in a factorial of a given number. 
 	I just coded that same algorithm.
 	
	The algo is:
	Divide n by the powers of 5 and store the sum of floor of the quotients we get. 
 	*/
	while(n)
	{
		ans+=n/5; // i.e. same as floor(n/5)
		n/=5;
	}
 
	cout<<ans;
	return 0;
}
