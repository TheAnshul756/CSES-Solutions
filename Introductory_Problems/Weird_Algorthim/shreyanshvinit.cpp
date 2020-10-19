#include <iostream>

using namespace std;

int main()
{
    long long a;
    cin>>a;
    cout<<a<<" ";
    while(a!=1){
        a%2==0 ? a = a/2 : a = a*3 + 1;
        cout<<a<<" ";
    }
}
