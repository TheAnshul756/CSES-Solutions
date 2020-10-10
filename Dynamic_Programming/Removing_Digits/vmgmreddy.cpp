#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> dp(n+1,1e9);
  dp[0] = 0;
  for (auto i = 0; i <= n; ++i) {
    for (char ch : to_string(i)) {
      dp[i] = min(dp[i], dp[i-(ch-'0')]+1);
    }
  }
  
  cout << dp[n] << endl;
  return 0;
}
