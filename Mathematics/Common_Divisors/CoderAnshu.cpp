#include<bits/stdc++.h>
using namespace std ;

const int N=1000005;

int cnt[N];

// gcd of a number n with any number m is a divisor of both n and m for sure 

/*  Here we store the count of multiples of each number which are in the array 
    Basically , we will iterate on the divisors of the a[i] and increment their count .

    If any pair of elements has gcd = g then both of them should be the multiples of g .
    We will iterate in reverse order and print the very first number whose count > 2 because that 
    must be the gcd of at least one pair in the array .

*/
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        for(int i=1;i*i<=a;++i)
        {
            if(a%i==0)
            {
                ++cnt[i];
                if(i!=a/i)
                    ++cnt[a/i];
            }
        }
    }
    for(int i=1e6;i>=1;--i)
    {
        if(cnt[i]>1)
        {
            cout<<i;break;
        }
    }
 
    return 0;
}
