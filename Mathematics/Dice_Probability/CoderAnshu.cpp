#include<bits/stdc++.h>
using namespace std ;

#define ld long double
#define ll long long
 
// Basic Dynamic Programming Problem

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n,a,b;
    cin>>n>>a>>b;
    vector<vector<ld>> dp(n+1,vector<ld>(6*n+1,0));
    dp[0][0]=1;

    /* dp[i][j] = Probability that the sum obtained is j after throwing the dice i times */
    // Transitions are quite simple

    for(int i=1;i<=n;++i)
    {
        // i-> represents the the current number of turn
        for(int j=1;j<=6;++j)
        {
            // j-> number obtained in the current turn
            for(int k=0;k<=6*n;++k)
            {
                // k-> sum obtained uptill now
                if(k+j<=6*n)
                {
                    dp[i][k+j]+=1.0/6*dp[i-1][k]; // probability of obtaining each number if 1/6;
                }
            }
        }
    }
    ld ans=0;
    // need to calculate sum of probabilities where total_sum is between A and B
    for(int i=a;i<=b;++i)
        ans+=dp[n][i];

    // setting up the precision to 6 decimal places 
    cout<<fixed<<setprecision(6)<<ans<<'\n';

    return 0;
}