#include <bits/stdc++.h>

using namespace std;

int main() {
// #ifndef ONLINE_JUDGE
//   freopen("../input.txt", "r", stdin);
//   freopen("../output.txt", "w", stdout);
// #endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++) {
      int power; cin >> power;
      hash[power]++;
    }
    vector<int> freq;
    for(auto p : hash) {
      freq.push_back(p.second);
    }
    for(int i = 1; i <= n; i++) {
      if(i <= hash.size()) cout << hash.size() << " ";
      else cout << i << " ";
    }
    cout << "\n";
  }

  return 0;
}