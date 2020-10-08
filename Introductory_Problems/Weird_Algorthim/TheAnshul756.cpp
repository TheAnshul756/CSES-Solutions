#include<bits/stdc++.h>
using namespace std;
#define N  100005

int main()
{
	long long n;
	cin >> n;
	cout << n << " ";
	while(n != 1) {
		if(n&1) {
			// n is odd n:= 3 * n + 1
			n = 3 * n + 1;
		} else {
			// n is even n:= n / 2
			n/=2;
		}
		cout << n << " ";
	}
	cout << endl;
	return 0;
}