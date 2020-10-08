#include <bits/stdc++.h>
using namespace std;
int main()
{  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
int t=1;
//cin>>t;
while(t--){
string s;
cin>>s;
sort(s.begin(),s.end());
vector<string> v;
int ans=1;
v.push_back(s);
while(next_permutation(s.begin(),s.end())){
    ans++;
    v.push_back(s);
}
cout<<ans<<"\n";
for(int i=0;i<v.size();i++)cout<<v[i]<<"\n";
}
return 0;
 
}