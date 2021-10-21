// https://cses.fi/problemset/task/1637

#include <bits/stdc++.h>

using namespace std;

int subtractDigit(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = i, mn = INT_MAX;
        while (t)
        {
            int r = t % 10;
            if (r)
                mn = min(mn, 1 + dp[i - r]);
            t /= 10;
        }
        dp[i] = mn;
    }
    return dp[n];
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../../input.txt", "r", stdin);
    //     freopen("../../output.txt", "w", stdout);
    // #endif

    int n;
    cin >> n;

    cout << subtractDigit(n);

    return 0;
}