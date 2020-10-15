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
    ll c=1;
    multiset<ll> s;   //multiset s store the number of towers
    s.insert(arr[0]);
    for(ll i=1;i<n;i++)
    {
        ll a=arr[i];
        auto itr=s.upper_bound(a);  //finding the cube in multiset just greater then the current cube
        if(itr==s.end())   // if no greater cube found
        {
            s.insert(a);  //inserting a tower
            c++;
        }else    // if found
        {
            s.insert(a);   //inserting the current cube above the bigger cube on previously made tower
            s.erase(itr);  // deleting the lower cube and working with the currently inserted cube to represent the tower
        }
    }
    cout<<c;
    return 0;
}
