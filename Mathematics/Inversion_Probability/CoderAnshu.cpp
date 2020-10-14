#include<bits/stdc++.h>
using namespace std ;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    

    int n;
    cin>>n;
    vector<int> r(n+1,0);
    for(int i=1;i<=n;++i)
        cin>>r[i];
    long double ans=0;

    /*  Number of inversions depends only on the pair of indexes and therefore we iterate over all pairs
        and add to answer the probability of current pair to be the inversion and since only one inversion
        is counted in every case we simply add P(is_inversion)*1
    */
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            //(i,j) pair of indices
            for(int k=1;k<=r[i];++k)
            {
                // range of a[i]
                for(int l=1;l<=r[j];++l)
                {
                    // range of a[j]
                    if(k>l)
                    {
                        // if is a inversion
                        ans+=1.0/r[i]/r[j];
                    }
                }
            }
        }
    }

    // setting up the precision to 6 decimal places 
    cout<<fixed<<setprecision(6)<<'\n';
    cout<<ans;

    return 0;
}