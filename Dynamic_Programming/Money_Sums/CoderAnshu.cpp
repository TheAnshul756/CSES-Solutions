#include<bits/stdc++.h>
using namespace std ;
 
const int N=100005;

bool dp[N]; // if the sum is possible
int a[101];

/*  This is the most common problem of dynamic programming which is also called knapsack problem.
    For more details refer to : 
        https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
*/

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];

    // dp[i] = if sum i can be obtained or not

    // base condition
    dp[0]=true;
    
    for(int i=1;i<=n;++i)
    {
        for(int j=1e5-a[i];j>=0;--j)
        {
            dp[j+a[i]] = dp[j+a[i]] || dp[j];
        }
    }
    int ans=0;
    for(int i=1;i<N;++i)
        ans+=dp[i];
    cout<<ans<<'\n';
    for(int i=1;i<N;++i)
    {
        if(dp[i])
        {
            cout<<i<<" ";
        }
    }

    return 0;
}
