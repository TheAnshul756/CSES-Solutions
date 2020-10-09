// Problem Link - https://cses.fi/problemset/task/1734
#include<bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
// #pragma GCC optimize("-O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma") 
//*****************************************Base Template Begins**********************************************//
using namespace std;
using namespace __gnu_pbds;
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
 
#define rep(i, a, aux)       for(int  i=a;i<aux;i++)
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
//*****************************************Base Template Ends**********************************************//
int n, m, k, a[N];
/*  Solution-
    Prerequisites - Segment Tree, STL
    Solution to this problem is a bit complex, I will recommend you solve previous ones first.
    Logic Behind the solution to this problem - 
    First thing is processing queries, now we will store the queries and process them in sorted manner about the left index.
    We will also create a map in which key will be current index's element and value mapped by it will be next greater index containing the same element, if it exists otherwise it will direct to n as our implementation is 0 indexed, so n basically means just out of range index for queries.
    Now as we will process queries one by one, we are sure that always left index will either move to the left or stay the same as we had them sorted.
    Thus as soon as our query crosses a particular index, we will set next greater index contatining that element as 1 as now this element won't contribute anymore in distinct queries for our upcoming query.
    To do this we will use the value stored in the map.
    Algorithm - 
    We create map named next_greater_index, an auxiliary array named aux which contains next greater index, another array named to_create to initialize segment tree, and another vector to store queries along with its index, and array named ans to store the answers of each query in order of its arrival.
    1. We input the number of elements, number of queries, array.
    2. we iterate from right to left in the input array, we check if that element is present in map, there are 2 cases - 
        i.  If it isn't present, it means it's the rightmost element ,thus we store its next greater element in aux array as n and we update map with current index.
        ii. If it is present, then value stored in the map is given to the aux array's ith element and we update map with current index.
    3. Now we create another auxiliary array to_create, to initialize segment tree, it will contain 1 if the element is leftmost, otherwise 0, we will check it using the condiiton next_greater_element[a[i]] == i for an index i, if true set to_create[i] = 1, otherwise 0.
    4. After building segment tree, we store the queries sort them by left index and then iterate them one by one keeping an extra pointer to the leftmost index upto this query, and before beginning of each query, we bring that pointer upto its left index, if it wasn't there and keep update aux[i] as 1, as we have passed this index, so its next greater element which was previously set 0 in the segment tree should be set 1 as it will contribute now in distinct queries.
    5. We store each querie's answer in another array named answer and output it afterwards.
    I've further marked each step in the code also, you'll se something like step 1 begins, step 1 ends etc.
    End of the solution.
*/  
// standard item class to mange the queries
struct item{
    // val stored current count of number of distinct elements for a particular node of segment tree.
    int val;
    // override assignment operator and default constructor and also remember to override + operator to get merge operation sorted.
    item(){
        val = 0;
    }
    item(int ok)
    {
        val = ok;
    }
    // Overloading + operator so that we can perform merge operation in our segment tree without changing anything inside segtree class.
    // For more clarity about need to overload it you can watch out lines numbered 156, 169.
    item operator+(const item &op1)
    {
        item ret;
        ret.val = op1.val + val;
        return ret;
    }
};
//O(N) preprocessing time and O(logN) query time amortized.
// take care this implementation is 0 indexed!
// segtree st;
// st.init(n);
// st.build(v);
// ************************Basic Segment Tree Template Begins********************//
template<class itemType, class aux>
struct segtree{
    int sz;
    vector<itemType> values;
    itemType NEUTRAL_ELEMENT;
    itemType merge(itemType fi, itemType se)
    {
        return {fi.val + se.val};
    }
    
    itemType single(aux val)
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
    void build(vector<aux> &v, int x, int lx, int rx)
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
    void build(vector<aux> &v)
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
    void set(int i, aux val, int x, int lx, int rx)
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
    void set(int i, aux val)
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
        // step 1 begins.
        cin >> n;
        cin >> m;
        segtree<item, int> st;
    	vector<int> to_create(n + 1, 0);
    	map<int, int> next_greater_index;
    	rep(i, 0, n)cin >> a[i];
        // step 1 ends.
        // step 2 begins.
    	int aux[n];
    	for(int i = n - 1; i > -1; i--)
    	{
    		if(next_greater_index.find(a[i]) == next_greater_index.end())
    		{
    			aux[i] = n;
     		}
     		else
     		{
     			aux[i] = next_greater_index[a[i]];
     		}
			next_greater_index[a[i]] = i;
    	}
        // step 2 ends.
        // step 3 begins.
    	rep(i, 0, n)
    	{
    		if(next_greater_index[a[i]] == i)to_create[i] = 1;
    	}	
        // step 3 ends.
        // step 4 begins.
    	st.build(to_create);
    	vector<pair<pair<int, int>, int>> queries(m);
    	rep(i, 0, m)
    	{
    		cin >> queries[i].first.first >> queries[i].first.second;
    		queries[i].second = i;
    	}
    	sort(all(queries));
        // step 4 ends.
    	int i = 0, ans[n];
        // step 5 begins.
    	rep(j, 0, m)
    	{
    		int lidx = queries[j].first.first, ridx = queries[j].first.second;
    		lidx--;
    		while(i < lidx)
    		{
    			st.set(aux[i], 1);
    			i++;
    		}
    		ans[queries[j].second] = st.calc(lidx, ridx).val;
    	}
    	rep(j, 0, m)cout << ans[j] << endl;
        // step 5 ends.
    }
    #ifdef LOCAL
        // cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}