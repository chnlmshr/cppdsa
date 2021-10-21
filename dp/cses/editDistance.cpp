// https://cses.fi/problemset/task/1639

#include <bits/stdc++.h>

using namespace std;

// tabulation

int solve(string &a, string &b)
{
    int na = a.length(), nb = b.length();
    int dp[na + 1][nb + 1];
    for (int i = 0; i <= na; i++)
        dp[i][0] = i;
    for (int i = 0; i <= nb; i++)
        dp[0][i] = i;
    dp[0][0] = 0;
    for (int i = 1; i <= na; i++)
        for (int j = 1; j <= nb; j++)
            dp[i][j] = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] : 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
    return dp[na][nb];
}

// memoization

// int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp)
// {
//     if (i >= 0 && j >= 0)
//     {
//         if (dp[i][j])
//             return dp[i][j];
//         if (a[i] == b[j])
//             return solve(a, b, i - 1, j - 1, dp);
//         return 1 + min(min(solve(a, b, i, j - 1, dp), solve(a, b, i - 1, j - 1, dp)), solve(a, b, i - 1, j, dp));
//     }
//     if (i >= 0)
//         return i + 1;
//     if (j >= 0)
//         return j + 1;
//     return 0;
// }

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../../input.txt", "r", stdin);
    //     freopen("../../output.txt", "w", stdout);
    // #endif

    string a, b;
    cin >> a >> b;

    cout << solve(a, b);

    return 0;
}