#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cout<<n<<" ";
    while(n!=1)
    {
        if(n%2==0)
        {
            n/=2;
            cout<<n<<" ";
            continue;
        }
        else
        {
            n*=3;
            n++;
            cout<<n<<" ";
        }
    }
    return 0;
}
