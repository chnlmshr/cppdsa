#include <bits/stdc++.h>

using namespace std;

int maxPages(vector<pair<int, int>> &books, int n, int x)
{
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (books[i - 1].first <= j)
                dp[i][j] = max(books[i - 1].second + dp[i - 1][j - books[i - 1].first], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][x];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> books(n); //price, pages
    for (auto &&book : books)
        cin >> book.first;
    for (auto &&book : books)
        cin >> book.second;

    cout << maxPages(books, n, x);

    return 0;
}