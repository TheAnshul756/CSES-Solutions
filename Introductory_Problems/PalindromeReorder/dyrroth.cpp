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
int a[26]={};
for(int i=0;s[i];i++){
    a[s[i]-'A']++;
}
string ans,mid;
int flag=1;
for(int i=0;i<26;i++){
    if(a[i]%2==0){
        for(int j=0;j<a[i]/2;j++)ans+='A'+i;
    }
    else if(flag){
         for(int j=0;j<a[i];j++)mid+='A'+i;
         flag=0;
    }
    else{cout<<"NO SOLUTION\n";return 0;}
}
cout<<ans+mid;
reverse(ans.begin(),ans.end());
cout<<ans;
}
return 0;
 