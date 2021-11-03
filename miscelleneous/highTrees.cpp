#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &heights, int i, int j, int &mni, int &mnj, vector<vector<bool>> &dp)
{
    if (dp[i][j])
        return;
    dp[i][j] = true;
    if (i + 1 == j)
    {
        if (heights[i] <= heights[j])
        {
            if (j - i > mnj - mni)
            {
                mnj = j;
                mni = i;
            }
        }
    }
    else
    {
        if (heights[i] <= heights[j])
        {
            if (j - i > mnj - mni)
            {
                mnj = j;
                mni = i;
            }
        }
        solve(heights, i, j - 1, mni, mnj, dp);
        solve(heights, i + 1, j, mni, mnj, dp);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> heights(n);
    for (auto &height : heights)
        cin >> height;

    int mni, mnj;
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    solve(heights, 0, n - 1, mni, mnj, dp);
    cout << mni << " " << mnj << "\n";
    return 0;
}