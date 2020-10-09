#include<bits/stdc++.h>
#define ll long long
#define hell 1000000007
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin>>n;
    ll a[1000001];
    //assign values from 1 to 6 
    for(ll i=1;i<=6;i++)
      a[i]=pow(2,i-1);

    //as each value on dice ranges from 1 to 6 the answer of i will be sum of all cases in the range i-6 to i-1  
    for(ll i=7;i<=n;i++){ // iterating from 7 to n
      ll sum=0;
      for(ll j=1;j<=6;j++) // for iterating from i-1 to i-6
        sum=(sum+a[i-j])%hell;
      a[i]=sum;
    }
    cout<<a[n]; //print the answer
    return 0;
}
