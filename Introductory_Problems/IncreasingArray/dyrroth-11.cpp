#include <bits/stdc++.h>
using namespace std;
int main()
{  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
long long int n;
int t=1;
//cin>>t;
while(t--){
int n;
cin>>n;
long long int cnt,ans=0,x;
cin>>x;
cnt=x;
n--;
while(n--){
    cin>>x;
    if(x<cnt){ans+=(cnt-x);cnt;}
    else {cnt=x;}
}
cout<<ans;
}
return 0;
 