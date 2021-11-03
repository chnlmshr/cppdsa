#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &nums, int mn, vector<vector<int>> &dp) {
    if(n < 0) return 0;
    if(dp[n][mn]) return dp[n][mn];
    if(nums[n] < nums[mn]) return dp[n][mn] = max(solve(n-1, nums, mn, dp), 1 + solve(n-1, nums, n, dp));
    else return dp[n][mn] = solve(n-1, nums, mn, dp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int mx = INT_MIN, mxi;
    vector<int> nums(n); for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(mx <= nums[i]) {
            mx = nums[i];
            mxi = i;
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    cout << solve(n-1, nums, mxi, dp);
}
