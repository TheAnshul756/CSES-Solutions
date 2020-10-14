#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pi 3.141592653589
#define F first
#define S second
 
ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power(ll b,ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll maxall=arr[0],maxthis=arr[0]; // maxall give the overall maximum sum, maxthis give the maxsum till this point
    for(ll i=1;i<n;i++)
    {
        maxthis=max(maxthis+arr[i],arr[i]); // applying kadane's algorithm
        if(maxthis>maxall)
            maxall=maxthis;
    }
    cout<<maxall;
    return 0;
}
