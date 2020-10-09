#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   	int n,x;
   	cin>>n>>x;
   	int price[n],pages[n];
   	for(int i=0;i<n;i++)
   		cin>>price[i];
   	for(int i=0;i<n;i++)
   		cin>>pages[i];
   	int dp[x+1]={0};
	for(int i=0;i<n;i++)
	{
		int prc=price[i];
		for(int j=x;j>=prc;j--)
		{
			dp[j]=max(dp[j],dp[j-prc]+pages[i]);
		}

	}	
	cout<<dp[x]<<endl;
}