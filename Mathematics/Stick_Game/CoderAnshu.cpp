#include<bits/stdc++.h>
using namespace std ;

const int N = 1e6+5;

// Basic dynamic programming problem
bool dp[N];
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    

    int n,k;
    cin>>n>>k;
    string ans;
    vector<int> v(k);  // possible moves
    for(int i=0;i<k;++i)
        cin>>v[i];

    /* 0 denotes the losing position and 1 denotes the winning position */

    dp[0] = false ; // because if no sticks are remaining and its ur move then u are sure to lose

    for(int i=1;i<=n;++i)
    {
        dp[i] = false; // Setting the current position to be losing position

        /*
            This question is based on basics of game theory .
            Now dp[i] is winning state if and only if you can convert it into any of the possible
            losing states by performing a valid move . And if you convert the game into a losing state
            for the opponent then you are sure to win by playing optimally.

            Losing state here means a state where you can never win and irrespective of your moves your 
            opponent can always win by a definite strategy.

            Winning state here means that if by performing any valid move you make your opponent enter into 
            a losing state then you are sure to win.

            A state is losing if by performing any valid move you always end up in a winning state therby
            losing tha game.

            And a state is winning if u have any of the reachable losing states forcing your opponent to that
            state by performing the corresponding move.
        */

        for(int j=0;j<k;++j)
        {
            // iterating over all valid moves 
            if((i-v[j])>=0)
            {
                // move is valid
                if(!dp[i-v[j]])
                {
                    // the state after this move is losing and therefore u can force ur oppenent to 
                    // that losing state
                    dp[i] = true;
                }
            }
        }
        ans += dp[i]?"W":"L";
    }

    cout<<ans<<"\n";
    return 0;
}