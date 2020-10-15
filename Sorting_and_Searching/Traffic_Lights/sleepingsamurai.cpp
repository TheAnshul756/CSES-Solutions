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
    ll x,n;
    cin>>x>>n;
    ll arr[n];
    multiset<ll> s,s1;  //set s stores the inserted traffic light and s1 stores the difference at a point in the series
    cin>>arr[0];     // 1st insertion of traffic light
    s.insert(arr[0]);
    s1.insert(arr[0]);
    s1.insert(x-arr[0]);
    auto itr=s1.end();
    itr--;
    cout<<*itr<<" ";
    s.insert(-1);
    s.insert(x+1);   //setting the borders to -1 and x+1
    for(ll i=1;i<n;i++)
    {
        cin>>arr[i];
        auto itr1=s.lower_bound(arr[i]);
        itr1--;
        auto itr2=s.upper_bound(arr[i]);
        ll diff=abs(*itr1-*itr2);   
        if(*itr1==-1 || *itr2==x+1)
            diff--;
        if(s1.count(diff));         // deleting the difference which got destroyed after inserton of traffic light
            s1.erase(s1.find(diff)); 
        ll max1=abs(*itr1-arr[i]);
        ll max2=abs(*itr2-arr[i]);
        if(*itr1==-1)
            max1--;
        if(*itr2==x+1)
            max2--;
        s1.insert(max1);        // adding new differences after inserion
        s1.insert(max2);
        s.insert(arr[i]);       // inserting the traffic light
        auto itr=s1.end();         // max difference is answer
        itr--;
        cout<<*itr<<" ";
    }
    return 0;
}
