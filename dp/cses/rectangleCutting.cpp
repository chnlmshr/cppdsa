// https://cses.fi/problemset/task/1744

#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b, vector<vector<int>> &dp)
{
    if (dp[a][b])
        return dp[a][b];
    if (a == b)
        return 0;
    if (a == 1 || b == 1)
        return a + b - 2;
    int mn = INT_MAX;
    for (int i = 1; i < a; i++)
        mn = min(mn, solve(i, b, dp) + solve(a - i, b, dp) + 1);
    for (int i = 1; i < b; i++)
        mn = min(mn, solve(a, i, dp) + solve(a, b - i, dp) + 1);
    return dp[a][b] = mn;
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

    int a, b, c = 0;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

    cout << solve(a, b, dp);

    return 0;
}