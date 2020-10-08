#include <bits/stdc++.h>
using namespace std;
#define x 8
#define z 50
char a[x][x];
int c[z],d1[z],d2[z],ans=0;
void fun(int p){
if(p==8){ans++;return;}
for(int i=0;i<8;i++){
    if(a[p][i]=='*')continue;
    if(c[i]==0 && d1[p+i]==0 && d2[12+i-p]==0 ){
       c[i]=1;
       d1[p+i]=1;
       d2[12+i-p]=1;
       fun(p+1);
        c[i]=0;
       d1[p+i]=0;
       d2[12+i-p]=0;
    }
}
}
int main()
{  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
int t=1;
//cin>>t;
while(t--){
char m;
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        cin>>m;
        a[i][j]=m;
    }
}
fun(0);
cout<<ans;
}
return 0;
 
}