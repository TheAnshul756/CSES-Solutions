#include <bits/stdc++.h>
using namespace std;
int main()
{  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
int t=1;
//cin>>t;
while(t--){
int n,ans=0,f=5;
cin>>n;
while(n>=f){
    ans+=n/f;
    f*=5;
}
cout<<ans;
}
return 0;
 
}