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
    ll cont[n];      //array cont will store the length of continuous series till that point in the array
    for(ll i=0;i<n;i++)
        cont[i]=0;
    map<ll,ll> m,m1;   //map m stores the occurrence of a track and m1 stores the index of that track;
    ll c=0,k=0;
    for(ll i=0;i<n;i++)
    {
        if(m[arr[i]]==0)  //operation on first occurrence of a track
        {
            m1[arr[i]]=i;
            m[arr[i]]++;
            c++;
            cont[i]=max(cont[i],c);
        }else               // operation on second occurrence of track
        {
            c=i-m1[arr[i]]-1;
            for(ll j=k;j<=m1[arr[i]];j++)  //deletion of elements before the previous occurrence of track
            {
                m[arr[j]]=0;
            }
            k=m1[arr[i]]+1;
            i--;
        }
    }
    ll max1=0;
    for(ll i=0;i<n;i++)
    {
        max1=max(max1,cont[i]);   //obtaining the max value in the cont array for answer
    }
    cout<<max1;
    return 0;
}
