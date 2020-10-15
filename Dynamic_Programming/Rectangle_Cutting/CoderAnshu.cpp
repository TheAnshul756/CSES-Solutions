#include<bits/stdc++.h>
using namespace std;

const int N = 502;

int dp[N][N];

/*  Here dp[i][j] => minimum number of moves to cut a rectangle of dimension ixj into squares
    
    We will iterate on the horizontal cut and similarly on the vertical cut and sum up the DP's of the
    two obtained rectangles and take minimum over all possible cuts.

    For example : if rectangle is 3 x 4 and we make a cut to reduce it into 1 x 4 and 2 x 4
                     then we would say dp[3][4] = min(dp[3][4],dp[1][4] + dp[2][4] + 1);
*/

int main()
{
    int a,b;
    cin>>a>>b;

    for(int i=1;i<=a;++i)
    {
        for(int j=1;j<=b;++j)
        {
            dp[i][j] = 1e9; // initial value is infinity

            if(i==j) // if it is already a square 
                dp[i][j] = 0;

            // horizontal cut
            for(int k=1;k<=i-1;++k)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);

            // vertical cut
            for(int k=1;k<=j-1;++k)
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[i][j-k] + 1);

        }
    }

    cout << dp[a][b] << "\n";
}
