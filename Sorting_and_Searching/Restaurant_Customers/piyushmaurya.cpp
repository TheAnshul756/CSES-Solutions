#include <bits/stdc++.h>

#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define ll long long
#define endl '\n'
#define pii pair<ll int, ll int>
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pb push_back

using namespace std;

int main()
{
    ios
        ll n;
    cin >> n;
    // This vector of pairs will store entry and exit times
    // with a flag representing the type of timestamp
    // 0 represents entry and 1 represents exit
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb({x, 0});
        v.pb({y, 1});
    }
    // All the combined timestamps should be sorted for a sweep
    sort(all(v));
    ll cur = 0, ans = 0;
    // Doing a sweep on entry and exit times keeping track of
    // maximum number of customers
    for (auto x : v)
    {
        if (x.S == 0)
            cur++;
        else
            cur--;
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}