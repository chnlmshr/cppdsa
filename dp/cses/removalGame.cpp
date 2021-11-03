#include<bits/stdc++.h>
#define ll long long int
using namespace std;

/*int solve(int i, int j, vector<int> &scores, int sm) {
    if(j - i == 1) return max(scores[i], scores[j]);
    return max(sm-solve(i+1, j, scores, sm-scores[i]), sm-solve(i, j-1, scores, sm-scores[j]));
}*/


ll solve(int n, vector<int> &scores) {
    ll dp[n][n];
    for(int i = n-1; i >= 0; i--) 
        for(int j = i; j < n; j++) 
            if(i == j) dp[i][j] = scores[i];
            else if(i + 1 == j) dp[i][j] = max(scores[i], scores[j]);
            else dp[i][j] = max(scores[i] + min(dp[i+2][j], dp[i+1][j-1]), scores[j] + min(dp[i+1][j-1], dp[i][j-2]));
    return dp[0][n-1];
}

int main() {
	int n; cin >> n;
	vector<int> scores(n); for(auto &score : scores) cin >> score;
	cout << solve(n, scores);
}
