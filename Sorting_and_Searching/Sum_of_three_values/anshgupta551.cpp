#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back
#define in(x) ll x; cin>>x;
#define ln(x) long long x; cin>>x;
#define memf(a) memset(a,false,sizeof(a))
#define F first
#define S second
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main() 
{ 
	ll n,sum;
	cin>>n>>sum;
	ll a[n];
	map<ll,set<ll>> m;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		m[a[i]].insert(i);
	}
	ll l, r; 
  
    				
    sort(a, a+n); // Sort the elements 
  
   	 /* Now fix the first element one by one and find the 
       other two elements */
    for (ll i = 0; i < n - 2; i++) 
    { 
        // To find the other two elements, start two index 
        // variables from two corners of the array and move 
        // them toward each other 
        l = i + 1; // index of the first element in the 
        // remaining elements 
  
        r = n - 1; // index of the last element 
        while (l < r)
        { 
            if (a[i] + a[l] + a[r] == sum) 
            { 
               	ll x=*m[a[i]].begin();
               	cout<<x+1<<" ";
               	auto it=m[a[l]].begin();
               	while(*it==x)
               	{
               		it++;
               	}
               	ll y=*it;
               	cout<<y+1<<" ";
               	it=m[a[r]].begin();
               	while(*it==x || *it==y)
               	{
               		it++;
               	}
               	ll z=*it;
               	cout<<z+1;
                return 0; 
            } 
            else if ((a[i] + a[l] + a[r]) < sum) 
                l++; 
            else // a[i] + a[l] + a[r] > sum 
                r--; 
        } 
    } 
    cout<<"IMPOSSIBLE";
	return 0; 
} 

