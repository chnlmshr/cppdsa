#include <bits/stdc++.h>

using namespace std;

int distribute(int x, int y, map<pair<int, int>, int> &dp) {
  if(x == y) return 1;
  if(dp[{x,y}]) return dp[{x,y}];
  if(dp[{y,x}]) return dp[{y,x}];
  return dp[{x,y}] = 1 + distribute(abs(x-y), min(x,y), dp);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int mxh, mnh, mxw, mnw; 
  cin >> mnh >> mxh >> mnw >> mxw;
  
  vector<pair<int, int>> chocs;
  for(int i = mnh; i <= mxh; i++) {
    for(int j = mnw; j <= mxw; j++) {
      chocs.push_back({i, j});
    }
  }
  int n = chocs.size(), res = 0;
  map<pair<int, int>, int> dp;
  for(auto choc : chocs) {
    res += distribute(choc.first, choc.second, dp);
  }
  cout << res;

  return 0;
}