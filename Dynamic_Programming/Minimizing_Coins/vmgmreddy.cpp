#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, trg;
  cin >> n >> trg;
  vector<int> cn(n);
  
  for (int&v : cn) {
  cin >> v;
  }
  
  vector<int> dp(trg+1,1e9);
  dp[0] = 0;
  
  for (auto i = 1; i <= trg; ++i) {
    for (auto j = 0; j < n; ++j) {
      if (i-cn[j] >= 0) {
	dp[i] = min(dp[i], dp[i-cn[j]]+1);
      }
    }
  }
  
  cout << (dp[trg] == 1e9 ? -1 : dp[trg]) << endl;
  return 0;
}
