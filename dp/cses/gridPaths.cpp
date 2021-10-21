// https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>

using namespace std;

int nPaths(int n, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        if (grid[0][i])
            dp[0][i] = 1;
        else
            break;

    for (int i = 0; i < n; i++)
        if (grid[i][0])
            dp[i][0] = 1;
        else
            break;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (grid[i][j])
                (dp[i][j] = dp[i - 1][j] + dp[i][j - 1]) %= 1000000007;

    return dp[n - 1][n - 1];
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../../input.txt", "r", stdin);
    //     freopen("../../output.txt", "w", stdout);
    // #endif

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '.')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }

    cout << nPaths(n, grid);

    return 0;
}