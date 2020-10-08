#include <bits/stdc++.h>
using namespace std;
int main()
{  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
int t=1;
//cin>>t;
while(t--){
int n;
cin>>n;
if(n%4==0){
    cout<<"YES\n";
cout<<n/2<<"\n";
for(int i=1;i<=n/4;i++){
    cout<<i<<" "<<n-i+1<<" ";
}
cout<<"\n"<<n/2<<"\n";
for(int i=n/4+1;i<=n/2;i++){
    cout<<i<<" "<<n-i+1<<" ";
}
}
else if(n%4==3){
    cout<<"YES\n";
 cout<<n/2<<"\n";
cout<<n<<" ";
for(int i=1;i<=n/4;i++){
    cout<<i<<" "<<n-i<<" ";
}
cout<<"\n"<<n/2+1<<"\n";
for(int i=n/4+1;i<=n/2;i++){
    cout<<i<<" "<<n-i<<" ";
}
}
else{cout<<"NO";return 0;}
}
return 0;
 
}