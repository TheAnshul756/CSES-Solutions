#include<bits/stdc++.h>
using namespace std ;



// segment tree template

/*  Segment Tree is a data structure that supports point updates and range updates along with 
    a large number of range queries
    To learn in detail refer to : https://cp-algorithms.com/data_structures/segment_tree.html
*/

const int N=200005;
struct node
{
    int sum;
}fake={int(2e9)};

struct SEGTREE
{
    int a[N];
    SEGTREE(){ }
    node tree[4*N];

    // combine two child nodes to a new node 
    inline node combine(node a,node b)
    {
        node ret;
        ret.sum=min(a.sum,b.sum);
        return ret;
    }

    // make a new node
    inline node make_node(int val)
    {
        node ret;
        ret.sum=val;
        return ret;
    }

    // build the segTree Bottom - Up 
    void buildTree(int v,int st,int en)
    {
        if(st==en)
        {
            tree[v]=make_node(a[st]);
            return ;
        }
        int mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }

    // Point - Update
    void update(int v,int st,int en,int in,int val)
    {
        int mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(val);
            a[st]=val;
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val);
        else
            update(v<<1 | 1,mid+1,en,in,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }

    // Range Query 
    node query(int v,int st,int en,int l,int r)
    {
        if(en<l || st>r)
            return fake;
        if(st>=l && en<=r)
            return tree[v];
        int mid=(st+en)>>1;
        return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
    }
}seg;

 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,q;
    cin>>n>>q;

    // initialize the segment tree with initial values of the array
    for(int i=0;i<n;++i)
        cin>>seg.a[i];

    // build the segTree
    seg.buildTree(1,0,n-1);

    while(q--)
    {
        int a,b;
        cin>>a>>b;
            
        cout<<seg.query(1,0,n-1,a-1,b-1).sum<<'\n';
    }

    return 0;
}
