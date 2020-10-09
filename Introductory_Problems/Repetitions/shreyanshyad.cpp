#include <bits/stdc++.h>
using namespace std;

/*logic
while the previous char matches increase count
else reset
*/

int main()
{
    string s;
    cin >> s;
    int mx = 1;
    int cur = 1;
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            cur++;
            mx = max(mx, cur);
        }
        else
        {
            cur = 1;
        }
    }
    cout << mx;
}