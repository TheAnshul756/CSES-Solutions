#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) (v).begin(),(v).end()
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define DEC(x) fixed<<setprecision(x)
#define FAST ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/__gcd((a),(b))
const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);
const long long INF=2e18;

template<typename T,typename T1>void amax(T &a,T1 b){if(b>a)a=b;}
template<typename T,typename T1>void amin(T &a,T1 b){if(b<a)a=b;}

ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll modinv(ll a,ll m)
{
    return power(a,m-2,m);
}

// #define _NCR_

int TLE_TERROR()
{
 	ll n;
 	cin>>n;
 	ll a[n];
 	stack<ll>s;
 	for(ll i=0;i<n;i++)
 		cin>>a[i];
 	ll ans[n];
 	for(ll i=0;i<n;i++)
     		ans[i]=-1;
    // 1) Push the last element to stack.
    // 2) Pick rest of the elements one by one and follow the following steps in loop.
    // 3) Mark the current element as next.
    // 4) If stack is not empty, compare top element of stack with next.
    // 5) If next is greater than the top element,Pop element from stack. next is the next greater element for the popped element.
    // 6) Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements
    // 7) Finally, push the next in the stack.
    // 8) After the loop in step 2 is over, pop all the elements from stack and print 0 as next element for them.
 	for(ll i=n-1;i>=0;i--)
 	{
 		if(s.empty())
 		{
 			s.push(i);
 			continue;
 		}
 		while(!s.empty()&&a[s.top()]>a[i])
 		{
            ans[s.top()]=i+1;
 			s.pop();
 		}
 		s.push(i);
 	}
 	
 	for(ll i=0;i<n;i++)
    {
        if(ans[i]==-1)
            ans[i]=0;
 		cout<<ans[i]<<" ";
    }
 	return 0;   
}

int main()
{
    FAST
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll int TESTS=1;
    // cin>>TESTS;
    #ifdef _NCR_
        initialvalues();
    #endif
    while(TESTS--)
        TLE_TERROR();
    return 0;
}
