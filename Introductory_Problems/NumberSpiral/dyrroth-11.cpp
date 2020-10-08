#include <bits/stdc++.h>
using namespace std;
int main()
{  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
int t=1;
cin>>t;
while(t--){
long long int y,x,mx,mn,ans=0;
cin>>y>>x;
mx=max(y,x);
mn=min(y,x);
if(mn==y){
    if(mx&1){ans+=mx*mx;ans-=(mn-1);}
    else {ans+=(mx-1)*(mx-1);ans+=mn;}
}
else{
      if(mx&1){ans+=(mx-1)*(mx-1);ans+=mn;}
    else {ans+=mx*mx;ans-=(mn-1);}
}
cout<<ans<<"\n";
}
return 0;
 
}