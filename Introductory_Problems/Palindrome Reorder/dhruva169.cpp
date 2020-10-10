#include<bits/stdc++.h> 
using namespace std;

#pragma GCC optimize ("-O2")
#define testcase(t) int t;cin>>t;while(t--)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define what_is(x)  cerr << #x << " is " << x << endl;
#define int long long

const int N = 1e5 + 5, MOD = 1e9 + 7;

int32_t main(){
    
    IOS;

    int cnt=0;
    bool chk[26];
    string s, ans=""; cin >> s;
    for (auto c : s){
        if (!chk[c - 'A']){
            chk[c - 'A'] = true;
            cnt++;
        }
        else{
            ans += c;
            chk[c - 'A'] = false;
            cnt--;
        }
    }
    if (cnt >= 2){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    cout << ans;
    for (char c = 'A'; c <= 'Z'; c++){
        if (chk[c - 'A']){
            cout << c;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}
 
/*

*/
