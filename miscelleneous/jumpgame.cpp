#include <bits/stdc++.h>

using namespace std;

void climbStairsVarJumps(int n, vector<int> jump) {
	vector<int> dp(n+1,0);
	dp[n]=1;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=1;j<=jump[i] && (i+j)<=n;j++)
		{
			dp[i]+=dp[i+j];
		}

	}
	cout<<dp[0];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n; cin >> n;
  vector<int> jumps(n);
  for(auto &jump : jumps) cin >> jump;
  climbStairsVarJumps(n, jumps);

  return 0;
}