#include <bits/stdc++.h>
using namespace std;

/*logic
add all to set anc counts it's size
*/

int main()
{
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        st.insert(t);
    }
    cout << st.size();
}