#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   	int n;
  	cin>>n;
  	int val[n];
  	set<int> ans;
  	for(int i=0;i<n;i++)
  		cin>>val[i];
  	vector<int> dp(n+1,n);
  	dp[0]=0;
  	for(int i=1;i<=n;i++)
  	{
  		for(int j=i;j!=0;j=j/10)
  		{
  			dp[i]=min(dp[i],dp[i-j%10]+1); //checking for every current digits of i
  		}
  	}
  	cout<<dp[n];

  }
