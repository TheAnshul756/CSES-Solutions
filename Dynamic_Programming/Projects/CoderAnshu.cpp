#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

long long dp[N];

struct node
{
    int l,r,p;
};
// denoting a project

int main()
{
    int n;
    cin>>n;

    vector<node> v(n+1);

    for(int i=1;i<=n;++i)
        cin>>v[i].l>>v[i].r>>v[i].p;

    // sorting according to endpoints
    sort(v.begin(),v.end(),[&](node a,node b)
    {
        return a.r<b.r;
    });

    // dp[i] => maximum amount of reward we can earn upto day v[i].r (i.e) using only projects from 1 to i.

    /*  Transitions : 
        dp[i] = dp[i-1] => if current project is skipped
        dp[i] = v[i].p ( reward for current project ) + (now we cant do any projects whose r > v[i].l)dp[j]
            where j is the last index where v[j].r < v[i].l
            Because we can't take any project from v[i].l to v[i].r and the previous ones are maintained in
            DP.
        For index j , we will binary search as v[i].r is monotonic .
    */

    dp[0] = 0;
    for(int i=1;i<=n;++i)
    {
        dp[i] = dp[i-1];
        // binary search for j
        int lo = 1,hi = i-1,j = 0;
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            if(v[mid].r<v[i].l)
                lo = mid+1,j = mid;
            else
                hi = mid-1;
        }
        dp[i] = max(dp[i] , v[i].p + dp[j]);
    }

    // our answer is dp[n];

    cout << dp[n] << "\n";
}
