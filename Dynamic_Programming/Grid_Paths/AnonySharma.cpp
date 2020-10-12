#include <bits/stdc++.h>
using namespace std;
 
//DEFINE and TYPEDEF--------------------------------------------------------------
#define SPEEDUP ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define st first
#define nd second

typedef long long int lld;
#define mod 1000000007
//--------------------------------------------------------------------------------

int main()
{
	SPEEDUP;
	lld n;
	cin>>n;
 
	string s[n];
	for(lld i=0;i<n;i++)
		cin>>s[i];
 
	lld dp[n+2][n+2]; //dp[i][j] is the number of ways to visit s[i][j] from the upper left square
	memset(dp,0,sizeof(dp));
	dp[0][0]=1; //We are already at upper left square
 
	for(lld i=0;i<n;i++)
	for(lld j=0;j<n;j++)
	if(s[i][j]!='*') // Since we have to skip the traps
	{
		if(i and !j) // If we are in the first vertical line, the only way to visit it is from the point above to it
			dp[i][j]=dp[i-1][j];
		else if(!i and j) // If we are in the first horizontal line, the only way to visit it is from the point left to it
			dp[i][j]=dp[i][j-1];
		else if(i and j) // Otherwise, we can visit it from the cell above it or the cell left to it,
			dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
	}
 
	cout<<((s[0][0]=='*')?0:dp[n-1][n-1]); // If last cell consists a trap, we can never visit it, so answer is 0
	return 0;
}
