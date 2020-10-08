#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
long long int dyrroth(long long int x){
long long int ans=1,y=2;
while(x>0){
       if(x&1) ans=(y*(ans%m))%m;
        y=((y%m)*(y%m))%m;
        x/=2;
}
return ans;
}
int main()
{  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
int t=1;
//cin>>t;
while(t--){
int n;
cin>>n;
cout<<dyrroth(n);
}
return 0;
 
}