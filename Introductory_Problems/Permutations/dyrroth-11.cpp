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
if(n==1){cout<<"1";return 0;}
if(n<4){cout<<"NO SOLUTION";return 0;}
else{
for(int i=2;i<=n;i+=2)cout<<i<<" ";
for(int i=1;i<=n;i+=2)cout<<i<<" ";
}
}
return 0;
 
}