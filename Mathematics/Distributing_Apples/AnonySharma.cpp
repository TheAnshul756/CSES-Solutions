#include <bits/stdc++.h>
using namespace std;
 
//DEFINE and TYPEDEF--------------------------------------------------------------
#define SPEEDUP ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define st first
#define nd second

typedef long long int lld;
#define mod 1000000007
//--------------------------------------------------------------------------------

lld power(lld b, lld e, lld m) // This calculates (b^e)%m
{
	assert(e>=0);
	if(e==0) return 1;
	if(e%2==1) return b*power(((b%m)*(b%m))%m,(e-1)/2,m)%m;
	else return power(((b%m)*(b%m))%m,e/2,m)%m;
}

lld modInv(lld x, lld m) 
{
	// This calculates modular multiplicative inverse. 
	// For reference, check method 3 on https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
	return power(x,m-2,m);
}

lld fact[2000007];
lld nCr(lld n, lld r)
{
	fact[0]=1;

	for(lld i=1;i<=n;i++)
		fact[i]=i*fact[i-1]%mod;

	return (((fact[n]*modInv(fact[r],mod))%mod)*modInv(fact[n-r],mod))%mod; // This just calculates (n!)/((n-r)!*r!) % mod
}

int main()
{
    SPEEDUP;
	lld a,b;
	cin>>a>>b;

	// This is solved using the circles and lines method we used in Permutation and combination,
	// Let's consider a case of distributing 2 apples to 3 students
	// 0|0| -> 1st gets 1 apple, 2nd gets 1 apple, and 3rd gets 0 apple
	// 00|| -> 1st gets 2 apples, 2nd gets 0 apple, and 3rd gets 0 apple

	// Its pretty clear that, The total possibilities is all the possible arrangements of these circles and lines
	// So, Total arrangements = fact(Number of zeros+Numbers of lines)/(fact(Number of zeros)*fact(Numbers of lines))
	// Number of circles = number of apples, and Number of lines = Number of students - 1
	// And, it is same as nCr(a+b-1,a-1);

	// And for calculating nCr mod m, I used Fermat Little Theorem. 
	// For reference: https://www.geeksforgeeks.org/compute-ncr-p-set-3-using-fermat-little-theorem/
	cout<<nCr(a+b-1,a-1)<<endl;
	return 0;
}
