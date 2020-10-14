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
    sort(arr,arr+n);  //sorting to find median
    if(n%2==0)
    {
        ll mid1=arr[n/2];
        ll mid2=arr[(n/2)-1];  //2 medians if n is even
        ll val1=0,val2=0;
        for(ll i=0;i<n;i++)
            val1+=(abs(mid1-arr[i]));
        for(ll i=0;i<n;i++)
            val2+=(abs(mid2-arr[i]));
        cout<<min(val1,val2);    //taking minimum of the two values
    }else
    {
        ll mid=arr[n/2];     //1 median if n is odd
        ll val=0;
        for(ll i=0;i<n;i++)
            val+=(abs(arr[i]-mid));
        cout<<val;
    }
    return 0;
}
