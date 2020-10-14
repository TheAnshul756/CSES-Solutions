#include<bits/stdc++.h>
using namespace std ;
 
#define ld long double

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n,k;
    cin>>n>>k;

    vector<ld> dp(k+1);

    // dp[i] stores the probability that each student gets <=i candies

    dp[0] = 0.0;

    for(int i=1;i<=k;++i)
    {
        // n students and probability of getting <=i candies is i/k
        dp[i] = pow(i*1.0/k,n);
    }

    ld ans=0;
    // expected value of maximum number of candies = 
    /*
        E = P(max = 1)*1 + P(max = 2)*2 + ............ P(max = k)*k
        Here
            P(max = i) = dp[i] - dp[i-1] because if we subtract those cases from dp[i] where  we get <= i-1
            candies then there is atleast one student who gets = i candies and max is therefore = i;

    */

    for(int i=1;i<=k;++i)
        ans += i*(dp[i]-dp[i-1]);

    // seting up precision value to 6 decimal places 
    cout<<fixed<<setprecision(6)<<ans<<'\n';

    return 0;
}