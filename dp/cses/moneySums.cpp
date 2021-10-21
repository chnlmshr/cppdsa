// https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>

using namespace std;

void solve(int n, vector<int> &coins, set<int> &res, int sm, vector<vector<bool>> &dp)
{
    if (n < 0)
    {
        if (sm)
            res.emplace(sm);
        return;
    }
    if (dp[n][sm])
        return;
    solve(n - 1, coins, res, sm + coins[n], dp);
    solve(n - 1, coins, res, sm, dp);
    dp[n][sm] = true;
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

    int n;
    cin >> n;
    vector<int> coins(n);
    for (auto &i : coins)
        cin >> i;

    vector<vector<bool>> dp(n, vector<bool>(100001, false));
    set<int> res;
    solve(n - 1, coins, res, 0, dp);

    cout << res.size() << "\n";

    for (int i : res)
        cout << i << " ";

    return 0;
}