#include <bits/stdc++.h>
#define int long long
using namespace std;

bool available(int from, int &to, unordered_map<int, bool> &schedule)
{
    while (from != to)
        if (schedule[from++])
            return false;
    if (schedule[from])
        return false;
    else
        return true;
}

unordered_map<int, bool> allocate(int from, int &to, unordered_map<int, bool> schedule)
{
    while (from != to)
        schedule[from++] = true;
    schedule[from] = true;
    return schedule;
}

int solve(vector<vector<int>> &v, int n, unordered_map<int, bool> schedule)
{
    if (n < 0)
        return 0;
    if (available(v[n][0], v[n][1], schedule))
        return max(v[n][2] + solve(v, n - 1, allocate(v[n][0], v[n][1], schedule)), solve(v, n - 1, schedule));
    else
        return solve(v, n - 1, schedule);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> v[i][j];

    unordered_map<int, bool> schedule;

    cout << solve(v, n - 1, schedule);

    return 0;
}