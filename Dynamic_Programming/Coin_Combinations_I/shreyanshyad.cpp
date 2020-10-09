#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - v[j] >= 0)
                (dp[i] += dp[i - v[j]]) %= MOD;
        }
    }
    cout << dp[sum];
}