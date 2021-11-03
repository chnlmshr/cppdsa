#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a, int mx1 = INT_MIN, int mn1 = INT_MAX, int mx2 = INT_MIN, int mn2 = INT_MAX)
{
    if (n < 0)
        return abs((mx1 - mn1) - (mx2 - mn2));
    if (n == 0)
    {
        if (mn1 == INT_MAX)
        {
            return mx2 - mn2;
        }
        else if (mn2 == INT_MAX)
        {
            return mx1 - mn1;
        }
        else
        {
            return min(solve(n - 1, a, max(mx1, a[n]), min(mn1, a[n]), mx2, mn2), solve(n - 1, a, mx1, mn1, max(mx2, a[n]), min(mn2, a[n])));
        }
    }
    else
    {
        return min(solve(n - 1, a, max(mx1, a[n]), min(mn1, a[n]), mx2, mn2), solve(n - 1, a, mx1, mn1, max(mx2, a[n]), min(mn2, a[n])));
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a)
            cin >> i;
        cout << solve(n - 1, a) << "\n";
    }

    return 0;
}