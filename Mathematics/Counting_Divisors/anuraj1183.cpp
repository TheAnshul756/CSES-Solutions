#include<bits/stdc++.h>
#define N 2000006
#define hell 10000000
#define ll long long
using namespace std;
 
void solve(long long cno)
{
 
 
 
int i,n,m,k;
int x;
int j;
cin>>n;
int maxN=1e6+1;
int seive[maxN];
for(i=0;i<maxN;i++)
{
	seive[i]=1;
}
 
for(i=2;i<maxN;i++)
{
	for(j=1;j*i<maxN;j++)
	{
		seive[j*i]++;   // for more information go to cp-algorithms.com
	}
}
 
while(n--)
{
	int l;
	cin>>l;
	cout<<seive[l]<<endl;
}
 
}

 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long TESTS=1;
	// cin>>TESTS;
	long long i=1;
	while(TESTS--)
	{
		solve(i);
		i++;
	}
	return 0;
}
