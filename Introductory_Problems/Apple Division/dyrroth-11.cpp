using namespace std;
int n;
long long int sum=0,ans=1000000009;
long long int a[20]={};
void fun(long long int cnt,int i){
 
ans=min(ans,abs(sum-2*cnt));
if(i==n)return;
fun(cnt+a[i],i+1);
fun(cnt,i+1);
 
}
int main()
{  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
int t=1;
//cin>>t;
while(t--){
cin>>n;
for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
fun(0,0);
cout<<ans;
 
}
return 0;
 
}