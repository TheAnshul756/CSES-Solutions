#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s,t;
    cin>>s>>t;
    int n=s.length(), m=t.length();
    int dp[n+1][m+1];
    for(int i=0;i<m+1;i++)
      dp[0][i]=i;
    for(int i=1;i<n+1;i++)
    {
      dp[i][0]=i;
      for(int j=1;j<m+1;j++)
      {
        dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
        dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s[i-1]!=t[j-1]));

      }
    }
    cout<<dp[n][m];

 }
