#include <iostream>
using namespace std;
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t=1;
//cin>>t;
while(t--){
long long int n;
cin>>n;
while(1){
cout<<n<<" ";
if(n==1)break;
if(n&1)n=3*n+1;
else n/=2;
}
 
}
return