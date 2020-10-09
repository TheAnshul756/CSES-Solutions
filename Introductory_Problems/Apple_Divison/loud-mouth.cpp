#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;
int n, sum=0LL;
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        int b;
        cin>>b;
        a.push_back(b);
        sum+=b;
    }
    int min=1<<30;
 
    for(int mask=1; mask<(1<<n); ++mask) 
    //binary representation of mask denotes the partition of sets
    //0 for set 1, 1 for set 2
    {
        int tp=0; //temporary sum for set 2 in this instance
        for(int j=0; j<(int)a.size(); ++j)
        {
            if(((mask >> j)&1))
            {
                tp+=a[j];
            }
        }
        int cmp = abs(tp - (sum-tp)); //set difference in this case
        if(cmp< min){
            min=cmp;
        }
    }
    cout<<min;
 
    return 0;   
}