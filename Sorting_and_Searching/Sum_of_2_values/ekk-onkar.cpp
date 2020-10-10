#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x,tmp;
    cin>>n>>x;
    vector<int>v;
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        v.push_back(tmp);
        m[tmp]=i+1;
    }
    sort(v.begin(),v.end());
    auto it1=v.begin();
    auto it2=v.end()-1;
    while(it1!=it2)
    {
        if(*it1+*it2 == x)
        {
            cout<<m[*it1]<<" "<<m[*it2];
            return 0;
        }
        else if(*it1+*it2 < x)
        {
            it1++;
            continue;
        }
        else if(*it1+*it2 > x)
        {
            it2--;
        }
        
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
