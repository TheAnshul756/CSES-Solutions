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
  string s;
  cin>>s;
  int n=s.length();
  int ans=1,cnt=1;
    for(int i=1;i<n;i++){
        while(s[i]==s[i-1]&& i<n){
            cnt++;
            i++;
        }
        ans=max(ans,cnt);
        cnt=1;
    }
    cout<<ans;
}
return 0;
 
}