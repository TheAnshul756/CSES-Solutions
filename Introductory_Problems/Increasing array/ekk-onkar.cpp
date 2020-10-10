#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,tmp;
    cin>>n;
    std::vector<int>v ;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        v.push_back(tmp);
    }
    int min=v[0],ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(v[i+1] < v[i])
        {
            ans+=min-v[i+1];
        }
        else if(v[i+1] > v[i])
        {
            min=v[i+1];
        }
    }
    cout<<ans;
    return 0;
}
