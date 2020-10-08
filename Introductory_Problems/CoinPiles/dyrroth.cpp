#include <bits/stdc++.h>
using namespace std;
int main()
{  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
int t=1;
cin>>t;
while(t--){
int a,b;
cin>>a>>b;
if((a+b)%3==0 && (a>=(a+b)/3) && (b>=(a+b)/3) ){cout<<"YES\n";}
else cout<<"NO\n";
}
return 0;
 
}