#include <bits/stdc++.h>
using namespace std;

int solve(int sm, int n, vector<vector<int>> &dp) {
    dp[0][0] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= sm; j++) {
            if(i <= j) dp[i][j] += (dp[i-1][j] + dp[i-1][j-i]) % 1000000007;
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n-1][sm];
}

int main()
{
    int n, sm;
    cin >> n;
    sm = n * (n + 1) / 2;
    if (sm % 2) cout << 0;
    else {
        sm /= 2;
        vector<vector<int>> dp(n, vector<int>(sm + 1, 0));
        cout << solve(sm, n, dp);
    }
}
