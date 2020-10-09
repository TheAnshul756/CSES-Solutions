// Problem Line - https://cses.fi/problemset/task/1190/
#include<bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//******************************************Template Begins*************************************************************//
#ifdef LOCAL
#define dbg(args...)       { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#else
#define dbg(args...)
#endif
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#define ll                 int
#define vi                 vector<int >
#define ordered_set        tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// -------------------Standard Traversal Moves---------------------
// vi fx = {1 ,-1 ,0, 0}, fy = {0, 0, -1, 1};
// vi fx = {2, -2, 2, -2,  1, -1, 1, -1}, fy = {1, 1, -1, -1, 2, 2, -2, -2};
// vi fx = {1, 1, 1, -1, -1 , -1, 0, 0}, fy = {1, -1, 0, 1, -1, 0, 1, -1};
// ----------------------------------------------------------------
 
#define rep(i, a, b)       for(int  i=a;i<b;i++)
#define all(a)             (a).begin(),(a).end()
#define sz(x)              (int )x.size()
#define yes                cout << "YES" << endl
#define no                 cout << "NO" << endl
#define endl               '\n' 
// const int hell = (int)998244353;
const int hell = (int)1e9 + 7;
const long long int inf = 3223372036854775807;
const double PI = 3.14159265;
const int N = (int) 1e6 + 5;
//******************************************Template Ends*************************************************************//
int n, m, k, a[N];
/*  Solution-
    Prerequisites - Segment Tree
    For each element of our segment tree which covers segment from [l, r), we will store 4 values namely-
    ans - Maximum subarray sum for the array a from [l, r).
    sum - Sum of all the elements in the subarray from [l, r).
    pref - Maximum Prefix sum for the subarray from [l, r).
    suff - Maximum Suffix sum for the subarray from [l, r).
    Since empty subarray is allowed, thus pref, ans, suff >= 0
    Now if we have single element, we can simply create it like i've done on line 69
    To perform merge operation that i've implemented on line 79 - 
    Sum of parent will simple be sum of left child and right child
    Prefix of parent will be 0 or prefix of left child or sum of left child + prefix of right child
    Suffix of parent will be 0 or Suffix of right child or sum of right child + Suffix of left child
    Ans of parent will either be 0 or answer of left child or answer of right child or suffix of left child + prefix of right child.
*/
// standard item class to mange the queries
struct item{
    long long int ans, sum, pref, suf;
    item(){
    	ans = sum = pref = suf = 0;
    }
    item(long long int ok)
    {
    	ans = max(0LL, ok);
    	sum = ok;
    	pref = max(0LL, ok);
    	suf = max(0LL, ok);
    }
    // Overloading + operator so that we can perform merge operation in our segment tree without changing anything inside segtree class.
    // For more clarity about need to overload it you can watch out lines numbered 156, 169.
    item operator+(const item &op1)
    {
        item ret;
        ret.sum = sum + op1.sum;
        ret.pref = max({
        	0LL, pref, sum + op1.pref
        });
        ret.suf = max({
        	0LL, op1.suf, op1.sum + suf
        });
        ret.ans = max({
        	ans, op1.ans, suf + op1.pref
        });
        return ret;
    }
};
//O(N) preprocessing time and O(logN) query time amortized.
// take care this implementation is 0 indexed!
// segtree st;
// st.init(n);
// st.build(v);
// ************************Basic Segment Tree Template Begins********************//
template<class itemType, class B>
struct segtree{
    int sz;
    vector<itemType> values;
    itemType NEUTRAL_ELEMENT;
    itemType merge(itemType fi, itemType se)
    {
        return {fi.val + se.val};
    }
    
    itemType single(B val)
    {
        // if(val > 0)return {val, val, val, val};
        // return {0, 0 , 0, val};
        return {val};
    }
    inline int ri(int _gg){return _gg * 2 + 2;}
    inline int le(int _gg){return _gg * 2 + 1;}
    void init(int new_size)
    {
        sz = 1;
        while(sz < new_size)sz <<= 1;
        values.resize(sz << 1);
    }
    void build(vector<B> &v, int x, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < sz(v))
            {
                values[x] = v[lx];
            }
            return ;
        }
        int mx = (lx + rx) >> 1;
        build(v, le(x), lx, mx);
        build(v, ri(x), mx, rx);
        
        values[x] = values[le(x)] + values[ri(x)];
    }
    void build(vector<B> &v)
    {
        /****************************************************************************/
        // REMEMBER TO CHANGE IT IF OUR FIRST ARGUMENT IS NOT ITEM WHICH IS RARE THO
        // initializing neutral value
        NEUTRAL_ELEMENT = item();
        /*****************************************************************************/
        int _n = v.size();
        init(_n);
        build(v, 0, 0, sz);
    }
    void set(int i, B val, int x, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            values[x] = val;
            return ;
        }
        int mx = (lx + rx) >> 1;
        if(i < mx)
        {
            set(i, val, le(x), lx, mx);
        }
        else
            set(i, val, ri(x), mx, rx);
        values[x] = values[le(x)] + values[ri(x)];
    }
    void set(int i, B val)
    {
        set(i, val, 0, 0, sz);
    }
    itemType calc(int l, int r, int x, int lx, int rx)
    {
        if(lx >= r or l >= rx)return NEUTRAL_ELEMENT;
        if(lx >= l and rx <= r)return values[x];
        int mx = (lx + rx) >> 1;
        itemType f1 = calc(l ,r ,le(x), lx, mx);
        itemType f2 = calc(l ,r ,ri(x), mx, rx);
        return f1 + f2;
    }
    itemType calc(int l, int r)
    {
        return calc(l, r, 0, 0, sz);
    }
};
// ************************Basic Segment Tree Template Ends********************//
 
 
int32_t main()
{
    /* Code for Fast I/O */
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cerr.precision(10);
    cout.precision(25);
    cout << fixed;
    #ifdef LOCAL
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int tests = 1;
    // cin >> tests;
    rep(test, 1, tests+1)
    {
        cin >> n;
        cin >> m;
        // initializing vector to initialize segment tree
        vector<int> to_create(n);
        // Creating an object of segment tree class defined above
        segtree<item, int> st;
        // reading initial values
        rep(i, 0, n)cin >> to_create[i];
        // Calling build function for segment tree
        st.build(to_create);
        // Processing the queries.
        while(m--)
        {
        	int u, v;
        	cin >> u >> v;
        	u--;
        	st.set(u, v);
        	cout << st.calc(0, n).ans << endl;
        }
    }
    #ifdef LOCAL
        // cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}