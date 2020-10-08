#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,xr=0,sm=0,tmp;
	cin>>n;
	//algo1
	// for(int i=0;i<n-1;i++)
	// {
	// 	cin>>tmp;
	// 	sm+=tmp; //given all numbers except n,take sum of all the remaining numbers concept.easy but care overflow
	// }
	//algo 2
	for(int i=0;i<n-1;i++)
	{
		cin>>tmp;
		xr^=tmp;
	}
	for(int i=0;i<n;i++)
	{
		xr^=i+1;
	}
	//this algo relies on that fact A^A=0
	//in first loop,we xor all the elements except the missing one,
	//in second loop,we xor all from 1...n , you can figure out the rest.
	cout<<xr;

}