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
long long int n,sum=0,x;
cin>>n;
for(int i=0;i<n-1;i++){
    cin>>x;
    sum+=x;
}
cout<<(n*(n+1))/2 - sum;
}
return 0;
}