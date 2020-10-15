#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> v[N];

int sub[N],ans[N];

/*  
    This is a basic subtree dp

    Suppose we have to calculate the subtree size of a node X and we have calculated the subtree sizes of 
    its descendents . 
    Then our answer would be the sum of subtree_sizes of the children of the current node X

    sub[X] = sum_over_all_children(sub[j]) + 1(node itself);

*/


void dfs(int s,int p)
{
    // include the node itself in the subtree size
    sub[s] = 1;

    for(int &j:v[s])
    {
        if(j!=p)
        {
            dfs(j,s);
            sub[s] += sub[j];   
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;++i)
    {
        int p;
        cin>>p;
        v[p].push_back(i);
    }
    dfs(1,0);

    for(int i=1;i<=n;++i)
    {
        // node itself should not be included
        cout << sub[i] -1 << " ";
    }
    cout << "\n";
}   
