#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n, num; cin >> n;
  map<int, int> hash;
  
  for(int i = 0; i < n; i++) {
    cin >> num;
    hash[num]++;
  }
  
  cout << hash.size();
  
  return 0;
}