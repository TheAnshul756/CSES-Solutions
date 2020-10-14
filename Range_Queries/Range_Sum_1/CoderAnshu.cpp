#include<iostream>

using namespace std;

const int N = 200005;

long long prefix_sum[N];
int a[N];

int main()
{
    int n,Q;
    scanf("%d %d",&n,&Q);

    for(int i=1;i<=n;++i)
        scanf("%d",a+i);

    // for answering range_sums we can just maintain the prefix_sums and then the answer for range (l,r)
    // would pe prefix_sum[r] - prefix_sum[l];

    for(int i=1;i<=n;++i)
        prefix_sum[i] = prefix_sum[i-1] + a[i];

    while(Q--)
    {
        int l,r;
        scanf("%d %d",&l,&r);

        printf("%lld\n",prefix_sum[r] - prefix_sum[l-1]);
    }
}