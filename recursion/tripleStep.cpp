#include <bits/stdc++.h>

using namespace std;

int possibleWays(int n, unordered_map<int, int> &hash) {
  if(hash[n]) return hash[n];
  if(n <= 0) return n == 0;
  return hash[n] = possibleWays(n-1, hash) + possibleWays(n-2, hash) + possibleWays(n-3, hash);
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
  
  unordered_map<int, int> hash;
  cout << possibleWays(n, hash);

  return 0;
}