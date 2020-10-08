#include <bits/stdc++.h>
using namespace std;
 
int main()
{  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
int t=1;
//cin>>t;
while(t--){
int i;
cin>>i;
for(long long int n=1;n<=i;n++){
    cout<<((n*n)*(n*n-1))/2 - 4*(n-1)*(n-2)<<"\n";
}
}
return 0;
 
}