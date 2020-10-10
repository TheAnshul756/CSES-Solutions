#include<bits/stdc++.h>
#define F first
#define S second
#define endl "\n"
#define Endl "\n"
#define ll long long
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  /*
  In this approach we maintain a set of numbers
  if a number is the greatest till now it will be simply added to set
  else
  it will be added and next greater element will be removed from the set
  set would not contain the actual subsequence but its size will properly give its length
  case1 can be easily proved for its correctness
  in case 2 our previous lis would be still there as size of set does not change but if actual lis is not the previous lis
  the further elements will automatically eleminate the elements of previous lis 
  */
  ll n,i;
  cin>>n;
  ll a[n];
  set<ll> s;
  for(i=0;i<n;i++){
    cin>>a[i];
    if(s.insert(a[i]).S){   //check if the element was not present before
      auto k=s.find(a[i]);  
      k++;
      if(k!=s.end())
        s.erase(k);   //erase the element in the set which is just greater than a[i]
    }
  }
  cout<<s.size();
  return 0;
}  
