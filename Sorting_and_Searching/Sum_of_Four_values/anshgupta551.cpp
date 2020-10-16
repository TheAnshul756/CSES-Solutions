// #include <bits/stdc++.h>
// using namespace std;

// // The following structure is needed
// // to store pair sums in aux[]
// class pairSum {
// public:
// 	// index (ll A[]) of first element in pair
// 	ll first;

// 	// index of second element in pair
// 	ll sec;

// 	// sum of the pair
// 	ll sum;
// };

// // Following function is needed
// // for library function qsort()
// ll compare(const void* a, const void* b)
// {
// 	return ((*(pairSum*)a).sum - (*(pairSum*)b).sum);
// }

// // Function to check if two given pairs
// // have any common element or not
// bool noCommon(pairSum a, pairSum b)
// {
// 	if (a.first == b.first || a.first == b.sec
// 		|| a.sec == b.first || a.sec == b.sec)
// 		return false;
// 	return true;
// }

// // The function finds four
// // elements with given sum X
// void findFourElements(ll arr[], ll n, ll X)
// {
// 	ll i, j;

// 	// Create an auxiliary array
// 	// to store all pair sums
// 	ll size = (n * (n - 1)) / 2;
// 	pairSum aux[size];

// 	// Generate all possible pairs
// 	// from A[] and store sums
// 	// of all possible pairs in aux[]
// 	ll k = 0;
// 	for (i = 0; i < n - 1; i++) {
// 		for (j = i + 1; j < n; j++) {
// 			aux[k].sum = arr[i] + arr[j];
// 			aux[k].first = i;
// 			aux[k].sec = j;
// 			k++;
// 		}
// 	}

// 	// Sort the aux[] array using
// 	// library function for sorting
// 	qsort(aux, size, sizeof(aux[0]), compare);

// 	// Now start two index variables
// 	// from two corners of array
// 	// and move them toward each other.
// 	i = 0;
// 	j = size - 1;
// 	while (i < size && j >= 0) {
// 		if ((aux[i].sum + aux[j].sum == X)
// 			&& noCommon(aux[i], aux[j])) {
// 			cout << arr[aux[i].first] << ", "
// 				<< arr[aux[i].sec] << ", "
// 				<< arr[aux[j].first] << ", "
// 				<< arr[aux[j].sec] << endl;
// 			return;
// 		}
// 		else if (aux[i].sum + aux[j].sum < X)
// 			i++;
// 		else
// 			j--;
// 	}
// }

// // Driver code
// ll main()
// {
// 	ll arr[] = { 10, 20, 30, 40, 1, 2 };
// 	ll n = sizeof(arr) / sizeof(arr[0]);
// 	ll X = 91;

// 	// Function Call
// 	findFourElements(arr, n, X);
// 	return 0;
// }

// // This is code is contributed by rathbhupendra


#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back
#define in(x) ll x; cin>>x;
#define ln(x) long long x; cin>>x;
#define memf(a) memset(a,false,sizeof(a))
#define F first
#define S second
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
/*Function to check if two given pairs
 have any common element or not*/
bool noCommon(pair<ll,ll> A, pair<ll,ll> B)
{
	if(A.F==B.F || A.F==B.S || A.S==B.F || A.S==B.S)
		return false;
	else
		return true;
}
int main()
{
	fast
	ll n,x;
	cin>>n>>x;
	ll a[n];
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll k=n*(n-1)/2;
	pair<ll,pair<ll,ll>> p[k];
	ll y=0;
	 /*Generate all possible pairs from a[] and store sums of all possible pairs in p along with indexes*/
	for(ll i=0;i<n;i++)
	{
		for(ll j=i+1;j<n;j++)
		{
			p[y]={a[i]+a[j],{i,j}};
			y++;
		}
	}
	sort(p,p+k);
	 /* Now start two index variables from two corners of array and move them toward each other.*/
	ll l=0,r=k-1;
	while(l<=r)
	{
		ll sum=p[l].F+p[r].F;
		if(sum==x && noCommon(p[l].S,p[r].S))
		{
			cout<<p[l].S.F+1<<" "<<p[l].S.S+1<<" "<<p[r].S.F+1<<" "<<p[r].S.S+1<<endl;
			return 0;
		}
		else if(sum<x)
		{
			l++;
		}
		else
			r--;
	}
	cout<<"IMPOSSIBLE";
	return 0;
}
