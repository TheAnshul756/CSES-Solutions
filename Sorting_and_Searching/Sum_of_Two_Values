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
    int n,x;
    cin>>n>>x;
    pair<int,int> p[n];  // storing numbers in array of pairs
    for(int i=0;i<n;i++)
    {
        cin>>p[i].F;
        p[i].S=i+1;
    }
    sort(p,p+n); // sorting the array of pairs
    map<int,int> m1; // using map to store values less then x/2;
    int mark1,mark2,f=0,no;
    for(int i=0;i<n;i++)
    {
        if(p[i].F<=x/2)
            m1[p[i].F]++;
        if(p[i].F>x/2)
        {
            if(m1[x-p[i].F]!=0)
            {
                no=x-p[i].F;
                f=1;
                mark2=p[i].S;
                break;
            }
        }
    }
    if(f==1)
    {
        for(int i=0;i<n;i++)
        {
            if(no==p[i].F)
            {
                mark1=p[i].S;
                break;
            }
        }
        cout<<mark1<<" "<<mark2<<"\n";
    }else
    if(x%2==0)
    {
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(p[i].F==x/2)
            {
                v.pb(p[i].S);
            }
        }
        if(v.size()>=2)
        {
            cout<<v[0]<<" "<<v[1];
        }else
        cout<<"IMPOSSIBLE";
    }else
    cout<<"IMPOSSIBLE";
    return 0;
}
