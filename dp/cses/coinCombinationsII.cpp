// Coin Permutations

#include <bits/stdc++.h>

using namespace std;

int nCombinations(vector<int> &coins, int n, int x)
{
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (coins[i - 1] <= j)
            {
                (dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]]) %= 1000000007;
            }
            else
            {
                (dp[i][j] = dp[i - 1][j]) %= 1000000007;
            }
        }
    }
    return dp[n][x];
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