#include <bits/stdc++.h>
using namespace std;

int maxPossible(int &n, int &m, vector<int> &a)
{
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    if (a[0])
        dp[0][a[0]] = 1;
    else
        fill(dp[0].begin(), dp[0].end(), 1);
    for (int i = 1; i < n; i++)
        if (a[i])
        {
            for (int k : {a[i] - 1, a[i], a[i] + 1})
                if (k >= 1 && k <= m)
                    (dp[i][a[i]] += dp[i - 1][k]) %= 1000000007;
        }
        else
            for (int j = 1; j <= m; j++)
                for (int k : {j - 1, j, j + 1})
                    if (k >= 1 && k <= m)
                        (dp[i][j] += dp[i - 1][k]) %= 1000000007;
    int res = 0;
    for (int i = 1; i <= m; i++)
        (res += dp[n - 1][i]) %= 1000000007;
    return res;
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

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &&i : a)
        cin >> i;

    cout << maxPossible(n, m, a);

    return 0;
}