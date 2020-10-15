#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;

template<typename T>
using ordered_set = tree<T , null_type ,less<T> ,rb_tree_tag ,tree_order_statistics_node_update>;
ordered_set<pair<int,int>> s;

const int N=200005;

int salary[N],n,q;

/*  This is a very basic use of policy based data structures.
    For more details you can refer here : 
        https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/
*/
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        cin>>salary[i];
        s.insert({salary[i],i});
    }
    while(q--)
    {
        char cc;
        int a,b;
        cin>>cc>>a>>b;
        if(cc=='?')
        {
            cout<<s.order_of_key({b+1,0})-s.order_of_key({a,0})<<'\n';
        }
        else
        {
            s.erase({salary[a],a});
            salary[a]=b;
            s.insert({salary[a],a});
        }
    }

    return 0;
}
