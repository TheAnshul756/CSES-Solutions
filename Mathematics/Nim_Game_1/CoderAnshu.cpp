#include<bits/stdc++.h>
using namespace std ;

/*  This is a pretty standard game => Nim
    If the Xor of All The values is 0, only then it is a losing state else if the Xor of All The Numbers 
    is non-zero then it is a winning state .
    For complete proofs and theory ,
        Refer : https://cp-algorithms.com/game_theory/sprague-grundy-nim.html

*/
 
int main()
{
    int n,TESTS;
    cin >> TESTS;
    while(TESTS --)
    {
        int Xor = 0;
        cin>>n;
        while(n--)
        {
            int a;
            cin>>a;
            Xor^=a;
        }
        cout<<(Xor?"first\n":"second\n");
    }
    return 0;
}