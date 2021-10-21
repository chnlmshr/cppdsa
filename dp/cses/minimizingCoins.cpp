// https://cses.fi/problemset/task/1634
#include <bits/stdc++.h>

using namespace std;

// vector<vector<int>> minCoinsMemo;

// int minCoins(vector<int> &coins, int n, int x)
// {
//     if (!x)
//         return 0;
//     if (x < coins[n] && !n || n < 0)
//         return 1000002;
//     if (minCoinsMemo[n][x])
//         return minCoinsMemo[n][x];
//     if (x < coins[n])
//         return minCoinsMemo[n][x] = minCoins(coins, n - 1, x);
//     return minCoinsMemo[n][x] = min(1 + minCoins(coins, n, x - coins[n]), minCoins(coins, n - 1, x));
// }

int minCoins(vector<int> &coins, int n, int x)
{
    vector<int> minCoinsMemo(x + 1, 1000001);
    minCoinsMemo[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0)
                minCoinsMemo[i] = min(minCoinsMemo[i], 1 + minCoinsMemo[i - coin]);
        }
    }
    return minCoinsMemo[x] >= 1000001 ? -1 : minCoinsMemo[x];
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../../input.txt", "r", stdin);
    //     freopen("../../output.txt", "w", stdout);
    // #endif
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto &&coin : coins)
        cin >> coin;
    // minCoinsMemo.resize(n + 1, vector<int>(1000001, 0));
    int ans = minCoins(coins, n - 1, x);
    cout << (ans >= 1000002 ? -1 : ans);
    return 0;
}