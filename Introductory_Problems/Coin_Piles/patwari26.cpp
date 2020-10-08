#include <iostream>
using namespace std;

int main()
{
    long long int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        // we have to remove 3 coins in every step so (a+b)%3 should be zero
        // the pile with more coins should not contain greater coins than double of first pile
        // else it can never be removed
        cout << ((a + b) % 3 == 0 && (min(a, b) * 2 >= max(a, b)) ? "YES" : "NO") << endl;
    }
}