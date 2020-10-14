#include<bits/stdc++.h>
using namespace std ;

const int N=200005;
int a[N];
int b[N];

/*  Xor function also satisfies all properties of prefix sum type functions therefore we build
    
    b[i] = a[1]^a[2]^a[3]^......a[i]
    i.e Prefix-Xor upto i.

    Then Answer for query(l,r) i.e Xor of Subarray(l,r) = Prefix-Xor[r] ^ Prefix-Xor[l-1]
*/
 
int main()
{
    ios_base::sync_with_stdio(0);

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        b[i]=b[i-1]^a[i];
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<(b[r]^b[l-1])<<'\n';
    }    

    return 0;
}
