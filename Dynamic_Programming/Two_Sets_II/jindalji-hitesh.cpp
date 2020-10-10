#include<bits/stdc++.h>
#define F first
#define S second
#define endl "\n"
#define Endl "\n"
#define ll long long
#define vl vector<long long>
#define pll pair<long long,long long>
#define sl set<long long>
#define uset unordered_set<long long>
#define umap unordered_map
#define prq priority_queue
#define pqll priority_queue<ll> 
#define hell 1000000007
#define mod 998244353
#define pb push_back
#define ppb pop_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define all(v) (v).begin(),(v).end()
using namespace std;
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;  
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
ll modInverse(ll n, ll p=hell) 
{ 
    return power(n, p-2, p); 
} 

ll dp[501][100000];
ll solve(ll i,ll n,ll sum){
  if(i>n||sum<=0||i>sum)
    return 0;
  if(dp[i][sum]!=-1)
    return dp[i][sum];
  if(sum==i)
    return 1;
  return dp[i][sum]=(solve(i+1,n,sum)+solve(i+1,n,sum-i))%hell;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  // the problem can simplified to number of subsets of set {1,2,....n} whose sum is (n*(n+1))/4
  // the solution of this is simple recursive approach where at each number two cases are explored to include that number or exclude that number
  // memoization is used to avoid overlapping subproblems
  ll n;
  cin>>n;
  mem1(dp);
  if(n%4==1||n%4==2){  //check if sum of numbers is odd , if it is so numbers cannot be divided into two sets of equal sum
    cout<<0;
    return 0;
  }
  ll sum=(n*(n+1))/4;
  cout<<(solve(1,n,sum)*modInverse(2))%hell;

  return 0;
}  
