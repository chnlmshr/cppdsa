// Coin Permutations

#include <bits/stdc++.h>

using namespace std;

int nCombinations(vector<int> &coins, int n, int x)
{
    vector<int> dp(x + 1, 0);
    for (int i = 1; i <= x; i++)
    {
        for (int coin : coins)
        {
            if (coin == i)
            {
                (dp[i] += 1) %= 1000000007;
            }
            else if (coin < i && dp[i - coin])
            {
                (dp[i] += dp[i - coin]) %= 1000000007;
            }
        }
    }
    return dp[x];
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../../input.txt", "r", stdin);
    //     freopen("../../output.txt", "w", stdout);
    // #endif

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto &&coin : coins)
        cin >> coin;

    cout << nCombinations(coins, n, x);

    return 0;
}